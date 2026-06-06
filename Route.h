#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
using namespace std;

// Template Class
template <class T>
class RouteData
{
private:
    T data;

public:
    RouteData(T d)
    {
        data = d;
    }

    void display()
    {
        cout << "Route Data: " << data << endl;
    }
};

// Abstract Base Class
class Route
{
protected:
    string route_ID;
    string start_Point;
    string end_Point;
    double distance;

public:
    Route(string id ,string start,string end,double dist);

    virtual ~Route();

    // Pure Virtual Function
    virtual void displayRoute() = 0;

    // Operator Overloading
    bool operator>(const Route& r);

    double getDistance() const;
};

#endif
