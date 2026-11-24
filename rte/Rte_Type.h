#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t Std_ReturnType;

#define E_OK        ((Std_ReturnType)0x00U)
#define E_NOT_OK    ((Std_ReturnType)0x01U)

/* AUTOSAR Application Data Types */
typedef uint16_t Voltage_mV_t;
typedef int16_t  Temp_DegC_t;
typedef uint8_t  BmsState_t;

#define BMS_STATE_NORMAL        ((BmsState_t)0x00U)
#define BMS_STATE_OVERVOLTAGE   ((BmsState_t)0x01U)
#define BMS_STATE_UNDERVOLTAGE  ((BmsState_t)0x02U)
#define BMS_STATE_OVERTEMP      ((BmsState_t)0x03U)

/* Diagnostic Event Status */
typedef uint8_t Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED ((Dem_EventStatusType)0x00U)
#define DEM_EVENT_STATUS_FAILED ((Dem_EventStatusType)0x01U)

#endif /* RTE_TYPE_H */
