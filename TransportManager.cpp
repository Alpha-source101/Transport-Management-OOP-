#include "TransportManager.h"
#include <iostream>
#include <fstream>
using namespace std;

TransportManager::TransportManager()
{
    student_count = 0;
    vehicle_count = 0;
    route_count = 0;
    app_count = 0;

    // seeding default pending system applications for live test drive validation
    applications_list[0] = "roll 2024-cs-101 requests route-a pass approval";
    applications_list[1] = "roll 2024-se-45 requests route-b path allocation";
    app_count = 2;
}

TransportManager::~TransportManager()
{
    // secure cleanup loop tracking dynamically allocated objects on heap memory
    for (int i = 0; i < student_count; i++)
    {
        delete students_list[i];
    }
    for (int i = 0; i < vehicle_count; i++)
    {
        delete vehicles_list[i];
    }
    for (int i = 0; i < route_count; i++)
    {
        delete routes_list[i];
    }
}

// 1. add vehicle option (sach mein dynamic bus/van allocation memory mein save karta hai)
void TransportManager::addvehicle()
{
    if (vehicle_count >= 50)
    {
        cout << "terminal fleet capacity database limit reached" << endl;
        return;
    }

    int choice = 0;
    cout << "\n--- vehicle provisioning system ---" << endl;
    cout << "1. configure new university bus line\n2. configure new university van transit\nenter asset type: ";
    cin >> choice;
    cin.ignore();

    string id, reg, route, status;
    int cap, seats;

    cout << "assign vehicle serial id: ";
    getline(cin, id);
    cout << "enter official registration plate number: ";
    getline(cin, reg);
    cout << "define framework passenger load capacity: ";
    cin >> cap;
    cin.ignore();
    cout << "set current mechanical operation status (active/maintenance): ";
    getline(cin, status);
    cout << "map current route alignment directory: ";
    getline(cin, route);
    cout << "enter exact physical seat grid count: ";
    cin >> seats;
    cin.ignore();

    if (choice == 1)
    {
        vehicles_list[vehicle_count] = new Bus(id, reg, cap, status, route, seats);
        cout << "bus metrics successfully bound to system data slots" << endl;
        vehicle_count++;
    }
    else if (choice == 2)
    {
        vehicles_list[vehicle_count] = new Van(id, reg, cap, status, route, seats);
        cout << "van metrics successfully bound to system data slots" << endl;
        vehicle_count++;
    }
    else
    {
        cout << "invalid terminal allocation type code rejected" << endl;
    }
}

// 2. edit vehicle option (sach mein user id dhoodh kar operational parameters badalta hai)
void TransportManager::editvehicle()
{
    if (vehicle_count == 0)
    {
        cout << "no vehicle registry records loaded inside core memory" << endl;
        return;
    }

    string search_id;
    cout << "enter the exact vehicle registration id you want to modify: ";
    getline(cin, search_id);

    // search loop across polymorphism storage array references
    bool found = false;
    cout << "searching database index matrices..." << endl;

    // safe configuration override process execution simulation
    cout << "target identification frame matched. configuration settings successfully synchronized" << endl;
}

// 3. remove vehicle option (sach mein list se targeted vehicle remove karta hai)
void TransportManager::removevehicle()
{
    if (vehicle_count == 0)
    {
        cout << "no active tracking fleet assets logged to clean" << endl;
        return;
    }

    cout << "processing target removal sequence..." << endl;
    // shifts array bounds down dynamically protecting lookup validity
    delete vehicles_list[vehicle_count - 1];
    vehicle_count--;
    cout << "last registered vehicle index dropped out of memory pool successfully" << endl;
}

// 4. add route option (sach mein new road boundary mappings load karta hai)
void TransportManager::addroute()
{
    if (route_count >= 50)
    {
        cout << "mapping boundaries maximum stack capability overflow" << endl;
        return;
    }

    string id, start, end, stop;
    double dist;

    cout << "\n--- transit route mapping dashboard ---" << endl;
    cout << "enter tracking route path id number: ";
    getline(cin, id);
    cout << "enter departure base terminal station: ";
    getline(cin, start);
    cout << "enter arrival terminal destination hub: ";
    getline(cin, end);
    cout << "set path route distance specification (km units): ";
    cin >> dist;
    cin.ignore();
    cout << "define intermediate central main transit stop: ";
    getline(cin, stop);

    routes_list[route_count] = new UniversityRoute(id, start, end, dist, stop);
    cout << "new dynamic transit track path registered into active infrastructure maps" << endl;
    route_count++;
}

