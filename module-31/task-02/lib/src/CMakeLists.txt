cmake_minimum_required(VERSION 3.16.3)

project(MyLib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(MY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(MY_SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../src)


# Source files
set(SOURCE my_shared_ptr.cpp)


# Header files
set(HEADERS
    ${MY_INCLUDE_DIR}/my_shared_ptr.h 
    ${MY_INCLUDE_DIR}/my_shared_ptr.hpp
    )


# Add library
add_library(mylib SHARED ${SOURCE} ${HEADER})


# Include to target
target_include_directories(mylib
                           PRIVATE 
                           ${CMAKE_CURRENT_SOURCE_DIR}/../include)

                           
