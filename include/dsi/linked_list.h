//
// Created by mrfre on 8/11/2023.
//

#ifndef DSI_LINKED_LIST_H
#define DSI_LINKED_LIST_H
#include <iostream>

template <typename T> class Node {
    public:
        T data;
        Node* next;

        //- Constructors
        Node() {
            data = 0;
            next = NULL;
        }

        Node(T data) {
            this->data = data;
            this->next = NULL;
        }
};


template <typename T> class linked_list {
    Node<T>* head;

    public:
        //- Constructors
        linked_list() { head = NULL; }

        //- Public Member Functions
        void insert_node(T data) {
            Node<T>* newNode = new Node<T>(data);

            if (head == NULL) {
                head = newNode;
                return;
            }

            Node<T>* i = head;  // treated as an iterator through the linked list
            while (i->next != NULL) {
                i = i->next;
            }
            i->next = newNode;
        }

        void delete_node(int nodeOffset) {
            Node<T> *i = head, *j = NULL;
            int length = 0;

            if (head == NULL) {
                std::cout << "List empty" << std::endl;
                return;
            }

            while (i != NULL) {
                i = i->next;
                length++;
            }

            if (length < nodeOffset) {
                std::cout << "Index out of range" << std::endl;
                return;
            }

            i = head;
            if (nodeOffset == 1) {
                head = head->next;
                delete i;
                return;
            }

            while (nodeOffset-- > 1) {
                j = i;
                i = i->next;
            }
            
            j->next = i->next;
            delete i;
        }

        void print() {
            Node<T>* i = head;

            if (head == NULL) {
                std::cout << "List empty" << std::endl;
                return;
            }

            while (i != NULL) {
                std::cout << i->data << " ";
                i = i->next;
            }
        }
};


#endif //DSI_LINKED_LIST_H
