#include "Bus.h"

Bus::Bus(string id, string type, int cap, string bNo, string rName) : Vehicle(id, type, cap),bus_Number(bNo), route_Name(rName){}

void Bus::displayVehicle() {
    Vehicle::displayVehicle(); // ya base class ka data print kare ga
    cout << "Bus Number: " << bus_Number << endl;
    cout << "Route: " << route_Name << endl;
    
}

double Bus::calculateFare(double distance) {
    double baseFare = Vehicle::calculateFare(distance); // 5 per km
    
}

void Bus::setRoute(string rName)
 {
     route_Name = rName;
 }
string Bus::getRoute()
 { 
    return route_Name;
 }
