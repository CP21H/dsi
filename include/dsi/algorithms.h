//
// Created by Cristhian Prado on 8/11/2023.
//

#ifndef DSI_ALGORITHMS_H
#define DSI_ALGORITHMS_H
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace algorithms {
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
    };

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
    };

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

    //- MERGE SORT FUNCTIONS
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

    //- QUICK SORT FUNCTIONS
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
}

#endif //DSI_ALGORITHMS_H
