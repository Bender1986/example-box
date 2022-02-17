cmake_minimum_required(VERSION 3.16.3)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(PhoneApp main.cpp 
                ${MY_INCLUDE_DIR}/phone.h phone.cpp               
               )

target_include_directories(PhoneApp PUBLIC ${MY_INCLUDE_DIR})