cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER "g++")

set(SOURCE_FILES src/beakjoon/2448.cpp)

ADD_EXECUTABLE(app.out ${SOURCE_FILES})