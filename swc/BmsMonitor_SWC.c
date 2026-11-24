#include "BmsMonitor_SWC.h"
#include "../bsw/Dem.h"

void BmsMonitor_Init(void) {
    Dem_ClearAllDTCs();
    (void)Rte_Write_PpBmsStatus_State(BMS_STATE_NORMAL);
}

void BmsMonitor_MainFunction_10ms(void) {
    Voltage_mV_t currentVoltage = 0U;
    Temp_DegC_t  currentTemp    = 0;
    BmsState_t   nextState      = BMS_STATE_NORMAL;

    if ((Rte_Read_RpCellVoltage_Value(&currentVoltage) == E_OK) &&
        (Rte_Read_RpPackTemp_Value(&currentTemp) == E_OK)) {

        /* Evaluate Over-Temperature Fault (Highest Priority) */
        if (currentTemp > BMS_MAX_PACK_TEMP_DEGC) {
            nextState = BMS_STATE_OVERTEMP;
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_PACK_OVERTEMP, DEM_EVENT_STATUS_FAILED);
        } else {
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_PACK_OVERTEMP, DEM_EVENT_STATUS_PASSED);
        }

        /* Evaluate Cell Voltage Faults */
        if (currentVoltage > BMS_MAX_CELL_VOLTAGE_MV) {
            if (nextState == BMS_STATE_NORMAL) {
                nextState = BMS_STATE_OVERVOLTAGE;
            }
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_CELL_OVERVOLTAGE, DEM_EVENT_STATUS_FAILED);
        } else {
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_CELL_OVERVOLTAGE, DEM_EVENT_STATUS_PASSED);
        }

        if (currentVoltage < BMS_MIN_CELL_VOLTAGE_MV) {
            if (nextState == BMS_STATE_NORMAL) {
                nextState = BMS_STATE_UNDERVOLTAGE;
            }
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_CELL_UNDERVOLTAGE, DEM_EVENT_STATUS_FAILED);
        } else {
            (void)Rte_Call_DiagnosticMonitor_SetEventStatus(DEM_EVENT_CELL_UNDERVOLTAGE, DEM_EVENT_STATUS_PASSED);
        }

        /* Publish ECU State to RTE & CAN Bus */
        (void)Rte_Write_PpBmsStatus_State(nextState);
    }
}
