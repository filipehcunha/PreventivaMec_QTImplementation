cmake_minimum_required(VERSION 3.21)
project(PreventivaMecQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Output dirs
if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()
if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Test)

add_subdirectory(sdk)
add_subdirectory(plugins/maintenance_service)
add_subdirectory(app)
add_subdirectory(docs)

enable_testing()
add_subdirectory(tests/gui)
add_subdirectory(tests/unit)
add_subdirectory(tests/functional)
