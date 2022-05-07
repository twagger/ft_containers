cmake_minimum_required(VERSION 3.14)
project(ft_containers)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# Directories for header files
include_directories(srcs/containers)
include_directories(srcs/iterators)
include_directories(srcs/utils)

# Directories for source files
add_subdirectory(tests)
add_subdirectory(lib/googletest)
