cmake_minimum_required(VERSION 3.16.3)

# Name variable include
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


# Linced files project
add_executable(WorkWindowApp main.cpp
               ${MY_INCLUDE_DIR}/window.h window.cpp
               )

# Set include directory
target_include_directories(WorkWindowApp PUBLIC ${MY_INCLUDE_DIR})