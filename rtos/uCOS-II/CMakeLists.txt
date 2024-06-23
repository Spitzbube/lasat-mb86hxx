project (ucos_ii)

set (
   SRCS
   Source/kernel.c
   Source/kernel_stack.c
   Source/kernel_task.c
   Source/os_mem.c
   Source/os_q.c
)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE
    .
    Source
)

add_definitions(
    --gnu
)
