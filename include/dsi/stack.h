//
// Created by mrfre on 8/11/2023.
//

#ifndef DSI_STACK_H
#define DSI_STACK_H
#include <iostream>

template <typename T> class stack {
    public:
    //- Constructor & Destructor
        stack() {
            data = new T[1];
            capacity = 1;
            size = 0;
        }

        ~stack() {
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

        T top() {
            return data[0];
        }

    //--> Capacity
        size_t get_size() const {
            return size;
        }

        void empty() {
            if (size == capacity) {
                std::cout << "Stack is not empty." << std::endl;
            } else {
                std::cout << "Stack is empty." << std::endl;
            }
        }

    //--> Modifiers
        void add(T element) {
            T* temp = new T[capacity + 1];

            for (int i = 0; i < capacity; i++) {
                temp[i+1] = data[i];
            }

            temp[0] = element;
            size++;
            delete[] data;
            capacity++;
            data = temp;
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


#endif //DSI_STACK_H
