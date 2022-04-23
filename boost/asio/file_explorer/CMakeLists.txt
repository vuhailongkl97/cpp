cmake_minimum_required(VERSION 3.16)
Project(hello)

add_executable(hello src/main.cpp src/html.cpp src/files.cpp src/http_server.cpp)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/home/long/bin/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/home/long/bin")

find_package(Boost REQUIRED)
message (${Boost_INCLUDE_DIRS})
target_link_libraries(hello pthread ${Boost_LIBRARIES} stdc++fs)
target_include_directories(hello PUBLIC ${Boost_INCLUDE_DIRS} inc )
