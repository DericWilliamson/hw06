/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */

#ifndef HW06_PRIORITYQUEUE_H
#define HW06_PRIORITYQUEUE_H

#include "CustomerLine.h"
#include "Node.h"

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue();
    ~PriorityQueue();
    bool isEmpty();
    bool enqueue(Customer& cust);
    void dequeue();
    Customer peekFront();
};


#endif //HW06_PRIORITYQUEUE_H
