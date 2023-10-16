cmake_minimum_required(VERSION 3.0)
project(vtk2geogram)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(ultimaille)

include_directories(ultimaille ultimaille/ext)

add_executable(vtk2geogram main.cpp)
target_link_libraries(vtk2geogram ultimaille)