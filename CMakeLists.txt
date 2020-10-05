cmake_minimum_required(VERSION 3.16.3)
project(/home/jcmartin/Documents/C++/ATMMachine)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11)
include_directories(lib/include/)

add_executable( ATMMachine src/main.cpp src/Users.cpp lib/include/Users.h)
