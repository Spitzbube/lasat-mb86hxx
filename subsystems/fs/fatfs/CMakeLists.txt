project (fatfs)

set (
   SRCS
   fatfs.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${mb86h60_SOURCE_DIR}
    ${drv_SOURCE_DIR}
    ${ucos_ii_SOURCE_DIR}/Source
    ${ucos_ii_SOURCE_DIR}/Cfg
    ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
    ${musb_SOURCE_DIR}/include
    ${musb_SOURCE_DIR}/src/msc
)

add_definitions(
    --gnu
    --c99
#    -O2
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
    FATFS_DEBUG
)

