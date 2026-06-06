#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

// Template Class
template <class T>
class Display
{
public:
    static void show(T data)//static means that the function belongs to the class itself, not to an object of the class.
    {
        cout << data << endl;
    }
};

// Abstract Base Class
class Vehicle
{
protected:
    string veh_ID;
    string reg_no;
    int capacity;
    string status;

public:
    // Constructor
    Vehicle(string id, string reg, int cap, string st);

    // Virtual Destructor
    virtual ~Vehicle();

    // Pure Virtual Function (Makes Vehicle Abstract)
    virtual void displayVehicle() = 0;

    // Operator Overloading
    bool operator>(const Vehicle& v); 

    int getCapacity() const;
};
#endif
