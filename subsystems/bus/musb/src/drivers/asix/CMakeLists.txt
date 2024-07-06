project (musb_asix)

set (
   MUSB_ASIX_SRCS
   mu_asix.c
)

add_library(${PROJECT_NAME} STATIC ${MUSB_ASIX_SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${musb_SOURCE_DIR}/include
    ${musb_SOURCE_DIR}/include/class
    ${musb_SOURCE_DIR}/src/systems/FAPI4
    ${ucos_ii_SOURCE_DIR}/Cfg
    ${ucos_ii_SOURCE_DIR}/Source
    ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
)

