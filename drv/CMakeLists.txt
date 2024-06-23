project (drv)

set (
   SRCS
   sys_services.c
   gpio.c
   uart.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})
