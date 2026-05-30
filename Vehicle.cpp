#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string id, string type, int cap)
    : veh_Id(id), veh_Type(type), veh_capacity(cap) {}

Vehicle::~Vehicle() {}

void Vehicle::displayVehicle() {
    cout << "Vehicle ID: " << veh_Id << endl;
    cout << "Type: " << veh_Type << endl;
    cout << "Capacity: " << veh_capacity << endl;
}

double Vehicle::calculateFare(double distance) {
    return distance *20; // fare can be set of any amount. 
}

string Vehicle::getVehicleId() 
{ 
    return veh_Id;
 }
int Vehicle::getCapacity() 
{ 
    return veh_capacity;
 }
