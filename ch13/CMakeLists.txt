cmake_minimum_required(VERSION 3.12)
project(ch12)

#set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(.)

add_executable(ch13 folder_main.cc folder.h folder.cc hasptr.h)
