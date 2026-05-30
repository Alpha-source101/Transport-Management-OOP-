#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Passenger : public Person
{
protected:
    int passengerid;
    string pickuppoint;
    string destination;
    int transportfee;
public:
    Passenger();

    // Parameterized Constructor
    Passenger(string n, int a, string ph,string c,
              int id, string pickup, string dest,int t);             

    void setpassengerid(int id);          //set karny ka lya values
    void setpickuppoint(string pickup);
    void setdestination(string dest);
      void settransportfee(int t);

int getpassengerid();           //single retreive ka lya 
    string getpickuppoint();
    string getdestination();
      int gettransportfee();
    
    void inputpassenger();    //input all
    virtual void calculatetransportfee(int distance);
    void display() override;             //display kary ga all      ----> its override used
    virtual ~Passenger();
};
#endif

