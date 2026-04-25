

cmake_minimum_required(VERSION 3.10)
project(EvilClass)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags for better warnings and optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wpedantic")

# Add executable
add_executable(code main.cpp evil.hpp)

# Ensure proper compilation of C++ code
set_target_properties(code PROPERTIES CXX_STANDARD 14)

