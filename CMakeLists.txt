cmake_minimum_required(VERSION 3.28)
project(OperateSystem_simulation)

set(CMAKE_CXX_STANDARD 26)

add_executable(OperateSystem_simulation main.cpp
        LRU_cache.cpp
        LRU_cache.h
        myList.cpp
)
