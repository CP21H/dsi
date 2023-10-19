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
>`template <typename T>` creates a function that serves as a template for an unknown type, meaning that the function is initialized to take in an unknown type that we refer to as `T`. This unknown type is used as you would any normal type, as seen, an array of unknown type is passed in as the first parameter, then the size of this array, represented by an `Integer`, is also passed in as the second parameter.

`for (int i = 0; i < size - 1; i++) {}`
> Create a standard for-loop starting at 0 as long as the iterator, `i`, is less than the size minus one, due to iterator indexing at 0.

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
The Selection Sort algorithm iterates through a list of elements and sorts them by setting a variable `min` equal to whatever the lowest value is, then it sets the next lowest index to that value by switching the places of the values at `i` and the next lowest index.

**Implementation**
~~~C++
template <typename T> void selection_sort(T arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}
~~~

**Line by Line Explanation**

`template <typename T> void selection_sort(T arr[], int size) {}`
> Identical function declaration as `bubble_sort`, selection_sort takes in as parameters an array of unknown type, as defined by `T`, and then the Integer size of the array being passed.

`for (int i = 0; i < size - 1; i++) {}`
> Standard for-loop initialization...

```C++
int min = i;
for (int j = i + 1; j < size; j++) {
  if (arr[min] > arr[j]) {
    min = j;
  }
}
int temp = arr[i];
arr[i] = arr[min];
arr[min] = temp;
```
> Set an Integer `min` equal to the iterator `i`. Nested for-loops iterates through the array with an iterator `j` set to the next index that follows `i`, and if the `min` value is greater than what is at the index `j`, set the `min` value to `j`. Afterwards, swap the values of index `i` and index `j`. 

### Insertion Sort
The Insertion sort algorithm iterates through a list of elements and sorts them by beginning at index one of the array as opposed to index zero, stored in the iterator `i`, while an iterator `j` is set to the index to the left of `i`. As the algorithm iterates through the list, it checks whether the item on the left is greater than the current index value, being `i`, and if it is, swaps their places.

**Implementation**
~~~C++
template <typename T> void insertion_sort(T arr[], int size) {
  for (int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}
~~~ 

**Line by Line Explanation**

`template <typename T> void insertion_sort(T arr[], int size) {}`
> Function declaration, similar to all other sorting algorithms. insertion_sort takes in an array of unknown type, defined by `T`, along with the size of this array as an `Integer`.

`for (int i = 1; i < size; i++) {}`
> Standard for-loop initializiation with iterator `i` starting at 1 instead of the standard 0 in order to account for the `size` offset of 1, allowing the next iterator `j` to serve as the iterator handling the values left of the iterator `i`.  

~~~C++
int temp = arr[i];
int j = i - 1;
~~~
> Set a temporary variable, `temp` equal to the value in the array at index `i`. Set the iterator `j` equal to the value of `i` - 1. These variables will be used later.

~~~C++
while (j >= 0 && arr[j] > temp) {
  arr[j + 1] = arr[j];
  j--;
}
~~~
> This while-loop does the bulk of the sorting in the Insertion Sort algorithm. In this while-loop, we are saying that as long as the iterator `j` is greater than 0 and the value in the array at index `j` is greater than the value in the `temp` variable, which represents the value which is to the right of `j`, or at `i`. As long as this is satisfied, we will set the value at index `j+1` equal to the value of the array at index `j`, then we decrement the iterator `j` by one so that we can continue to shift values to the right in order to make space for the `temp` value.

`arr[j + 1] = temp;`
> In the case that j is either no longer greater than or equal to zero, or the value in the array at index `j` is no longer greater than the value of `temp`, set the value in the array at index `j+1` equal to the value we have stored in the `temp` variable. 

### Merge Sort
The Merge Sort algorithm iterates through a list of elements and sorts them by dividing an array into sub-arrays up until there are arrays with only one element in them, then through the use of a separate `merge` function, merges all of the sub-arrays back into the original array.

**Implementation** 
~~~C++
template <typename T> void merge(T left_arr[], T right_arr[], T arr[], int main_arr_size) {
  int left_size = main_arr_size / 2;
  int right_size = main_arr_size - left_size;
  int i = 0, l = 0, r = 0;

  while (l < left_size && r < right_size) {
    if (left_arr[l] < right_arr[r]) {
      arr[i] = left_arr[l];
      i++;
      l++;
    } else {
      arr[i] = right_arr[r];
      i++;
      r++;
    }
  }

  while (l < left_size) {
    arr[i] = left_arr[l];
    i++;
    l++;
  }

  while (r < right_size) {
    arr[i] = right_arr[r];
    i++;
    r++;
  }
}


template <typename T> void merge_sort(T arr[], int length) {
  if (length <= 1) return;

  int main_arr_size = length;
  int middle = length / 2;
  int right_arr_size = length - middle;
  T left_arr[middle];
  T right_arr[right_arr_size];

  int i = 0;
  int j = 0;

  for (; i < length; i++) {
    if (i < middle) {
      left_arr[i] = arr[i];
    } else {
      right_arr[j] = arr[i];
      j++;
    }
  }

  merge_sort(left_arr, middle);
  merge_sort(right_arr, right_arr_size);
  merge(left_arr, right_arr, arr, main_arr_size);
}
~~~

**Line by Line Explanation**

`template <typename T> void merge(T left_arr[], T right_arr[], T arr[], int main_arr_size) {}`
> Function declaration for a function called `merge` that is used at the end of the the `merge_sort` algorithm function. Takes in the left-hand side array of unknown type `left_arr[]`, and the right-hand side array of unknown type `right_arr[]` as parameters, along with the main array that we are sorting, also of unknown type, and lastly the size of the main array we are sorting in the form of an `Integer`.

### Quick Sort

