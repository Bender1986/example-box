cmake_minimum_required(VERSION 3.16.3)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(SimulatorApp main.cpp 
                ${MY_INCLUDE_DIR}/cpu.h  cpu.cpp
                ${MY_INCLUDE_DIR}/ram.h  ram.cpp
                ${MY_INCLUDE_DIR}/disk.h disk.cpp
                ${MY_INCLUDE_DIR}/gpu.h  gpu.cpp
                ${MY_INCLUDE_DIR}/kbd.h  kbd.cpp
               )

target_include_directories(SimulatorApp PUBLIC ${MY_INCLUDE_DIR})