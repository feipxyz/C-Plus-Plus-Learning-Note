cmake_minimum_required(VERSION 3.12)
project(ch12)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(ch12
        querymain.cc QueryResult.h QueryResult.cc TextQuery.cc TextQuery.h querymain.cc)
