cmake_minimum_required(VERSION 3.16.3)

project(SharedPtrToy VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


set(HEADERS 
    ${CMAKE_SOURCE_DIR}/include/toy.h
    )

set(SOURCES 
    ${CMAKE_SOURCE_DIR}/src/toy.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    )


add_executable(shared_toy ${HEADERS} ${SOURCES})


target_include_directories(shared_toy
                            PRIVATE
                            ${CMAKE_SOURCE_DIR}/include                
)

target_include_directories(shared_toy
                            PRIVATE
                            ${CMAKE_SOURCE_DIR}/lib/include               
)

target_link_libraries(shared_toy mylib)