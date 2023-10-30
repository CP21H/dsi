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

~~~C++
int left_size = main_arr_size / 2;
int right_size = main_arr_size - left_size;
int i = 0, l = 0, r = 0;
~~~
> Here we are setting two `Integer` variables, `left_size` and `right_size`. The `left_size` variable takes the size of the main array, in `main_arr_size`, and divides it by two to get half the number of elements total. To get the size of the right array, we take `main_arr_size` and substract `left_size` from it to get the remaining number of items. This is parallel to how the left and right arrays are made in the `merge_sort` function, where the left array takes the floored value of the main array size divided by 2, and the right array takes the size of either half of the main array or half + 1, to make up for odd numbers.

> We are also setting `Integers: i, l,` and `r` equal to 0, since these will be iterators for the main array, left array (l), and right array (r).

` while (l < left_size && r < right_size) {}`
> While-loop which loops as long as we have not iterated through all of the elements in the left array and we haven't iterated through all of the elements in the right array. `l` represents the iterator tied to the left array, and `r` stands for the iterator tied to the right array.

~~~C++
if (left_arr[l] < right_arr[r]) {
  arr[i] = left_arr[l];
  i++;
  l++;
}
~~~
> If the element in the left array at index `l` is less than the item in the right array at index `r`, we will set the value of the main array at index `i` equal to the left array value at index `l`. We will then increment `i` to continue on to the next available spot to merge elements back into, and also increment `l` to move onto the next left array value since we just placed one value from it back into the main array

~~~C++
else {
  arr[i] = right_arr[r];
  i++;
  r++;
}
~~~
> Here, we are doing the same thing as the if-statement tied to this else-statement, but for every case where the right array value happens to be less than the left array value at index `l` and `r` respectively.  

~~~C++
while (l < left_size) {
  arr[i] = left_arr[l];
  i++;
  l++;
}
~~~
> One of two while-loops that iterates through the remaining items in a respective array-side to "clean up" any remaining elements that were not brought in from the previous while-loop, meaning that the condition of one array being iterated over entirely was met. This while-loop specifically adds the remaining elements in the left array over to the main array, implying that the right array was iterated over entirely. 

~~~C++
while (r < right_size) {
  arr[i] = right_arr[r];
  i++;
  r++;
}
~~~
> Adds the remaining elements in the right array over to the main array, implying that the left array was iterated over entirely. 

### Quick Sort
The Quick Sort algorithm iterates through a list of elements and sorts them by selecting a `pivot-point` in the array we are sorting, usually the last element in the array. The algorithm then sorts the array by creating sections of the array that revolve around the pivot, meaning that on the left side will be unsorted elements that are all less than the pivot, and on the right, we will have unsorted elements larger than the pivot value. This process continues recursively in the quick_sort function itself. Below is a visualization, numbers within brackets [] represent the pivot.

**Visualization**
~~~
6 3 7 5 1 2 [4]
             |
     3 1 [2] 4 6 7 [5]
          |         |
        1 2 3       5 7 [6]
                         |
                         6 7
~~~

**Implementation** 
~~~C++
template <typename T> int partition (T arr[], int const start, int const end) {
  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j <= end; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  i++;
  int temp = arr[i];
  arr[i] = arr[end];
  arr[end] = temp;

  return i;
}

template <typename T> void quick_sort(T arr[], int const start, int const end) {
  if (end <= start) return;

  int pivot = partition(arr, start, end);
  quick_sort(arr, start, pivot - 1);
  quick_sort(arr, pivot + 1, end);
}
~~~

**Line by Line Explanation**

`template <typename T> int partition (T arr[], int const start, int const end) {}`
> Function declaration for a function called `partition` of return type `Integer`. This function takes in as parameters an array of unknown type, represented as `T`, along with two `Integers` of an index `start` and an index `end`. This `partition` function serves the purpose of "partitioning" elements within the array passed in as they relate to the `pivot`, partitioning the array into a side less than, and a side greater than, the `pivot`.

`int pivot = arr[end];`
> Set the `pivot`, the value we will partition our array relative to, equal to the last element of the array, represented by index `end`. It should be noted that this variable is used to represent the **value** of the pivot we are starting off with, and another `Integer` used later on will serve as the *actual* pivot that is used in the next iteration of quick_sort.

`int i = start - 1;`
> `i` is initialized to be one less than the starting index. `i` will be used to keep track of the index where elements less than the `pivot` should be placed.

`for (int j = start; j <= end; j++) {}`
> for-loop starting at the starting index, `int j = start;`, to the ending index, `j <= end;`, iterating throughout the entire array. This for-loop continues until all elements in the range `start` to `end` are partitioned based on their relationship to the pivot. 

~~~C++
if (arr[j] < pivot) {
  i++;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
~~~
> If at some point in the array the value of the element at index `j` is less than the value of the `pivot`, then we will increment `i` to move the `pivot` position, since `i` represents the new `pivot`. We then swap the elements of `j` and `i`.

~~~C++
i++;
int temp = arr[i];
arr[i] = arr[end];
arr[end] = temp;

return i;
~~~
> Move the `pivot` element to its final sorted position by swapping it with the element at the `i` index. Then return the index of the pivot element, which we will then use to divide the array into two subarrays in the quicksort function. 

`template <typename T> void quick_sort(T arr[], int const start, int const end) {}`
> Function declaration for the main quick sort algorithm. This function takes in as parameters an array of unknown type, denoted by `T`, a constant `Integer` index `start` and a constant `Integer` index `end`, denoting the start and end of the array respectively. 

`if (end <= start) return;`
>  Base case of the quick sort algorithm. If the range to be sorted consists of one or zero elements, the function returns as there's no need to sort further. 

`int pivot = partition(arr, start, end);`
> We set an `Integer` `pivot` equal to a function call of `partition` from the range `start` to `end`. This is how we find the index of the `pivot`.

`quick_sort(arr, start, pivot - 1);`
> The `quick_sort` function calls itself recursively on the subarray before the pivot.

`quick_sort(arr, pivot + 1, end);`
> The `quick_sort` function calls itself recursively on the subarry after the pivot.

---

## Linked List 
The `linked_list` class replicates the workings of a singly-linked list, meaning that each `Node` in it, stores both data and an address pointer to the next `Node`, whereas a doubly-linked list would have both an address to the _next_ node and the node _before_ the current node. Linked-lists are easier to insert into and delete out of than a standard array. This is done through the way linked-lists handle storage. Individual elements or `Nodes`, instead of taking up the next space in memory, are organized across memory in relation to a previous node; in the case of singly-linked lists. 

Linked-lists generally waste no to little memory but tend to overall have a greater memory usage. A slight disadvantage of them is also that accessing and searching is more time consuming, with a time complexity of O(n), whereas accessing an array has time complexity of O(1) to O(log n), both being faster time complexities than O(n). 

**Visualization**
~~~
     Node                Node                Node
[data | address] -> [data | address] -> [data | address]
~~~

**Implementation** 
[Implementation Link](https://github.com/CP21H/dsi/blob/main/include/dsi/linked_list.h)

**Line by Line Explanation**

`template <typename T> class Node {}`
> write description for node class which is used as indexs in the linked list, storing data, and address of next item
