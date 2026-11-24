#ifndef BMS_MONITOR_SWC_H
#define BMS_MONITOR_SWC_H

#include "../rte/Rte_BmsMonitor.h"

/* Calibration Parameters (MISRA-C Compliant Constants) */
#define BMS_MAX_CELL_VOLTAGE_MV   ((Voltage_mV_t)4200U)
#define BMS_MIN_CELL_VOLTAGE_MV   ((Voltage_mV_t)2800U)
#define BMS_MAX_PACK_TEMP_DEGC    ((Temp_DegC_t)60)

/* AUTOSAR Runnable Entities */
void BmsMonitor_Init(void);
void BmsMonitor_MainFunction_10ms(void);

#endif /* BMS_MONITOR_SWC_H */
