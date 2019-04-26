cmake_minimum_required(VERSION 3.13)
project(hw06)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw06 src/main.cpp src/CustomerLine.cpp src/CustomerLine.h src/PriorityQueue.cpp src/PriorityQueue.h src/Node.cpp src/Node.h)