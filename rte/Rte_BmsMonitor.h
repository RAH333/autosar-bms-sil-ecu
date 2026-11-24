#ifndef RTE_BMS_MONITOR_H
#define RTE_BMS_MONITOR_H

#include "Rte_Type.h"

/* RTE Sender-Receiver Read Interfaces */
Std_ReturnType Rte_Read_RpCellVoltage_Value(Voltage_mV_t* data);
Std_ReturnType Rte_Read_RpPackTemp_Value(Temp_DegC_t* data);

/* RTE Sender-Receiver Write Interfaces */
Std_ReturnType Rte_Write_PpBmsStatus_State(BmsState_t data);

/* RTE Client-Server Diagnostic Interface */
Std_ReturnType Rte_Call_DiagnosticMonitor_SetEventStatus(uint16_t EventId, Dem_EventStatusType EventStatus);

/* Helper functions for SIL Environment Injection */
void Rte_Sim_SetCellVoltage(Voltage_mV_t voltage);
void Rte_Sim_SetPackTemp(Temp_DegC_t temp);
BmsState_t Rte_Sim_GetBmsStatus(void);

#endif /* RTE_BMS_MONITOR_H */
