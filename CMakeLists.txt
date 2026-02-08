cmake_minimum_required(VERSION 4.0)
project(task3)

set(CMAKE_CXX_STANDARD 20)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
file(GLOB modules "modules/scripts/*.cpp")

add_executable(task3 main.cpp
        format.cpp
        format.h
        modules/Modules.cpp
        modules/Modules.h
        ${modules}
)
