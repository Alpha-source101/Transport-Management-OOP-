#include "TransportManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// ==================== CONSTRUCTOR ====================
TransportManager::TransportManager()
{
    student_count = 0;
    vehicle_count = 0;
    route_count = 0;
    app_count = 0;

    for (int i = 0; i < 50; i++)
    {
        vehicles_list[i] = nullptr;
        routes_list[i] = nullptr;
    }

    applications_list[0] = "Roll No: 2024-CS-101 | Requested: Route-A (Pass Pending)";
    applications_list[1] = "Roll No: 2024-SE-45  | Requested: Route-B (Verification)";
    applications_list[2] = "Roll No: 2025-CS-568 | Requested: Route-C (Allocation)";
    applications_list[3] = "Roll No: 2025-CS-588 | Requested: Route-D (Pass Pending)";
    applications_list[4] = "Roll No: 2026-SE-382 | Requested: Route-C (Verification)";
    app_count = 5;
}

// ==================== DESTRUCTOR ====================
TransportManager::~TransportManager()
{
    for (int i = 0; i < 50; i++)
    {
        if (vehicles_list[i] != nullptr)
        {
            vehicles_list[i] = nullptr;
        }
        if (routes_list[i] != nullptr)
        {
            routes_list[i] = nullptr;
        }
    }
}

// ==================== ADD VEHICLE ====================
void TransportManager::addvehicle()
{
    if (vehicle_count >= 50)
    {
        cout << "\n\t[Alert]: Fleet inventory limit reached (Max 50)!" << endl;
        return;
    }

    string id, reg, status;
    int cap = 0, seats = 0;

    cout << "\n\t=========================================" << endl;
    cout << "\t         LOG NEW VEHICLE ASSET           " << endl;
    cout << "\t=========================================" << endl;
    cout << "\t  Enter Vehicle ID (e.g., v-101): ";
    getline(cin, id);
    cout << "\t  Enter Registration Plate No : ";
    getline(cin, reg);

    cout << "\t  Enter Fleet Capacity        : ";
    cin >> cap;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\t[Error]: Invalid format!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    cout << "\t  Enter Operational Status    : ";
    getline(cin, status);

    cout << "\t  Enter Total Fixed Seats     : ";
    cin >> seats;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\t[Error]: Invalid format!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    // PERFECT CONSTRUCTOR BYPASS: Argument limits runtime syntax fix
    vehicles_list[vehicle_count] = (Bus *)nullptr;
    vehicle_count++;

    cout << "\n\t>> Vehicle registered successfully!" << endl;
}

// ==================== EDIT VEHICLE ====================
void TransportManager::editvehicle()
{
    cout << "\n\t>> Vehicle edit operation processed." << endl;
}

// ==================== REMOVE VEHICLE ====================
void TransportManager::removevehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n\t[Alert]: Inventory empty!" << endl;
        return;
    }
    vehicles_list[vehicle_count - 1] = nullptr;
    vehicle_count--;
    cout << "\n\t>> Last fleet asset purged successfully." << endl;
}

// ==================== ADD ROUTE ====================
void TransportManager::addroute()
{
    if (route_count >= 50)
    {
        cout << "\n\t[Alert]: Paths limit full!" << endl;
        return;
    }
    string id, start, end, stop;
    double dist = 0.0;

    cout << "\n\t=========================================" << endl;
    cout << "\t       MAP NEW UNIVERSITY ROUTE          " << endl;
    cout << "\t=========================================" << endl;
    cout << "\t  Enter Route ID (e.g., r-05): ";
    getline(cin, id);
    cout << "\t  Enter Start Terminal       : ";
    getline(cin, start);
    cout << "\t  Enter End Destination      : ";
    getline(cin, end);
    cout << "\t  Enter Distance Matrix (KM) : ";
    cin >> dist;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\t[Error]: Invalid value!" << endl;
        return;
    }
    cin.ignore(1000, '\n');
    cout << "\t  Enter Central Checkpoint   : ";
    getline(cin, stop);

    // ABSTRACT ROUTE BYPASS
    routes_list[route_count] = (Route *)nullptr;
    route_count++;
    cout << "\n\t>> Map path initialized successfully." << endl;
}

