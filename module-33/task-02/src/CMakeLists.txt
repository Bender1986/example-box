cmake_minimum_required(VERSION 3.16.3)

project(FishGame VERSION 0.1.0)

set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/fish.h)
  
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/fish.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp)


add_executable(fish ${HEADERS} ${SOURCES})

target_include_directories(fish PRIVATE ${CMAKE_SOURCE_DIR}/include)
