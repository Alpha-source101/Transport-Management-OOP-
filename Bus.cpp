#include "Bus.h"

// Constructor
Bus::Bus(string id,
         string reg,
         int cap,
         string st,
         string route,
         int seats)
    : Vehicle(id, reg, cap, st)
{
    routeAssigned = new string(route);
    totalSeats = seats;
}

// Destructor
Bus::~Bus()
{
    delete routeAssigned;
}

// Virtual Function Override
void Bus::displayVehicle()
{
    cout << "\n===== BUS DETAILS =====" << endl;

    cout << "Vehicle ID: "
         << vehicleID << endl;

    cout << "Registration Number: "
         << registrationNumber << endl;

    cout << "Capacity: "
         << capacity << endl;

    cout << "Status: "
         << status << endl;

    cout << "Route: "
         << *routeAssigned << endl;

    cout << "Seats: "
         << totalSeats << endl;
}

// Operator Overloading
bool Bus::operator==(const Bus& b)
{
    return totalSeats == b.totalSeats;
}

// Getter
int Bus::getSeats() const
{
    return totalSeats;
}
