cmake_minimum_required(VERSION 3.16.3)

project("UserRequestApp" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)


set(BUILD_CPR_TESTS OF)
set(CMAKE_USE_OPENSSL OF)
set(BUILD_CPR_PROXY ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


add_executable(UserRequestApp main.cpp)

target_link_libraries(UserRequestApp PRIVATE cpr::cpr)