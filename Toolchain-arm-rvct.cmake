set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH_BIN}/armcc)
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PATH_BIN}/armcc)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PATH_BIN}/armasm)

# Somehow the definition of TOOLCHAIN_PATH_BIN from outside truncates TOOLCHAIN_PATH_DATA
set(TOOLCHAIN_PATH_DATA /opt/RVCT/Data/3.1/640)

#set(CMAKE_CXX_ARCHIVE_CREATE "x -X -r5 -o <TARGET> <LINK_FLAGS> <OBJECTS>")
#set(CMAKE_C_ARCHIVE_CREATE "x --create -cr <TARGET> <LINK_FLAGS> <OBJECTS>")
set(CMAKE_ASM_CREATE_STATIC_LIBRARY "<CMAKE_AR> --create -r -c -s -v <TARGET> <OBJECTS> ")

#set(CMAKE_C_LINK_FLAGS "--libpath=${TOOLCHAIN_PATH_DATA}/lib --cpu ARM1176JZF-S")
#set(CMAKE_CXX_LINK_EXECUTABLE
#    "armlink <CMAKE_CXX_LINK_FLAGS>")
#set(CMAKE_LINKER
#    "armlink <CMAKE_CXX_LINK_FLAGS>")

add_definitions(
    --arm
    --cpu ARM1176JZF-S
    --fpu VFPv2
#    --cpu=ARM1176JZF-S
#    --enum_is_int
    --no_unaligned_access
#    --gnu
    -I${TOOLCHAIN_PATH_DATA}/include/unix
)

add_link_options(
    --libpath=${TOOLCHAIN_PATH_DATA}/lib
#    --info totals,sizes,unused,libraries,inline,debug,common,stack,summarystack 
)

#set(CMAKE_CXX_FLAGS
#    "${CMAKE_CXX_FLAGS} --cpp --no_rtti")
#set(CMAKE_C_FLAGS
#     "${CMAKE_C_FLAGS} --c99")
