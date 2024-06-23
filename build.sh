#!/bin/bash

rm -rf build
mkdir build
cd build

TOOLCHAIN_PATH=/opt/RVCT

cmake -DCMAKE_TOOLCHAIN_FILE=Toolchain-arm-rvct.cmake \
    .. \
    -DTOOLCHAIN_PATH_BIN:PATH=${TOOLCHAIN_PATH}/Programs/3.1/640/linux-pentium \
    -DTOOLCHAIN_PATH_DATA:PATH=${TOOLCHAIN_PATH}/Data/3.1/640 \

make


