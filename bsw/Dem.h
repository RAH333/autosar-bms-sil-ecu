#ifndef DEM_H
#define DEM_H

#include "../rte/Rte_Type.h"

/* Diagnostic Trouble Code (DTC) Event IDs */
#define DEM_EVENT_CELL_OVERVOLTAGE   ((uint16_t)0x01U)
#define DEM_EVENT_CELL_UNDERVOLTAGE  ((uint16_t)0x02U)
#define DEM_EVENT_PACK_OVERTEMP      ((uint16_t)0x03U)

Std_ReturnType Dem_SetEventStatus(uint16_t EventId, Dem_EventStatusType EventStatus);
Dem_EventStatusType Dem_GetEventStatus(uint16_t EventId);
void Dem_ClearAllDTCs(void);

#endif /* DEM_H */
