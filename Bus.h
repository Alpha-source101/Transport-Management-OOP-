#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;


template <class T>
class BusData
{
private:
    T data;

public:
    BusData(T d)
    {
        data = d;
    }

    void display()
    {
        cout << "Template Data: " << data << endl;
    }
};

class Bus : public Vehicle // Inheritence 
{
private:
    string* routeAssigned;     // Dynamic Memory
    int totalSeats;

public:
    // Constructor
    Bus(string id,string reg,int cap,string st,string route,int seats);

    // Destructor
    ~Bus();

    // Virtual Function Override
    void displayVehicle() override;

    // Operator Overloading
    bool operator==(const Bus& b);

    // Getter
    int getSeats() const;
};

#endif
