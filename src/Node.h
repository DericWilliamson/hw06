/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */


#ifndef HW06_NODE_H
#define HW06_NODE_H

#include "CustomerLine.h"


class Node {
public:
    Customer item;
    Node* next;
    Node();
    Node(const Customer& anItem);
    Node(const Customer& anItem, Node* nextNodePtr);
    ~Node();

};


#endif //HW06_NODE_H
