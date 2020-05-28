cmake_minimum_required(VERSION 3.14)
project(GMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GMS main.cpp hpp/MinSpanningTree.hpp cpp/MinSpanningTree.cpp hpp/EdgeQueue.hpp hpp/DisjointSets.hpp cpp/DisjointSets.cpp cpp/EdgeQueue.cpp hpp/FileReader.hpp cpp/FileReader.cpp)