//
// Created by mrfre on 8/11/2023.
//

#ifndef DSI_PRIORITY_QUEUE_H
#define DSI_PRIORITY_QUEUE_H
#include <iostream>

class priority_queue_item {
    public:
        priority_queue_item() {

        }
        priority_queue_item(int v, int p) {
            value = v;
            priority = p;
        };
        int value;
        int priority;
};

template <typename T> class priority_queue {
    public:
    //- Constructor & Destructor
        priority_queue() {
            data = new T[1];
            capacity = 1;
            size = 0;
        }

        ~priority_queue() {
            delete[] data;
        }

    //- Member Functions
    //--> Element access
        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << "Element: " << data[i].value << ", Priority: " << data[i].priority << std::endl;
            }
            std::cout << "----" << std::endl;
        }

        T first() {
            return data[0];
        }

    //--> Capacity
        void empty() {
            if (size == capacity) {
                std::cout << "Priority Queue is not empty." << std::endl;
            } else {
                std::cout << "Priority Queue is empty." << std::endl;
            }
        }

        size_t get_size() const {
            return size;
        }

        size_t get_capacity() const {
            return capacity;
        }

    //--> Modifiers
        void add(int element, int priority) {
            if (size == capacity) {
                capacity *= 2;
                T* temp = new T[capacity];
                for (size_t i = 0; i < size; i++) {
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
            }

            size_t index = size;
            while (index > 0 && data[index - 1].priority < priority) {
                data[index] = data[index - 1];
                index--;
            }
            data[index] = priority_queue_item(element, priority);
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


#endif //DSI_PRIORITY_QUEUE_H
