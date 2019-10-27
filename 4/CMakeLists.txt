cmake_minimum_required(VERSION 3.14)
project(GMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GMS main.cpp hpp/MSTree.hpp cpp/MSTree.cpp hpp/Edge.hpp hpp/DSNode.hpp cpp/DSNode.cpp cpp/Edge.cpp hpp/FileReader.hpp cpp/FileReader.cpp)