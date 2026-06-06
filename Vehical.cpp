#include "Vehicle.h"
Vehicle::Vehicle(string id, string reg, int cap, string st)
{
    veh_ID = id;
    reg_no = reg;
    capacity = cap;
    status = st;
}

Vehicle::~Vehicle() // Ya virtual destructor ha 
{
}

// Operator Overloading
bool Vehicle::operator>(const Vehicle& v)
{
    return capacity > v.capacity;
}

int Vehicle::getCapacity() const
{
    return capacity;
}
