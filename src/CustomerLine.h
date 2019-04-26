/**
 * CSC232 - Data Structures with C++
 * Missouri State University, Spring 2019
 *
 * Authors  Deric Williamson <Deric123@live.missouristate.edu>
 */


#ifndef HW06_CUSTOMERLINE_H
#define HW06_CUSTOMERLINE_H


class Customer{
private:
    int custArrivalTime;
    int custServiceLength;

public:
    Customer();
    Customer(int custArriveTime, int custServeTime);
    ~Customer();

    void setCustArrivalTime(int custArriveTime);
    int getCustArrivalTime();

    void setCustServiceLength(int custServeTime);
    int getCustServiceLength();
};


#endif //HW06_CUSTOMERLINE_H
