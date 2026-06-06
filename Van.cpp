#include "Van.h"

// Constructor
Van::Van(string id,
         string reg,
         int cap,
         string st,
         string route,
         int seats)
    : Vehicle(id, reg, cap, st)
{
    // Dynamic Memory Allocation
    routeAssigned = new string(route);

    totalSeats = seats;
}

// Destructor
Van::~Van()
{
    // Free Dynamic Memory
    delete routeAssigned;
}

// Overridden Virtual Function
void Van::displayVehicle()
{
    cout << "\n===== VAN DETAILS =====" << endl;

    cout << "Vehicle ID: "
         << vehicleID << endl;

    cout << "Registration Number: "
         << registrationNumber << endl;

    cout << "Capacity: "
         << capacity << endl;

    cout << "Status: "
         << status << endl;

    cout << "Route Assigned: "
         << *routeAssigned << endl;

    cout << "Total Seats: "
         << totalSeats << endl;
}

// Operator Overloading
bool Van::operator<(const Van& v)
{
    return totalSeats < v.totalSeats;
}

// Getter Function
int Van::getSeats() const
{
    return totalSeats;
}
