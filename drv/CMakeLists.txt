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
