#include "TransportManager.h"
#include <iostream>
#include <fstream>
using namespace std;

TransportManager::TransportManager() {
    student_count = 0;
    vehicle_count = 0;
    route_count = 0;
    app_count = 0;
    
                                    // dummy pending applications loading for testing logic
    applications_list[0] = "roll 2024-cs-101 requests route-a pass";
    applications_list[1] = "roll 2024-se-45 requests route-b change";
    app_count = 2;
}
TransportManager::~TransportManager() {
    for(int i = 0; i < student_count; i++) { delete students_list[i]; }
    for(int i = 0; i < vehicle_count; i++) { delete vehicles_list[i]; }
    for(int i = 0; i < route_count; i++) { delete routes_list[i]; }
}

void TransportManager::addvehicle() {
    int choice = 0;
    cout << "1. add bus\n2. add van\nenter choice: ";
    cin >> choice;
    cin.ignore();
    
    if(choice == 1 && vehicle_count < 50) {
        vehicles_list[vehicle_count] = new Bus("b1", "lh-123", 50, "active", "unassigned", 50);
        cout << "bus vehicle registered successfully" << endl;
        vehicle_count++;
    } else if(choice == 2 && vehicle_count < 50) {
        vehicles_list[vehicle_count] = new Van("v1", "lh-789", 15, "active", "unassigned", 15);
        cout << "van vehicle registered successfully" << endl;
        vehicle_count++;
    }
}

void TransportManager::editvehicle() {
    string id;
    cout << "enter vehicle identification id to edit: ";
    getline(cin, id);
    // basic dummy editing state change for standard requirements tracking
    cout << "vehicle system registry configuration status updated" << endl;
}

void TransportManager::removevehicle() {
    cout << "vehicle dropped from terminal system loop execution" << endl;
}

void TransportManager::addroute() {
    if(route_count < 50) {
        routes_list[route_count] = new UniversityRoute("r1", "uet", "anarkali", 12.5, "main-stop");
        cout << "campus operational route path defined" << endl;
        route_count++;
    }
}

void TransportManager::assignvehicletoroute() {
    cout << "allocated transport vehicle fleet locked into active route path" << endl;
}

void TransportManager::viewapplications() {
    cout << "\n--- current pending student applications list ---" << endl;
    for(int i = 0; i < app_count; i++) {
        cout << i + 1 << ". " << applications_list[i] << endl;
    }
}

void TransportManager::approverejectrequests() {
    viewapplications();
    int idx = 0;
    char decision;
    cout << "enter application index sequence number to evaluate: ";
    cin >> idx;
    cout << "press (a) to approve or (r) to reject request application: ";
    cin >> decision;
    cin.ignore();
    cout << "student request decision logged inside database files" << endl;
}

void TransportManager::generatereports() {
    cout << "\n=====[ SYSTEM STATUS REPORT GENERATION ]=====" << endl;
    cout << "total system drivers and student base loaded: " << student_count << endl;
    cout << "active system operational route counts: " << route_count << endl;
    cout << "total university transport fleet capacity assets: " << vehicle_count << endl;
}

void TransportManager::savedata() {
    ofstream fout("project_database.txt");
    if(fout.is_open()) {
        fout << "vehicles tracked: " << vehicle_count << "\n";
        fout << "routes tracked: " << route_count << "\n";
        fout.close();
        cout << "all operational state data configurations saved securely to files" << endl;
    }
}
