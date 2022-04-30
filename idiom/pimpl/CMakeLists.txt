Project(hello)

add_executable(hello main.cpp)
add_library(lib.a lib.cpp)

target_link_libraries(hello PRIVATE lib.a)
