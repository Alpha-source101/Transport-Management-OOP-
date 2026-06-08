#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Vehicle.h"
#include "Bus.h"
#include "Route.h"
#include "User.h"
#include "Student.h"
#include "Admin.h"
#include "Driver.h"
#include <string>

class TransportManager
{
private:
    // Pointers Arrays for PolyMorphic Allocation
    Vehicle *vehicles_list[50];
    Route *routes_list[50];
    std::string applications_list[50];

    // Database Counters
    int student_count;
    int vehicle_count;
    int route_count;
    int app_count;

public:
    TransportManager();
    ~TransportManager();

    // Admin Core Operations
    void addvehicle();
    void editvehicle();
    void removevehicle();
    void addroute();
    void editroute();
    void assignvehicletoroute();
    void viewapplications();
    void approverejectrequests();
    void generatereports();

    // File Subsystem Pipelines
    void savedata();
    void loaddata();

    // Student/Public Directory Views
    void showallvehicles();
    void showallroutes();
};

#endif