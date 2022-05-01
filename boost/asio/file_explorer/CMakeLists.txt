cmake_minimum_required(VERSION 3.16)
Project(hello)

find_program(CLANG_TIDY clang-tidy)
message("use" ${CLANG_TIDY})
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy;
  -header-filter=*.hpp;)
#  -warnings-as-errors=*;)

add_executable(hello src/main.cpp src/html.cpp src/files.cpp src/http_server.cpp)
set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/home/long/bin/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/home/long/bin")

find_package(Boost REQUIRED)
message (${Boost_INCLUDE_DIRS})
target_link_libraries(hello pthread ${Boost_LIBRARIES} stdc++fs)
target_include_directories(hello PUBLIC ${Boost_INCLUDE_DIRS} inc )
