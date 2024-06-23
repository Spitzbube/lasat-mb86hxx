
project (startup)

set (
   SRCS
   src/arm1176_start.s
   src/arm1176_tcm.s
   src/arm1176_vfp_fast.s
   src/arm1176_mmu.s
)

add_library(${PROJECT_NAME} STATIC ${SRCS})
enable_language(ASM)
