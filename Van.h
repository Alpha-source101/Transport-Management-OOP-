#ifndef VAN_H
#define VAN_H

#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;

// Template Class
template <class T>
class VanData
{
private:
    T data;

public:
    VanData(T d)
    {
        data = d;
    }

    void display()
    {
        cout << "Template Data: " << data << endl;
    }
};

// Derived Class
class Van : public Vehicle
{
private:
    string* routeAssigned;     // Dynamic Memory
    int totalSeats;

public:
    // Constructor
    Van(string id, string reg, int cap, string st, string route, int seats);

    // Destructor
    ~Van();

    // Virtual Function Override
    void displayVehicle() override;
    bool operator<(const Van& v);
    int getSeats() const;
};

#endif
