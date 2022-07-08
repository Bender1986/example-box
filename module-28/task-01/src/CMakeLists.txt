cmake_minimum_required(VERSION 3.16.3)

project("SwimApp" VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(THREADS_PREFER_PTHREAD_FLAG ON)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_executable(SwimApp main.cpp               
                ${MY_INCLUDE_DIR}/swim.h swim.cpp       
               
               )

target_include_directories(SwimApp PUBLIC ${MY_INCLUDE_DIR})


find_package(Threads REQUIRED)

target_link_libraries(SwimApp PRIVATE Threads::Threads)