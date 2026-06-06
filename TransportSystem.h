#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include <iostream>
#include <string>
using namespace std;

class TransportSystem
{
protected:
    string system_Name;
    int total_Routes;
    int total_Bookings;

public:
    TransportSystem(string, int, int);

    virtual void displaySystem() = 0;//Pure virtual

    virtual void generateReport();//Virtual

    virtual ~TransportSystem();
};

#endif
