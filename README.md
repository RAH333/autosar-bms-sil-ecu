# autosar-bms-sil-ecu
AUTOSAR-compliant Battery Management System (BMS) Software Component (SWC) in Embedded C with RTE/BSW simulation, UDS diagnostics, CMake build system, Python SIL test automation, and GitHub Actions CI/CD.

# AUTOSAR BMS Cell Monitoring & UDS Diagnostic ECU (SIL Environment)

An **AUTOSAR-compliant Battery Management System (BMS)** Application Software Component (`BmsMonitor_SWC`) written in **MISRA-compliant Embedded C**, complete with a simulated **Runtime Environment (RTE)**, **Basic Software (BSW)** modules (`CanIf`, `Dem`), **CMake** build configuration, **Python Software-in-the-Loop (SIL)** test automation, and **GitHub Actions CI/CD**.

## Architecture Overview
* **Application Layer (`swc/`):** Implements a 10ms cyclic runnable (`BmsMonitor_MainFunction_10ms`) that monitors cell voltage and pack temperature thresholds and manages state transitions.
* **RTE Layer (`rte/`):** Decouples the application from BSW using standard `Rte_Read`, `Rte_Write`, and `Rte_Call` APIs.
* **BSW Layer (`bsw/`):** Simulates CAN message transmission (`CanIf_Transmit`) and Diagnostic Event Manager (`Dem_SetEventStatus`) DTC logging.
* **SIL Verification (`sil_tests/`):** Python test runner that injects fault vectors into the compiled ECU binary and validates CAN/DTC responses.

## Build & Run SIL Tests Locally
```bash
cmake -B build -S .
cmake --build build
python3 sil_tests/test_bms_sil.py
```


```
autosar-bms-sil-ecu/
├── .github/
│   └── workflows/
│       └── sil_ci_pipeline.yml
├── bsw/
│   ├── CanIf.c
│   ├── CanIf.h
│   ├── Dem.c
│   └── Dem.h
├── rte/
│   ├── Rte_BmsMonitor.c
│   ├── Rte_BmsMonitor.h
│   └── Rte_Type.h
├── swc/
│   ├── BmsMonitor_SWC.c
│   └── BmsMonitor_SWC.h
├── sil_tests/
│   ├── sil_harness.c
│   └── test_bms_sil.py
├── CMakeLists.txt
└── README.md
```
