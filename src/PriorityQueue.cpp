/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */

#include "PriorityQueue.h"
#include "Node.h"

PriorityQueue::PriorityQueue() : head(nullptr) {}

PriorityQueue::~PriorityQueue() {
    Node* last;
    Node* current = head;

    while(current != nullptr){
        last = current;
        current = current->next;
        delete last;
    }
    head = nullptr;
}

bool PriorityQueue::isEmpty() {
    if(head == nullptr){
        return true;
    }
    return false;
}

bool PriorityQueue::enqueue(Customer& cust) {
    if(&cust == nullptr){
        return false;
    }

    if (head == nullptr || cust.getCustArrivalTime() < head->item.getCustArrivalTime()){
        Node* temporaryNode = new Node(cust, head);
        head = temporaryNode;
        return true;
    }

    Node* current = head;
    Node* previous = head;

    while(current != nullptr && (cust.getCustArrivalTime() > current->item.getCustArrivalTime())){
        previous = current;
        current = current->next;
    }

    Node* tempNode = new Node(cust, previous->next);
    previous->next = tempNode;

    return true;
}

void PriorityQueue::dequeue() {
    Node* headNext = head->next;
    delete head;
    head = headNext;
}

Customer PriorityQueue::peekFront() {
    return head->item;
}
