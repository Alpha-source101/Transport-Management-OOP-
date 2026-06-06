#include "Booking.h"

Booking::Booking(int id, string date)
{
    book_ID = id;
    book_Date = date;
}

double Booking::calculateFee()
{
    return 0;
}

Booking::~Booking()
{
}
/*
                 <<Abstract>>
             +--------------------+
             |      Booking       |
             +--------------------+
             | # bookingID : int  |
             | # bookingDate:str  |
             +--------------------+
             | + Booking()        |
             | + displayBooking()=0 |
             | + calculateFee()   |
             | + ~Booking()       |
             +--------------------+
                       ▲
                       |
                       |
             +--------------------+
             |  StudentBooking    |
             +--------------------+
             | - seatNumber : int |
             | - fee : double     |
             +--------------------+
             | + StudentBooking() |
             | + displayBooking() |
             | + calculateFee()   |
             +--------------------+
*/
