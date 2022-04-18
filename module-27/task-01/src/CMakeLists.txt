cmake_minimum_required(VERSION 3.16.3)

project("TownElfApp" VERSION 1.0.0)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(TownElfApp main.cpp 
                ${MY_INCLUDE_DIR}/elf.h 
                ${MY_INCLUDE_DIR}/elf.cpp 
               
               )

target_include_directories(TownElfApp PUBLIC ${MY_INCLUDE_DIR})