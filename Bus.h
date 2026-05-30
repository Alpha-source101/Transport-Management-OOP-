#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"
#include <string>
using namespace std;

class Bus : public Vehicle {  // public inheritance
private:
    string bus_Number;
    string route_Name;
    

public:
    Bus(string id, string type, int cap, string bNo, string rName);
    
    void displayVehicle() override; // override base function
    double calculateFare(double distance) override; // AC bus ka fare zyada

    void setRoute(string rName);
    string getRoute();
};
#endif
