cmake_minimum_required(VERSION 3.24)

project(dsi VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/dsi)

add_library(dsi STATIC
        include/dsi/vector.h
        include/dsi/linked_list.h
        include/dsi/algorithms.h
        include/dsi/priority_queue.h
        include/dsi/queue.h
        include/dsi/stack.h
        src/stack.cpp)
add_executable(testExe main.cpp)

target_link_libraries(testExe PRIVATE dsi)