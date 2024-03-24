cmake_minimum_required(VERSION 3.24)
project(clox_antlr)
set(CMAKE_CXX_STANDARD 20)

include(cmake-build-debug/conan_toolchain.cmake)
find_package(antlr4-runtime)
find_package(fmt)

add_executable(clox_antlr main.cpp loxLexer.cpp loxLexer.h loxParser.cpp loxParser.h compiler.cpp compiler.h
        chunk.cpp
        chunk.h
        object.cpp
        object.h
        vm.cpp
        vm.h)
target_link_libraries(clox_antlr antlr4_static fmt::fmt)