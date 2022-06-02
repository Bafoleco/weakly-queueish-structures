cmake_minimum_required(VERSION 3.21)
project(weakly_queueish_structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(weakly_queueish_structures main.cpp generics_attempt/WeaklyQueueishSearch.cpp generics_attempt/WeaklyQueueishSearch.h generics_attempt/SearchStructure.cpp generics_attempt/SearchStructure.h Dict.cpp Dict.h generics_attempt/Test.cpp generics_attempt/Test.h WeaklyQueueishDict.h WeaklyQueueishVecDict.h VecDict.h)
