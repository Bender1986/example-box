cmake_minimum_required(VERSION 3.16.3)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(AudioPlayerApp main.cpp 
                ${MY_INCLUDE_DIR}/player.h  player.cpp
               
               )

target_include_directories(AudioPlayerApp PUBLIC ${MY_INCLUDE_DIR})