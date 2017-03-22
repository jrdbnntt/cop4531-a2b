cmake_minimum_required(VERSION 3.6)
project(cop4531_a2b)

set(CMAKE_CXX_STANDARD 11)

add_executable(Dynamic.exe Dynamic.cpp main.cpp)
add_executable(Memoized.exe Memoized.cpp main.cpp)

