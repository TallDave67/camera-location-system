#!/bin/sh
export CC=/usr/bin/clang-12
export CXX=/usr/bin/clang++-12

cd build
cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- ../
make VERBOSE=1
