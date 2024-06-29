project (drv)

set (
   SRCS
   sys_services.c
   gpio.c
   uart.c
   intr.c
   timer.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
   ${ucos_ii_SOURCE_DIR}/Cfg
   ${ucos_ii_SOURCE_DIR}/Source
   ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
)
