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
The `algorithms.h` class replicates a handful of the sorting algorithms found in the STL library, notably: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, and Quick Sort. 

Each of these algorithms will be described below, both in terms of explicit functionality when reading the code itself, as well as "what the algorithm is doing" in more plain terms. 

### Bubble Sort
The Bubble Sort algorithm iterates through a list of elements and sorts them by checking two adjacent elements at a time and putting them in order. Generally speaking, this sorting algorithm isn't that efficient, even with smaller data sets, but it is very easy to write and conceptualize. 

**Implementation**
~~~C++
template <typename T> void bubble_sort(T arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
~~~

**Line by Line Explanation**

`template <typename T> void bubble_sort(T arr[], int size) {}`
>`template <typename T>` creates a function that serves as a template for an unknown type, meaning that the function is initialized to take in an unknown type that we refer to as T. This unknown type is used as you would any normal type, as seen, an array of unknown type is passed in as the first parameter, then the size of this array, represented by an Integer, is also passed in as the second parameter.

`for (int i = 0; i < size - 1; i++) {}`
> Create a standard for loop starting at 0 as long as the iterator, "i", is less than the size minus one, due to iterator indexing at 0.

~~~C++
for (int j = 0; j < size - i - 1; j++) {
  if (arr[j] > arr[j+1]) {
    int temp = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = temp;
  }
}
~~~
> This nested for-loop begins at index 0, iterates through the array once switching adjacent elements depending on which is larger. This loop continues for `j < size - i - 1` to account for both a minus one offset with the size from indexing at zero, and then subtracting by `i` in order to keep the elements that have been properly sorted to their proper location. This sorting method implements some standard peeking to the next elements value and a basic switching of values through use of a temporary variable.

### Selection Sort
[ALGORITHM DESCRIPTION] <br>
[FULL ALGORITHM CODE HERE] <br>
[BEGIN DESCRIBING EACH SEGMENT / FEW LINES OF THE CODE WITH CODE BLOCKS UNDERNEATH TO SHOW THOSE SEGMENTS]

### Insertion Sort
[ALGORITHM DESCRIPTION] <br>
[FULL ALGORITHM CODE HERE] <br>
[BEGIN DESCRIBING EACH SEGMENT / FEW LINES OF THE CODE WITH CODE BLOCKS UNDERNEATH TO SHOW THOSE SEGMENTS]

### Merge Sort
[ALGORITHM DESCRIPTION] <br>
[FULL ALGORITHM CODE HERE] <br>
[BEGIN DESCRIBING EACH SEGMENT / FEW LINES OF THE CODE WITH CODE BLOCKS UNDERNEATH TO SHOW THOSE SEGMENTS]

### Quick Sort
[ALGORITHM DESCRIPTION] <br>
[FULL ALGORITHM CODE HERE] <br>
[BEGIN DESCRIBING EACH SEGMENT / FEW LINES OF THE CODE WITH CODE BLOCKS UNDERNEATH TO SHOW THOSE SEGMENTS]
