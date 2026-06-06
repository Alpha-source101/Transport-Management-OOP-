#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

class Booking
{
protected:
    int book_ID;
    string book_Date;

public:
    Booking(int, string);
    virtual void displayBooking() = 0;//Pure virtual
    virtual double calculateFee();//virtual function
    virtual ~Booking();
};

#endif
