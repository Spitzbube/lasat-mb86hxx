project (drv)

set (
   SRCS
   sys_services.c
   gpio.c
   uart.c
   intr.c
   timer.c
   ir.c
   flash.c
   i2c.c
   clkpwr.c
   bm.c
   tsd.c
   tsd_reg.c
   auout.c
   dpll.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
   ${ucos_ii_SOURCE_DIR}/Cfg
   ${ucos_ii_SOURCE_DIR}/Source
   ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
)

add_definitions(
#    --gnu
    --c99
#    -O2
)

