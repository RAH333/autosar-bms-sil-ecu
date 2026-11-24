#include <stdio.h>
#include <stdlib.h>
#include "../swc/BmsMonitor_SWC.h"
#include "../bsw/Dem.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <voltage_mV> <temp_degC>\n", argv[0]);
        return 1;
    }

    Voltage_mV_t inputVoltage = (Voltage_mV_t)atoi(argv[1]);
    Temp_DegC_t  inputTemp    = (Temp_DegC_t)atoi(argv[2]);

    /* Initialize SWC */
    BmsMonitor_Init();

    /* Inject SIL Test Vectors into RTE */
    Rte_Sim_SetCellVoltage(inputVoltage);
    Rte_Sim_SetPackTemp(inputTemp);

    /* Execute 10ms Cyclic Runnable */
    BmsMonitor_MainFunction_10ms();

    /* Output Telemetry for Python SIL Verification */
    printf("SIL_RESULT|STATE:%u|DTC_OV:%u|DTC_UV:%u|DTC_OT:%u\n",
           Rte_Sim_GetBmsStatus(),
           Dem_GetEventStatus(DEM_EVENT_CELL_OVERVOLTAGE),
           Dem_GetEventStatus(DEM_EVENT_CELL_UNDERVOLTAGE),
           Dem_GetEventStatus(DEM_EVENT_PACK_OVERTEMP));

    return 0;
}
