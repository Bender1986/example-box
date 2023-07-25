cmake_minimum_required(VERSION 3.16.3)

project(TrashMagazine VERSION 0.1.0)

set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/trash.h)
  
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/trash.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp)


add_executable(trash ${HEADERS} ${SOURCES})

target_include_directories(trash PRIVATE ${CMAKE_SOURCE_DIR}/include)
