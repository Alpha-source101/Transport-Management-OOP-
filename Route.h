#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
using namespace std;

class Route
{
protected: // protected members ko derived class ma bhi access karsakta hain.
    int routeID;
    string startPoint;
    string endPoint;

public:
    Route(int id, string start, string end);

    virtual void displayRoute() = 0;   // Pure Virtual Function

    virtual double calculateFare();    // Virtual Function

    virtual ~Route();
};

#endif
