cmake_minimum_required(VERSION 3.13)

project (mb86h60_hello_world)

set(SRCS
   main.c
   sub_2340199c.c
   main1.c
   console.c
   memblk.c
   dma.c
   usb.c
   sub_23467de0.c
   network.c
   tcp_console.c
   ir_user.c
   ir_decode.c
   thumb.c
   thumb1.c
   thumb2.c
   menu_general_settings.c
   vfd.c
   fpc.c
   frontdisplay.c
   powermode.c
   av.c
   texttable.c
   sub_23438084.c
   sub_2340a6a0.c
   crc.c
   sub_2346fac4.c
   sub_23470890.c
   hexdump.c
   todo.c
)

add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(boot/startup)
add_subdirectory(rtos/uCOS-II)
add_subdirectory(drv)
add_subdirectory(subsystems/bus/musb)
add_subdirectory(subsystems/net/lwip)

target_link_libraries(${PROJECT_NAME}
#    startup
    drv
#    ucos_ii
    musb
    musb_hub
    musb_msd
    musb_asix
    lwipcore
)

target_include_directories(${PROJECT_NAME} PUBLIC
    drv
    ${musb_SOURCE_DIR}/include
    ${musb_SOURCE_DIR}/src/systems/FAPI4
    ${lwIP_SOURCE_DIR}/src/include
)

add_definitions(
    --gnu
    --c99
#    -O2
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    USB_HUB
    USB_ASIX
)

set(ENTRY_FUNC ARM1176_Start)
set(PROGRAM_LOAD_ADDRESS 0x23400000)

#SHELL is needed to avoid de-duplication
target_link_options(${PROJECT_NAME} PRIVATE 
    --ro-base ${PROGRAM_LOAD_ADDRESS}
    "SHELL:--entry ${ENTRY_FUNC}"
    "SHELL:--first ${ENTRY_FUNC}"
    "SHELL:--startup ${ENTRY_FUNC}"
)

# For the moment this is RVCT-specific
add_custom_command(TARGET ${PROJECT_NAME}
    COMMAND ${TOOLCHAIN_PATH_BIN}/fromelf ${PROJECT_NAME}.elf --text -v -c -d -e -g -r -s -t -y -z -o ${PROJECT_NAME}.txt
)
