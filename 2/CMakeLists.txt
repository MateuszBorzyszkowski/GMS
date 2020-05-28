cmake_minimum_required(VERSION 3.10.2)
project(2)

set(CMAKE_CXX_STANDARD 14)

add_executable(2 main.cpp hpp/FileReader.hpp cpp/FileReader.cpp)
