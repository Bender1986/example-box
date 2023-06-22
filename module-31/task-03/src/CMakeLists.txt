cmake_minimum_required(VERSION 3.16.3)

project(GraphProject VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/graph.h
    ${CMAKE_SOURCE_DIR}/include/list_graph.h
    ${CMAKE_SOURCE_DIR}/include/matrix_graph.h
    ${CMAKE_SOURCE_DIR}/include/matrix_graph.hpp
)

set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/graph.cpp
    ${CMAKE_SOURCE_DIR}/src/list_graph.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_executable(test_graph ${HEADERS} ${SOURCES})


target_include_directories(test_graph PRIVATE ${CMAKE_SOURCE_DIR}/include)