cmake_minimum_required(VERSION 3.5)

project(labs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(labs shell.h shell.cpp additivemethods.h
  laba10.h laba10.cpp main.cpp)
