/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */

#include "Node.h"

Node::Node() : next(nullptr){}

Node::Node(const Customer &anItem) : item(anItem), next(nullptr) {}

Node::Node(const Customer &anItem, Node* nextNodePtr)
        : item(anItem), next(nextNodePtr) {}

Node::~Node() {}