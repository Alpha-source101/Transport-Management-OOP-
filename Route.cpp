#include "Route.h"

Route::Route(int id, string start, string end)
{
    routeID = id;
    startPoint = start;
    endPoint = end;
}

double Route::calculateFare()
{
    return 0;
}

Route::~Route()
{
}
/*
                <<Abstract>>
                +------------------+
                |      Route       |
                +------------------+
                | # routeID : int  |
                | # startPoint     |
                | # endPoint       |
                +------------------+
                | + Route()        |
                | + displayRoute() = 0 |
                | + calculateFare()|
                | + ~Route()       |
                +------------------+
                         ▲
                         |
                         |
                Inheritance
                         |
                         |
                +------------------+
                |    BusRoute      |
                +------------------+
                | - distance:double|
                +------------------+
                | + BusRoute()     |
                | + displayRoute() |
                | + calculateFare()|
                +------------------+ */
