#include "CanIf.h"
#include <stdio.h>

static uint8_t lastTransmittedState = 0xFFU;

Std_ReturnType CanIf_Transmit(uint16_t CanTxPduId, const uint8_t* PduDataPtr, uint8_t Length) {
    if ((PduDataPtr == NULL) || (Length == 0U)) {
        return E_NOT_OK;
    }
    lastTransmittedState = PduDataPtr[0];
    printf("[CAN-TX] ID: 0x%03X | DLC: %u | Data: %02X %02X %02X %02X\n",
           CanTxPduId, Length, PduDataPtr[0], PduDataPtr[1], PduDataPtr[2], PduDataPtr[3]);
    return E_OK;
}

uint8_t CanIf_Sim_GetLastTxState(void) {
    return lastTransmittedState;
}
