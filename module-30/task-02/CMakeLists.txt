cmake_minimum_required(VERSION 3.16.3)

project(GetHeaderApp VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(GetHeaderApp main.cpp)


set(BUILD_CPR_TESTS OF)
set(CMAKE_USE_OPENSSL OF)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


target_link_libraries(GetHeaderApp PRIVATE cpr::cpr)