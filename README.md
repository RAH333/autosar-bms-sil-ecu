# autosar-bms-sil-ecu
AUTOSAR-compliant Battery Management System (BMS) Software Component (SWC) in Embedded C with RTE/BSW simulation, UDS diagnostics, CMake build system, Python SIL test automation, and GitHub Actions CI/CD.

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
