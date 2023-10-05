# dsi
The dsi library is an attempt at a recreation of the C++ STL Library, meant for me to learn how the STL library is created, and more generally, the process of creating a library. With that said, this is also my first attempt at ever writing a README.md file. The dsi library includes a set of classes dervied from the STL library, those classes are: algorithms.h, linked_list.h, priority_queue.h, queue.h, stack.h, and vector.h. Each class and its respective utilities will be covered in this README.

---

## Installation Instructions
1. Download the `dsi library` and unzip the zip file into the path where all of your projects are stored. This is for convenience when linking the library to projects that use it.
2. Once you unzip the folder, you should get a `dsi-main` folder. Rename this folder to just `dsi`.
3. Once you're in a given project you would like to use `dsi` in, update the CMakeLists.txt file of that project like so:
~~~CMake
cmake_minimum_required(VERSION 3.24)
project(project_name)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_name main.cpp)
add_subdirectory(C:/path/to/your/library/storage/dsi dsi_build)

target_link_libraries(project_name PRIVATE C:/path/to/your/library/storage/dsi/cmake-build-debug/libdsi.a)
target_include_directories(project_name PRIVATE C:/path/to/your/library/storage/dsi/include)
~~~
4. Setting up the proper include headers for the classes that are include in dsi should look something like this at the top of your main.cpp project file:
~~~C++
#include <dsi/algorithms.h>
#include <dsi/vector.h>
#include <dsi/linked_list.h>
~~~

---

## Algorithms
