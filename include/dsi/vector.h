//
// Created by mrfre on 8/11/2023.
//

#ifndef DSI_VECTOR_H
#define DSI_VECTOR_H
#include <iostream>

template <typename T> class vector {
    public:
    //- Constructor & Destructor
        vector() {
            data = new T[1];
            capacity = 1;
            size = 0;
        }

        ~vector() {
            delete[] data;
        }

    //- Member Functions
    //--> Capacity
        size_t get_size() const {
            return size;
        }

        size_t get_capacity() const {
            return capacity;
        }

        void empty() {
            if (size == capacity) {
                std::cout << "Vector is not empty." << std::endl;
            } else {
                std::cout << "Vector is empty." << std::endl;
            }
        }

        void resize(size_t new_size) {
            size = new_size;

            if (size == capacity) {
                T* temp = new T[new_size];

                for (int i = 0; i < capacity; i++) {
                    temp[i] = data[i];
                }

                delete[] data;
                data = temp;
            }
            capacity = new_size + 1;
        }

        //--> Element access
        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << data[i] << "\n";
            }
            std::cout << "----" << std::endl;
        }

        void at(int index) {
            if (index < size && index >= 0) {
                std::cout << data[index];
            }
        }

        T front() {
            return data[0];
        }

        T back() {
            return data[size - 1];
        }

    //--> Modifiers
        void add_back(T element) {
            if (size == capacity) {
                T* temp = new T[2 * capacity];

                for (int i = 0; i < capacity; i++) {
                    temp[i] = data[i];
                }

                delete[] data;
                capacity *= 2;
                data = temp;
            }

            data[size] = element;
            size++;
        };

        void add_at(T element, int index) {
            if (index == capacity) {
                add_back(element);
            } else {
                //1. Increase the size of the array by one.
                //--> probably going to have to create a new array with +1 size then copy over everything
                //2. for-loop starting at the end of the array, moving all items back one up until it reaches / equals the point where we want to add the new element.
                //3. add the new element at that index

                for (int i = size; i > index; i--) {
                    data[i] = data[i-1];
                }
                data[index] = element;
                size++;
            }
        }

        void remove(int index) {
            for (int i = index; i <= size; i++) {
                data[i] = data[i+1];
            }
            size--;
        }

        void swap(int first_index, int sec_index) {
            T temp = data[first_index];
            data[first_index] = data[sec_index];
            data[sec_index] = temp;
        }

        void reverse() {
            T temp;

            for (int i = 0, j = size - 1; i < j; i++, j--) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }

    private:
        T* data;
        size_t size;
        size_t capacity;
};


#endif //DSI_VECTOR_H
