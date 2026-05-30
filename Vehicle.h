#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
protected:
    string veh_Id;
    string veh_Type;
    int veh_capacity;

public:
    Vehicle(string id, string type, int cap);

    virtual void displayVehicle(); // virtual taake Bus override kar sake
    virtual double calculateFare(double distance); // fare calculate karne ke liye

    string getVehicleId(); //getter lagaye hain kiu ka entities protectedd hain.
    int getCapacity();
     virtual ~Vehicle(); //virtual is used to enable runtime polymorphism.

};
#endif
