cmake_minimum_required(VERSION 3.3)

project(sample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(erfinv erfinv.cpp)
target_compile_options(erfinv
  PUBLIC -O0 -Wall
  )
