#include "TransportManager.h"
#include <iostream>
using namespace std;
TransportManager::TransportManager() {
    student_count = 0;
    vehicle_count = 0;
    route_count = 0;
    pass_count = 0;
}
TransportManager::~TransportManager() {
                                          // clean up pointer arrays memory leakage protection
    for(int i = 0; i < student_count; i++) { delete students_list[i]; }
    for(int i = 0; i < vehicle_count; i++) { delete vehicles_list[i]; }
    for(int i = 0; i < route_count; i++) { delete routes_list[i]; }
    for(int i = 0; i < pass_count; i++) { delete passes_list[i]; }
}
void TransportManager::addstudent() {
    if(student_count < 50) {
        students_list[student_count] = new Student();
        students_list[student_count]->inputstudent();
        student_count++;
    }
}

void TransportManager::addbus() {
    if(vehicle_count < 50) {
        // dummy instantiation parameters for safe testing allocation
        vehicles_list[vehicle_count] = new Bus("b1", "lh-123", 50, "active", "route-a", 50);
        vehicles_list[vehicle_count]->displayVehicle();
        vehicle_count++;
    }
}

void TransportManager::addvan() {
    if(vehicle_count < 50) {
        vehicles_list[vehicle_count] = new Van("v1", "lh-789", 15, "active", "route-b", 15);
        vehicles_list[vehicle_count]->displayVehicle();
        vehicle_count++;
    }
}

void TransportManager::addroute() {
    if(route_count < 50) {
        routes_list[route_count] = new UniversityRoute("r1", "uet", "anarkali", 12.5, "rn-stop");
        routes_list[route_count]->displayRoute();
        route_count++;
    }
}

void TransportManager::issuepass() {
    if(pass_count < 50) {
        passes_list[pass_count] = new TransportPass();
        passes_list[pass_count]->inputpass();
        pass_count++;
    }
}

void TransportManager::showallstudents() {
    cout << "\n--- system students database view ---" << endl;
    for(int i = 0; i < student_count; i++) {
        students_list[i]->display();
    }
}

void TransportManager::showallvehicles() {
    cout << "\n--- transport fleet database view ---" << endl;
    for(int i = 0; i < vehicle_count; i++) {
        vehicles_list[i]->displayVehicle();
    }
}
void TransportManager::showallroutes() {
    cout << "\n--- map grid paths view ---" << endl;
    for(int i = 0; i < route_count; i++) {
        routes_list[i]->displayRoute();
    }
}
void TransportManager::showallpasses() {
    cout << "\n--- issued cards listing view ---" << endl;
    for(int i = 0; i < pass_count; i++) {
        passes_list[i]->displaypass();
    }
}
