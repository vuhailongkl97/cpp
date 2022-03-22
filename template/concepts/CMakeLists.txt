cmake_minimum_required( VERSION 3.0)
project(concepts)


add_compile_options(-g -fconcepts)
add_executable(concepts concepts.cpp)
