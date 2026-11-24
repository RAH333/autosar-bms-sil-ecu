#include "Rte_BmsMonitor.h"
#include "../bsw/Dem.h"
#include "../bsw/CanIf.h"

static Voltage_mV_t Rte_Buffer_CellVoltage = 3700U;
static Temp_DegC_t  Rte_Buffer_PackTemp    = 25;
static BmsState_t   Rte_Buffer_BmsStatus   = BMS_STATE_NORMAL;

Std_ReturnType Rte_Read_RpCellVoltage_Value(Voltage_mV_t* data) {
    if (data == NULL) {
        return E_NOT_OK;
    }
    *data = Rte_Buffer_CellVoltage;
    return E_OK;
}

Std_ReturnType Rte_Read_RpPackTemp_Value(Temp_DegC_t* data) {
    if (data == NULL) {
        return E_NOT_OK;
    }
    *data = Rte_Buffer_PackTemp;
    return E_OK;
}

Std_ReturnType Rte_Write_PpBmsStatus_State(BmsState_t data) {
    Rte_Buffer_BmsStatus = data;
    /* Transmit status frame over simulated CAN Interface (PDU ID 0x101) */
    uint8_t canPayload[4];
    canPayload[0] = data;
    canPayload[1] = (uint8_t)(Rte_Buffer_CellVoltage >> 8U);
    canPayload[2] = (uint8_t)(Rte_Buffer_CellVoltage & 0xFFU);
    canPayload[3] = (uint8_t)Rte_Buffer_PackTemp;
    return CanIf_Transmit(0x101U, canPayload, 4U);
}

Std_ReturnType Rte_Call_DiagnosticMonitor_SetEventStatus(uint16_t EventId, Dem_EventStatusType EventStatus) {
    return Dem_SetEventStatus(EventId, EventStatus);
}

void Rte_Sim_SetCellVoltage(Voltage_mV_t voltage) {
    Rte_Buffer_CellVoltage = voltage;
}

void Rte_Sim_SetPackTemp(Temp_DegC_t temp) {
    Rte_Buffer_PackTemp = temp;
}

BmsState_t Rte_Sim_GetBmsStatus(void) {
    return Rte_Buffer_BmsStatus;
}
