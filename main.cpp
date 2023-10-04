//
// Created by Cristhian Prado on 8/13/2023.
//

#include <iostream>
#include "include/dsi/algorithms.h"
#include "include/dsi/vector.h"
#include "include/dsi/stack.h"
#include "include/dsi/queue.h"
#include "include/dsi/priority_queue.h"

int main() {
    //priority_queue<priority_queue_item> pq;
    //
    //    // Add elements with priorities
    //    pq.add(1, 10);
    //    pq.add(17, 1);
    //    pq.add(99, 2);
    //    pq.add(55, 2);
    //    pq.add(12, 1);
    //
    //    std::cout << "Priority Queue Size: " << pq.get_size() << std::endl;
    //    std::cout << "Priority Queue Capacity: " << pq.get_capacity() << std::endl;
    //
    //    std::cout << "Priority Queue Contents:" << std::endl;
    //    pq.print();

    int a[] = {10,11,12,45,63,32,3,9,10,23,27,1,34,12};
    int length = 14;

    algorithms::merge_sort(a, length);

    for (int i = 0; i < length; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}