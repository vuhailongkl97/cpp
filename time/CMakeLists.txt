cmake_minimum_required(VERSION 3.10)
project(time_related)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add clang-tidy target
find_program(CLANG_TIDY_EXECUTABLE clang-tidy)
if(CLANG_TIDY_EXECUTABLE)
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -header-filter=.;
  -warnings-as-errors=*;
  --fix;
  --fix-errors;)
endif()

add_executable(stop_watch stop_watch.cpp)

