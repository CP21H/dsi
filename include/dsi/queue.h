//
// Created by mrfre on 8/11/2023.
//

#ifndef DSI_QUEUE_H
#define DSI_QUEUE_H
#include <iostream>

template <typename T> class queue {
    public:
    //- Constructor & Destructor
        queue() {
            data = new T[1];
            capacity = 1;
            size = 0;
        }

        ~queue() {
            delete[] data;
        }

    //- Member Functions
    //--> Element access
        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << data[i] << std::endl;
            }
            std::cout << "----" << std::endl;
        }

        T first() {
            return data[0];
        }

        T last() {
            return data[size - 1];
        }

    //--> Capacity
        void empty() {
            if (size == capacity) {
                std::cout << "Queue is not empty." << std::endl;
            } else {
                std::cout << "Queue is empty." << std::endl;
            }
        }

        size_t get_size() const {
            return size;
        }

        size_t get_capacity() const {
            return capacity;
        }

    //--> Modifiers
        void add(T element) {
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
        }

        void remove() {
            for (int i = 0; i <= size; i++) {
                data[i] = data[i+1];
            }
            size--;
        }

    private:
        T* data;
        size_t size;
        size_t capacity;
};


#endif //DSI_QUEUE_H
