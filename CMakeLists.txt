cmake_minimum_required(VERSION 3.10)
project(AutosarBmsSilEcu C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Strict compiler warnings aligned with MISRA-C best practices
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/rte
    ${PROJECT_SOURCE_DIR}/bsw
    ${PROJECT_SOURCE_DIR}/swc
)

set(SOURCES
    swc/BmsMonitor_SWC.c
    rte/Rte_BmsMonitor.c
    bsw/CanIf.c
    bsw/Dem.c
    sil_tests/sil_harness.c
)

add_executable(bms_sil_ecu ${SOURCES})
