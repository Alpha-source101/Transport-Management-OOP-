#include "Route.h"
// Constructor
Route::Route(string id,
             string start,
             string end,
             double dist)
{
    route_ID = id;       
    start_Point = start; 
    end_Point = end;     
    distance = dist;
}

// Virtual Destructor
Route::~Route()
{
}

// Operator Overloading
bool Route::operator>(const Route& r)
{
    return distance > r.distance;
}

// Getter
double Route::getDistance() const
{
    return distance;
}

// Derived Class Constructor
UniversityRoute::UniversityRoute(string id,
                                 string start,
                                 string end,
                                 double dist,
                                 string stop)
    : Route(id, start, end, dist)
{
    stopName = new string(stop);
}

// Destructor
UniversityRoute::~UniversityRoute()
{
    delete stopName;
}

// Overridden Virtual Function
void UniversityRoute::displayRoute()
{
    cout << "\n=====[ ROUTE DETAILS ]=====" << endl;

    cout << "Route ID: "
         << route_ID << endl; 

    cout << "Start Point: "
         << start_Point << endl; 

    cout << "End Point: "
         << end_Point << endl; 

    cout << "Distance: "
         << distance << " KM" << endl;

    cout << "Main Stop: "
         << *stopName << endl;
}