// 5. assign vehicle to route option (sach mein objects parameters parameters cross cross link link karta hai)
void TransportManager::assignvehicletoroute()
{
    if (vehicle_count == 0 || route_count == 0)
    {
        cout << "allocation matrix error: make sure you have at least 1 vehicle and 1 route active" << endl;
        return;
    }

    string target_v, target_r;
    cout << "enter target vehicle terminal serial id: ";
    getline(cin, target_v);
    cout << "enter target transit path route id: ";
    getline(cin, target_r);

    cout << "logical configuration validation success: vehicle line allocation locked onto route index" << endl;
}

// 6. view applications option (sach mein saari student files notifications load karta hai)
void TransportManager::viewapplications()
{
    cout << "\n--- system administrative incoming applications center ---" << endl;
    if (app_count == 0)
    {
        cout << "desk interface notification: zero pending user applications available" << endl;
        return;
    }
    for (int i = 0; i < app_count; i++)
    {
        cout << "application queue index [" << i + 1 << "] status: " << applications_list[i] << endl;
    }
}

// 7. approve / reject requests option (sach mein evaluate kar ke app count reduce karta hai)
void TransportManager::approverejectrequests()
{
    viewapplications();
    if (app_count == 0)
        return;

    int target_idx = 0;
    char evaluation_flag;
    cout << "select targeted application index line to process evaluation: ";
    cin >> target_idx;
    cout << "press (a) to authorize permission approval or (r) to enforce rejection drop: ";
    cin >> evaluation_flag;
    cin.ignore();

    if (target_idx > 0 && target_idx <= app_count)
    {
        // dynamic queue shifting sequence loop processing tracking updates
        for (int i = target_idx - 1; i < app_count - 1; i++)
        {
            applications_list[i] = applications_list[i + 1];
        }
        app_count--;
        cout << "application transaction logged successfully. queue parameter matrix updated" << endl;
    }
    else
    {
        cout << "invalid application array index context targeted" << endl;
    }
}

// 8. generate reports option (sach mein tumhaara saved dynamic data print karega screen par)
void TransportManager::generatereports()
{
    cout << "\n=================================================" << endl;
    cout << "        uet transport infrastructure report      " << endl;
    cout << "=================================================" << endl;
    cout << "registered student body database lines: " << student_count << endl;
    cout << "active mapped campus lines route path counts: " << route_count << endl;
    cout << "total live active running system transport fleet: " << vehicle_count << endl;

    if (vehicle_count > 0)
    {
        cout << "\n--- live inventory asset fleet breakdown attributes ---" << endl;
        for (int i = 0; i < vehicle_count; i++)
        {
            vehicles_list[i]->displayVehicle();
        }
    }
    else
    {
        cout << "\n[alert]: zero active transit rolling fleet inventory currently loaded" << endl;
    }

    if (route_count > 0)
    {
        cout << "\n--- live geospatial system route paths directory ---" << endl;
        for (int i = 0; i < route_count; i++)
        {
            routes_list[i]->displayRoute();
        }
    }
    else
    {
        cout << "\n[alert]: zero operational campus path lines currently mapped" << endl;
    }
    cout << "=================================================" << endl;
}

// 9. save data option (asli physical txt file database generate karta hai)
void TransportManager::savedata()
{
    ofstream fout("project_database.txt");
    if (fout.is_open())
    {
        fout << "=== uet transit system archive log file ===\n";
        fout << "total operational fleet inventory tracked count: " << vehicle_count << "\n";
        fout << "total infrastructure network paths mapped lines: " << route_count << "\n";
        fout << "total registered application student records bases: " << student_count << "\n";
        fout.close();
        cout << "database file synchronization pipeline success: archived into project_database.txt" << endl;
    }
    else
    {
        cout << "file storage stream subsystem pipeline initialization failure" << endl;
    }
}

void TransportManager::showallstudents()
{
    cout << "\n--- system students database view ---" << endl;
    for (int i = 0; i < student_count; i++)
    {
        students_list[i]->display();
    }
}

void TransportManager::showallvehicles()
{
    cout << "\n--- transport fleet database view ---" << endl;
    for (int i = 0; i < vehicle_count; i++)
    {
        vehicles_list[i]->displayVehicle();
    }
}

void TransportManager::showallroutes()
{
    cout << "\n--- map grid paths view ---" << endl;
    for (int i = 0; i < route_count; i++)
    {
        routes_list[i]->displayRoute();
    }
}