cmake_minimum_required(VERSION 3.25)
project(LicensePlate)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)
add_executable(LicensePlate main.cpp)
target_link_libraries(LicensePlate ${OpenCV_LIBS})

