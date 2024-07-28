project (psi_si)

set (
   SRCS
   eit.c
   nit.c
   pat.c
   pmt.c
   sdt.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${mb86h60_hello_world_SOURCE_DIR}
    ${drv_SOURCE_DIR}
    ${ucos_ii_SOURCE_DIR}/Source
    ${ucos_ii_SOURCE_DIR}/Cfg
    ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
)

add_definitions(
    --gnu
    --c99
#    -O2
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
#    NIT_DESCRIPTORS_LINKAGE_DEBUG
    PMT_STREAM_DEBUG
    PMT_DESCRIPTORS_TAG_DEBUG
)

