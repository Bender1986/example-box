cmake_minimum_required(VERSION 3.16.3)

project(FilmsProject VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")



add_executable(films main.cpp)

target_link_libraries(films PRIVATE nlohmann_json::nlohmann_json)
