#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Student.h"
#include "Admin.h"
#include "Driver.h"
#include "Bus.h"
#include "Van.h"
#include "Route.h"

class TransportManager {
private:
    Student* students_list[50];
    Vehicle* vehicles_list[50];
    Route* routes_list[50];
    string applications_list[50]; // simple array tracking user pending requests
    
    int student_count;
    int vehicle_count;
    int route_count;
    int app_count;

public:
    TransportManager();
    ~TransportManager();

    // core logic functions matching mam menu exactly
    void addvehicle();
    void editvehicle();
    void removevehicle();
    void addroute();
    void assignvehicletoroute();
    void viewapplications();
    void approverejectrequests();
    void generatereports();
    void savedata();
    
    // student view function portal setup
    void studentview();
};
#endif
