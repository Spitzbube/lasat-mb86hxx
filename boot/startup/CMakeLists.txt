
project (startup)

set (
   SRCS
   src/arm1176_start.s
   src/arm1176_tcm.s
   src/arm1176_vfp_fast.s
   src/arm1176_mmu.s
   src/arm1176_intr_handler.s
)

add_library(${PROJECT_NAME} STATIC ${SRCS})
enable_language(ASM)

add_definitions(
   --debug 
   -D__DEBUG__=1 -O0
)
