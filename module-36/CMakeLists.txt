cmake_minimum_required(VERSION 3.16.3)

project(CirclePrint VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_AUTOUIC ON)


find_package(Qt5Widgets REQUIRED)


add_executable(circle main.cpp)

target_link_libraries(circle PRIVATE Qt5::Widgets)
target_link_libraries(circle PRIVATE Qt5::Core)

target_include_directories(circle PUBLIC qt5)


#qt5_use_modules(circle Widgets)
#qt5_use_modules(circle Core)