cmake_minimum_required(VERSION 3.16.3)

project("FigureApp" VERSION 1.0.0)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(FigureApp main.cpp 
                ${MY_INCLUDE_DIR}/figure.h 
                figure.cpp                
               )

target_include_directories(FigureApp PUBLIC ${MY_INCLUDE_DIR})