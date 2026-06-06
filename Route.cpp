#include "Route.h"

// Constructor
Route::Route(string id,
             string start,
             string end,
             double dist)
{
    routeID = id;
    startPoint = start;
    endPoint = end;
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
    cout << "\n===== ROUTE DETAILS =====" << endl;

    cout << "Route ID: "
         << routeID << endl;

    cout << "Start Point: "
         << startPoint << endl;

    cout << "End Point: "
         << endPoint << endl;

    cout << "Distance: "
         << distance << " KM" << endl;

    cout << "Main Stop: "
         << *stopName << endl;
}
