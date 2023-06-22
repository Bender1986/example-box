cmake_minimum_required(VERSION 3.16.3)

project(DogToy VERSION 0.1.0)

set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/dog.h
    ${CMAKE_SOURCE_DIR}/include/toy.h)

set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/dog.cpp
    ${CMAKE_SOURCE_DIR}/src/toy.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp)


add_executable(dogtoy ${HEADERS} ${SOURCES})

target_include_directories(dogtoy PRIVATE ${CMAKE_SOURCE_DIR}/include)