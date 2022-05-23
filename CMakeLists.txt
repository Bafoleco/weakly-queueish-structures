cmake_minimum_required(VERSION 3.21)
project(weakly_queueish_structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(weakly_queueish_structures main.cpp WeaklyQueueishSearch.cpp WeaklyQueueishSearch.h SearchStructure.cpp SearchStructure.h)
