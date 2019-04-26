/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */

#include "CustomerLine.h"

Customer::Customer(){}

Customer::Customer(int custArriveTime, int custServeTime)
        : custArrivalTime(custArriveTime),custServiceLength(custServeTime) {}

Customer::~Customer() {}

void Customer::setCustArrivalTime(int custArriveTime) {
    custArrivalTime = custArriveTime;
}

int Customer::getCustArrivalTime() {
    return custArrivalTime;
}

void Customer::setCustServiceLength(int custServeTime) {
    custServiceLength = custServeTime;
}

int Customer::getCustServiceLength() {
    return custServiceLength;
}
#include "CustomerLine.h"