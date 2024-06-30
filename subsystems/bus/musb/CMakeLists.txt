project (musb)

set (
   SRCS
   src/cd/mu_cntlr.c
   src/cd/mu_mdr.c
   src/cd/mu_hdr.c
   src/cd/mu_hsdma.c
   src/cd/mu_list.c
   src/systems/FAPI4/mu_mem.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    src/systems/FAPI4
)

add_definitions(
    --gnu
#    -O2
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    -DMUSB_MHDRC
    -DMUSB_DMA
)
