cmake_minimum_required(VERSION 3.16.3)

project("Operation App" VERSION 1.0)

add_executable(OperationApp src/main.cpp include/Operation.h src/Operation.cpp)

target_include_directories(OperationApp PUBLIC include)
