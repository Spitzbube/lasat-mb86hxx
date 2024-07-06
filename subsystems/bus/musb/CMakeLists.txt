project (musb)

set (
   SRCS
   src/cd/mu_cntlr.c
   src/cd/mu_mdr.c
   src/cd/mu_hdr.c
   src/cd/mu_drc.c
   src/cd/mu_hst.c
   src/cd/mu_fun.c
   src/cd/mu_descs.c
   src/cd/mu_hsdma.c
   src/cd/mu_list.c
   src/cd/mu_pip.c
   src/lib/mu_bits.c
   src/lib/mu_strng.c
   src/systems/FAPI4/mu_mem.c
   src/systems/FAPI4/mu_reg.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    include/class
    src/systems/FAPI4
    ${ucos_ii_SOURCE_DIR}/Cfg
    ${ucos_ii_SOURCE_DIR}/Source
    ${ucos_ii_SOURCE_DIR}/Ports/ARM/Generic/RealView
)

target_link_libraries(${PROJECT_NAME}
    startup
    ucos_ii
)

add_definitions(
    --gnu
    --c99
#    -O2
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    -DMUSB_MHDRC
    -DMUSB_DMA
)

add_subdirectory(src/drivers/hub)
add_subdirectory(src/drivers/msd)