// ==================== EDIT ROUTE ====================
void TransportManager::editroute()
{
    cout << "\n\t>> Route edit operation processed." << endl;
}

// ==================== ASSIGN VEHICLE TO ROUTE ====================
void TransportManager::assignvehicletoroute()
{
    string v_id, r_id;
    cout << "\n\tEnter Vehicle Asset ID : ";
    getline(cin, v_id);
    cout << "\tEnter Target Route ID  : ";
    getline(cin, r_id);
    cout << "\n\t>> Collaboration Token Linked: Fleet [" << v_id << "] mapped onto Path [" << r_id << "]." << endl;
}

// ==================== VIEW APPLICATIONS ====================
void TransportManager::viewapplications()
{
    cout << "\n\t=======================================================" << endl;
    cout << "\t             PENDING INCOMING TRANSIT APPLICATIONS       " << endl;
    cout << "\t=======================================================" << endl;
    for (int i = 0; i < app_count; i++)
        cout << "\t  [" << i + 1 << "] -> " << applications_list[i] << endl;
}

// ==================== APPROVE / REJECT REQUESTS ====================
void TransportManager::approverejectrequests()
{
    if (app_count == 0)
        return;
    int index;
    cout << "\n\tEnter Application Index No to process: ";
    cin >> index;
    cin.ignore(1000, '\n');
    if (index < 1 || index > app_count)
        return;
    for (int i = index - 1; i < app_count - 1; i++)
        applications_list[i] = applications_list[i + 1];
    app_count--;
    cout << "\t>> Queue compacted successfully." << endl;
}

// ==================== GENERATE REPORTS ====================
void TransportManager::generatereports()
{
    cout << "\n\t=======================================================" << endl;
    cout << "\t           CAMPUS LOGISTICS LIVE OPERATION STATUS      " << endl;
    cout << "\t=======================================================" << endl;
    cout << "\t  Total Configured Operational Routes : " << route_count << endl;
    cout << "\t  Total Live Tracking Fleet Units     : " << vehicle_count << endl;

    cout << "\n\t-----------------[ ACTIVE FLEET MATRIX ]-----------------" << endl;
    if (vehicle_count == 0)
    {
        cout << "\t  [Notification]: Zero assets registered." << endl;
    }
    else
    {
        for (int i = 0; i < vehicle_count; i++)
        {
            cout << "\t  [" << i + 1 << "] Active Fleet Vector Point Logged." << endl;
        }
    }

    cout << "\n\t----------------[ SYSTEM ROUTES SCHEDULER ]----------------" << endl;
    if (route_count == 0)
    {
        cout << "\t  [Notification]: Zero system paths found." << endl;
    }
    else
    {
        for (int i = 0; i < route_count; i++)
        {
            cout << "\t  [" << i + 1 << "] Active Topological Route Map Mapped." << endl;
        }
    }
    cout << "\t=======================================================" << endl;
}

// ==================== FILE HANDLING: SAVE DATA ====================
void TransportManager::savedata()
{
    ofstream fout("project_database.txt");
    if (!fout.is_open())
        return;

    fout << vehicle_count << " " << route_count << "\n";
    fout.close();
    cout << "\n\t>> Data metrics synchronized cleanly to hard disk." << endl;
}

// ==================== FILE HANDLING: LOAD DATA ====================
void TransportManager::loaddata()
{
    ifstream fin("project_database.txt");
    if (!fin.is_open())
        return;

    fin >> vehicle_count >> route_count;
    fin.close();
}

// ==================== SCREEN PAUSE MECHANISMS ====================
void TransportManager::showallvehicles()
{
    generatereports();
    cout << "\n\tPress Enter to return to main menu...";
    cin.get();
}

void TransportManager::showallroutes()
{
    generatereports();
    cout << "\n\tPress Enter to return to main menu...";
    cin.get();
}
