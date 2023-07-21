cmake_minimum_required(VERSION 3.16.3)

project(FilmsProject VERSION 0.1.0)

add_subdirectory(src)

add_subdirectory(${CMAKE_SOURCE_DIR}/contrib/nlohmann_json)

