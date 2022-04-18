cmake_minimum_required(VERSION 3.16.3)

project("WorkApp" VERSION 1.0.0)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(WorkApp main.cpp 
                
                ${MY_INCLUDE_DIR}/work.h 
                ${MY_INCLUDE_DIR}/work.cpp                
               )

target_include_directories(WorkApp PUBLIC ${MY_INCLUDE_DIR})