cmake_minimum_required(VERSION 3.16.3)

project(RegistryProject VERSION 0.1.0)


set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/registry.h
    ${CMAKE_SOURCE_DIR}/include/registry.hpp
    )

    
set(SOURCES 
    
    ${CMAKE_SOURCE_DIR}/src/main.cpp)


add_executable(registry ${HEADERS} ${SOURCES})

target_include_directories(registry PRIVATE ${CMAKE_SOURCE_DIR}/include)