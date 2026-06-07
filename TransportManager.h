#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Student.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Van.h"
#include "Route.h"
#include <string>

class TransportManager
{
private:
    Student *students_list[50];
    Vehicle *vehicles_list[50];
    UniversityRoute *routes_list[50];
    std::string applications_list[50];

    int student_count;
    int vehicle_count;
    int route_count;
    int app_count;

public:
    TransportManager();
    ~TransportManager();

    void addvehicle();
    void editvehicle();
    void removevehicle();
    void addroute();
    void editroute();
    void assignvehicletoroute();
    void viewapplications();
    void approverejectrequests();
    void generatereports();

    // FIX: Yeh declarations zaroori theen taqe compile ho sakay
    void savedata();
    void loaddata();

    void showallstudents();
    void showallvehicles();
    void showallroutes();
};

#endif