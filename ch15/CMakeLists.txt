cmake_minimum_required(VERSION 3.12)
project(ch15)

#set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(.)

add_executable(ch15 main.cc quote.h quote.cc demo.h demo.cc student.cc student.h base.cc base.h)

