cmake_minimum_required(VERSION 3.21)
project(PreventivaMec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt's automatic processing of MOC/UIC/RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6 (Core, Test)
find_package(Qt6 6.2 REQUIRED COMPONENTS Core Test)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
