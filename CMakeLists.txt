cmake_minimum_required(VERSION 3.15)
project(LinZ)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinZ main.cpp)


add_subdirectory(vendor/customized/CLI11)

target_link_libraries(LinZ CLI11)