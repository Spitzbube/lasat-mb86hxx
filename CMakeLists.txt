cmake_minimum_required(VERSION 3.13)

project (mb86h60_hello_world)

set(SRCS
   main.c                   #?                              0x2349c5a0? -> 2349D220?
   main1.c                  #0x23400510?    0x23491d8c      0x2349d230?
   sub_2340199c.c           #0x2340199c     0x23491e10
   sub_23402e8e.c           #0x2340257c?    0x23491e20
   sub_2340a6a0.c           #0x2340956c     0x23491ffc      0x234fd8f0
   console.c                #0x2341af84?
   memblk.c
   dma.c
   usb.c
   sub_23467de0.c
   network.c
   tcp_console.c
   ir_user.c                #0x2340d3ec     0x23492068      0x235491e4
   ir_decode.c              #0x23453d34     0x23493628?
   thumb.c                  #0x2343d104?    ?               0x235fdf28?
   thumb1.c                 #0x2346ec9c     0x2349596c?
   thumb2.c
   menu_general_settings.c
   vfd.c
   fpc.c
   frontdisplay.c           #0x23419fd4     0x23492118
   radiotext.c              #0x2341a42c     0x2349211c
   powermode.c              #0x23412ea4     0x234920c8      0x2358be90
   ota.c                    #0x234133a0     0x234920cc      0x2358c124
   av.c
   fe_manager.c
   m88dc2800.c
   sub_23472ef0.c
   sub_2340217c.c
   texttable.c
   sub_23438084.c
   crc.c
   sub_2346fac4.c
   sub_23470890.c
   sub_2345d710.c
   sub_23418e1c.c
   psi.c
   nit.c
   eit.c
   pat.c
   pmt.c
   sdt.c
   sub_2344ed20.c
   sub_23458874.c
   sub_23411b0c.c
   channel_list_update.c    #0x2343dcfc
   audec.c
   scan.c
   menu_channel_search.c    #0x23470090     0x23495ea0      0x238de5d0
   sub_23472004.c           #0x23471fe4     0x23496474      0x238e0ad4
   sub_2344f770.c
   sub_234515f0.c
   ca_hw.c
   viscale_osd.c
   videc.c
   sub_234774c4.c
   graphic.c
   sub_23419cd0.c
   sub_2345bc50.c
   menu_guided_install.c    #?
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
