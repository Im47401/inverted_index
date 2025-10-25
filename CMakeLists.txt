cmake_minimum_required(VERSION 3.10)
project(InvertedIndex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

include_directories(include)

add_executable(inverted_index
    src/main.cpp
    src/inverted_index.cpp
)