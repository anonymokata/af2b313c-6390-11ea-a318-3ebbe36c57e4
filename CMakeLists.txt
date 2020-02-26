cmake_minimum_required(VERSION 3.15)
project(WordSearchKata)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

add_executable(WordSearchKata main.cpp FileReader.cpp FileReader.hpp)