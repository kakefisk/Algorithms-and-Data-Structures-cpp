cmake_minimum_required(VERSION 3.6)
project(Algorithms_and_Data_Structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Algorithm.cpp
    Algorithm.h
    LinkedList.cpp
    LinkedList.h
    main.cpp)

add_executable(Algorithms_and_Data_Structures ${SOURCE_FILES})