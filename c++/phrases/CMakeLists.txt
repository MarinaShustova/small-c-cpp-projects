cmake_minimum_required(VERSION 3.8)
project(Phrases)

set(CMAKE_CXX_STANDARD 11)

add_executable(phrases help_funkt.cpp main.cpp)
add_executable(tests help_funkt.cpp tests.cpp)