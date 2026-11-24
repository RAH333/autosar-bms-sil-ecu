#include "Dem.h"

#define MAX_DEM_EVENTS 10U
static Dem_EventStatusType Dem_EventMemory[MAX_DEM_EVENTS];

Std_ReturnType Dem_SetEventStatus(uint16_t EventId, Dem_EventStatusType EventStatus) {
    if (EventId >= MAX_DEM_EVENTS) {
        return E_NOT_OK;
    }
    Dem_EventMemory[EventId] = EventStatus;
    return E_OK;
}

Dem_EventStatusType Dem_GetEventStatus(uint16_t EventId) {
    if (EventId >= MAX_DEM_EVENTS) {
        return DEM_EVENT_STATUS_FAILED;
    }
    return Dem_EventMemory[EventId];
}

void Dem_ClearAllDTCs(void) {
    for (uint16_t i = 0U; i < MAX_DEM_EVENTS; i++) {
        Dem_EventMemory[i] = DEM_EVENT_STATUS_PASSED;
    }
}
