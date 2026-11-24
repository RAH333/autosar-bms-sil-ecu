import subprocess
import sys
import os

EXECUTABLE = os.path.join("build", "bms_sil_ecu")
if os.name == "nt":
    EXECUTABLE += ".exe"

TEST_CASES = [
    # (Name, Voltage_mV, Temp_C, Expected_State, Expected_OV, Expected_UV, Expected_OT)
    ("Nominal Operation",     3700, 30, 0, 0, 0, 0),
    ("Cell Over-Voltage",     4350, 32, 1, 1, 0, 0),
    ("Cell Under-Voltage",    2600, 28, 2, 0, 1, 0),
    ("Pack Over-Temperature", 3800, 68, 3, 0, 0, 1),
    ("Boundary Max Normal",   4200, 60, 0, 0, 0, 0),
]

def run_sil_test(voltage: int, temp: int) -> dict:
    result = subprocess.run(
        [EXECUTABLE, str(voltage), str(temp)],
        capture_output=True,
        text=True,
        check=True
    )
    for line in result.stdout.splitlines():
        if line.startswith("SIL_RESULT|"):
            parts = line.split("|")[1:]
            return {p.split(":")[0]: int(p.split(":")[1]) for p in parts}
    raise RuntimeError("No SIL_RESULT output found from ECU binary.")

def main():
    print("=== Running AUTOSAR BMS Software-in-the-Loop (SIL) Test Suite ===")
    passed = 0

    for name, v, t, exp_state, exp_ov, exp_uv, exp_ot in TEST_CASES:
        res = run_sil_test(v, t)
        ok = (
            res["STATE"] == exp_state and
            res["DTC_OV"] == exp_ov and
            res["DTC_UV"] == exp_uv and
            res["DTC_OT"] == exp_ot
        )
        status_str = "PASS" if ok else "FAIL"
        print(f"[{status_str}] {name} (V={v}mV, T={t}C) -> Got: {res}")
        if ok:
            passed += 1

    print(f"\nSummary: {passed}/{len(TEST_CASES)} SIL Test Cases Passed.")
    sys.exit(0 if passed == len(TEST_CASES) else 1)

if __name__ == "__main__":
    main()
  
