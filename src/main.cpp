/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"


void populatePriorityQueue(PriorityQueue &queue){
    int time;
    int length;
    //std::string inFile = "input.txt";

    std::ifstream infile;
    infile.open("input.txt");

    if (infile.fail()){
        std::cout<<"File input fail";
        exit(EXIT_FAILURE);
    }

    while (infile >> time >> length){
        Customer cust(time,length);
        queue.enqueue(cust);
    }
}

int main() {
    PriorityQueue bankQueue;

    populatePriorityQueue(bankQueue);

    std::queue<int> qArrivalTimes;
    std::queue<int> qDepartureTimes;
    int arrivalTime = 0;
    int LastDepartureTime = 0;
    int serviceTime = 0;
    int waitTime;
    int customerCounter = 0;

    double waitCounter = 0;

    std::cout << "Simulation Begins" << std::endl;
    while (!bankQueue.isEmpty()){
        customerCounter++;

        Customer Front = bankQueue.peekFront();
        arrivalTime = Front.getCustArrivalTime();
        qArrivalTimes.push(arrivalTime);


        serviceTime = Front.getCustServiceLength();

        waitTime = LastDepartureTime - arrivalTime;
        if(waitTime < 0)
            waitTime = 0;
        //std::cout << waitTime << std::endl;
        waitCounter += waitTime;

        LastDepartureTime = arrivalTime + waitTime + serviceTime;
        qDepartureTimes.push(LastDepartureTime);

        bankQueue.dequeue();

    }

    while(!qDepartureTimes.empty()) {
        if (!qArrivalTimes.empty() && !qDepartureTimes.empty()) {
            if (qArrivalTimes.front() < qDepartureTimes.front()) {
                std::cout << "Processing an arrival event at time:       " << qArrivalTimes.front() << std::endl;
                qArrivalTimes.pop();
            } else{
                std::cout << "Processing an departure event at time:     " << qDepartureTimes.front() << std::endl;
                qDepartureTimes.pop();
            }
        }
        else if (!qArrivalTimes.empty() && qDepartureTimes.empty()){
            std::cout << "Processing an arrival event at time:       " << qArrivalTimes.front() << std::endl;
            qArrivalTimes.pop();

        }
        else if (qArrivalTimes.empty() && !qDepartureTimes.empty()){
            std::cout << "Processing an departure event at time:     " << qDepartureTimes.front() << std::endl;
            qDepartureTimes.pop();
        }
    }

    std::cout << "Simulation Ends" << std::endl << std::endl;
    std::cout << "Final Statistics:" << std::endl << std::endl;



    std::cout << "    Total number of people processed: " << customerCounter << std::endl;
    std::cout << "    Average amount of time spent waiting: " << waitCounter/customerCounter << std::endl;
    return 0;
}