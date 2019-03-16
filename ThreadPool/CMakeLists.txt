cmake_minimum_required(VERSION 3.13)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 11)

add_executable(ThreadPool main.cpp thread_pool.h thread_pool2.h)