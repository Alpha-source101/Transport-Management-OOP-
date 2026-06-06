#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Student.h"
#include "Bus.h"
#include "Van.h"
#include "Route.h"
#include "TransportPass.h"

class TransportManager {
private:
    Student* students_list[50];
    Vehicle* vehicles_list[50];
    Route* routes_list[50];
    TransportPass* passes_list[50];
    
    int student_count;
    int vehicle_count;
    int route_count;
    int pass_count;

public:
    TransportManager();
    ~TransportManager();

    void addstudent();
    void addbus();
    void addvan();
    void addroute();
    void issuepass();

    void showallstudents();
    void showallvehicles();
    void showallroutes();
    void showallpasses();
};

#endif
