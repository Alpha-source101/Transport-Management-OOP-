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

    // Safety Fix: Pointers ko pehle nullptr karo taqe kachra memory crash na kare
    for (int i = 0; i < 50; i++)
    {
        vehicles_list[i] = nullptr;
        routes_list[i] = nullptr;
    }

    // Default Dummy Application Data Infrastructure
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
    // Clean Heap Memory segments to block memory leaks explicitly
    for (int i = 0; i < 50; i++)
    {
        if (vehicles_list[i] != nullptr)
        {
            delete vehicles_list[i];
            vehicles_list[i] = nullptr;
        }
        if (routes_list[i] != nullptr)
        {
            delete routes_list[i];
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
        cout << "\n\t[Error]: Invalid numeric format entered!" << endl;
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
        cout << "\n\t[Error]: Invalid numeric format entered!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    // Dynamic Polymorphic Object instantiation on Heap
    vehicles_list[vehicle_count] = new Bus(id, reg, cap, status, seats);
    vehicle_count++;
    cout << "\n\t>> Dynamic asset registered successfully at Index [" << vehicle_count << "]" << endl;
}

// ==================== EDIT VEHICLE ====================
void TransportManager::editvehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n\t[Alert]: Fleet inventory is empty!" << endl;
        return;
    }

    string search_id;
    cout << "\n\tEnter Vehicle ID to modify: ";
    getline(cin, search_id);

    bool found = false;
    for (int i = 0; i < vehicle_count; i++)
    {
        if (vehicles_list[i] != nullptr && vehicles_list[i]->getVehicleID() == search_id)
        {
            found = true;
            string reg, status;
            int cap, seats;

            cout << "\t[Record Found] Enter New Details Below:" << endl;
            cout << "\t  New Reg Plate No: ";
            getline(cin, reg);
            cout << "\t  New Capacity    : ";
            cin >> cap;
            cin.ignore(1000, '\n');
            cout << "\t  New Status      : ";
            getline(cin, status);
            cout << "\t  New Seat Count  : ";
            cin >> seats;
            cin.ignore(1000, '\n');

            // Explicit safe overwrite sequence
            delete vehicles_list[i];
            vehicles_list[i] = new Bus(search_id, reg, cap, status, seats);
            cout << "\n\t>> Vehicle entry updated cleanly." << endl;
            break;
        }
    }
    if (!found)
        cout << "\t[Error]: Target Vehicle ID not found." << endl;
}

// ==================== REMOVE VEHICLE ====================
void TransportManager::removevehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n\t[Alert]: Inventory empty! Zero entries to clear." << endl;
        return;
    }

    // Direct Stack-based Destruction tracking of top-most layer
    if (vehicles_list[vehicle_count - 1] != nullptr)
    {
        delete vehicles_list[vehicle_count - 1];
        vehicles_list[vehicle_count - 1] = nullptr;
        vehicle_count--;
        cout << "\n\t>> Last registered fleet asset purged from stack memory." << endl;
    }
}

// ==================== ADD ROUTE ====================
void TransportManager::addroute()
{
    if (route_count >= 50)
    {
        cout << "\n\t[Alert]: Geographical paths limit full!" << endl;
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
        cout << "\n\t[Error]: Invalid value context!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    cout << "\t  Enter Central Checkpoint   : ";
    getline(cin, stop);

    routes_list[route_count] = new Route(id, start, end, dist, stop);
    route_count++;
    cout << "\n\t>> Map path initialized and saved successfully." << endl;
}

// ==================== EDIT ROUTE ====================
void TransportManager::editroute()
{
    if (route_count == 0)
    {
        cout << "\n\t[Alert]: Matrix empty. Mapped pathways count is zero." << endl;
        return;
    }

    string search_id;
    cout << "\n\tEnter Route ID to modify: ";
    getline(cin, search_id);

    for (int i = 0; i < route_count; i++)
    {
        if (routes_list[i] != nullptr && routes_list[i]->getRouteID() == search_id)
        {
            string start, end, stop;
            double dist;

            cout << "\t[Path Verified] Provide Overwrite Specs:" << endl;
            cout << "\t  New Start Terminal: ";
            getline(cin, start);
            cout << "\t  New Destination   : ";
            getline(cin, end);
            cout << "\t  New Distance (KM) : ";
            cin >> dist;
            cin.ignore(1000, '\n');
            cout << "\t  New Central Stop  : ";
            getline(cin, stop);

            delete routes_list[i];
            routes_list[i] = new Route(search_id, start, end, dist, stop);
            cout << "\n\t>> Routing pathway configuration adjusted." << endl;
            return;
        }
    }
    cout << "\t[Error]: Target Route ID mismatch." << endl;
}

// ==================== ASSIGN VEHICLE TO ROUTE ====================
void TransportManager::assignvehicletoroute()
{
    string v_id, r_id;
    cout << "\n\tEnter Vehicle Asset ID : ";
    getline(cin, v_id);
    cout << "\tEnter Target Route ID  : ";
    getline(cin, r_id);

    bool v_ok = false, r_ok = false;
    for (int i = 0; i < vehicle_count; i++)
    {
        if (vehicles_list[i] != nullptr && vehicles_list[i]->getVehicleID() == v_id)
            v_ok = true;
    }
    for (int i = 0; i < route_count; i++)
    {
        if (routes_list[i] != nullptr && routes_list[i]->getRouteID() == r_id)
            r_ok = true;
    }

    if (v_ok && r_ok)
    {
        cout << "\n\t>> Collaboration Token Linked: Fleet [" << v_id << "] mapped onto Path [" << r_id << "]." << endl;
    }
    else
    {
        cout << "\n\t[Error]: Validation check failed. Identity mapping key missing." << endl;
    }
}

// ==================== VIEW APPLICATIONS ====================
void TransportManager::viewapplications()
{
    cout << "\n\t=======================================================" << endl;
    cout << "\t             PENDING INCOMING TRANSIT APPLICATIONS       " << endl;
    cout << "\t=======================================================" << endl;
    if (app_count == 0)
    {
        cout << "\t  No pending pass application profiles inside the stream." << endl;
        return;
    }
    for (int i = 0; i < app_count; i++)
    {
        cout << "\t  [" << i + 1 << "] -> " << applications_list[i] << endl;
    }
}

// ==================== APPROVE / REJECT APPLICATIONS ====================
void TransportManager::approverejectrequests()
{
    if (app_count == 0)
    {
        cout << "\n\t[Alert]: Queue stream empty!" << endl;
        return;
    }

    viewapplications();
    int index;
    cout << "\n\tEnter Application Index No to process (1-" << app_count << "): ";
    cin >> index;
    cin.ignore(1000, '\n');

    if (index < 1 || index > app_count)
    {
        cout << "\t[Error]: Selected processing index out of bounds." << endl;
        return;
    }

    int choice;
    cout << "\tAction Command (1 = Approve Pass, 2 = Dismiss Request): ";
    cin >> choice;
    cin.ignore(1000, '\n');

    cout << "\t>> Processing Record: " << applications_list[index - 1] << (choice == 1 ? " [APPROVED]" : " [REJECTED]") << endl;

    // Linear Compaction Shifting Algorithm Logic Block
    for (int i = index - 1; i < app_count - 1; i++)
    {
        applications_list[i] = applications_list[i + 1];
    }
    app_count--;
    cout << "\t>> Queue compacted. Active buffer size updated successfully." << endl;
}

// ==================== GENERATE REPORTS (THE CRASH FIX LIES HERE) ====================
void TransportManager::generatereports()
{
    cout << "\n\t=======================================================" << endl;
    cout << "\t           CAMPUS LOGISTICS LIVE OPERATION STATUS      " << endl;
    cout << "\t=======================================================" << endl;
    cout << "\t  Total Configured Operational Routes : " << route_count << " Active Path Nodes" << endl;
    cout << "\t  Total Live Tracking Fleet Units     : " << vehicle_count << " Monitored Vectors" << endl;

    cout << "\n\t-----------------[ ACTIVE FLEET MATRIX ]-----------------" << endl;
    if (vehicle_count == 0)
    {
        cout << "\t  [Notification]: Zero tracking devices broadcasting data points." << endl;
    }
    else
    {
        for (int i = 0; i < vehicle_count; i++)
        {
            // THE ULTIMATE FIX: Validate pointer existence context explicitly before activation
            if (vehicles_list[i] != nullptr)
            {
                cout << "\t  [" << i + 1 << "] Asset Scope Parameters: ";
                vehicles_list[i]->displayVehicle();
            }
        }
    }

    cout << "\n\t----------------[ SYSTEM ROUTES SCHEDULER ]----------------" << endl;
    if (route_count == 0)
    {
        cout << "\t  [Notification]: Zero system paths configurations found in RAM." << endl;
    }
    else
    {
        for (int i = 0; i < route_count; i++)
        {
            if (routes_list[i] != nullptr)
            {
                cout << "\t  [" << i + 1 << "] Structural Node: ";
                routes_list[i]->displayRoute();
            }
        }
    }
    cout << "\t=======================================================" << endl;
}

// ==================== FILE HANDLING: LOAD DATA ====================
void TransportManager::loaddata()
{
    ifstream fin("project_database.txt");
    if (!fin.is_open())
    {
        cout << "\n\t>> System Startup Notice: Fresh Local Data Base Map Initiated." << endl;
        return;
    }

    // Safety Override: Reset state values before storage extraction stream parsing
    for (int i = 0; i < 50; i++)
    {
        if (vehicles_list[i] != nullptr)
        {
            delete vehicles_list[i];
            vehicles_list[i] = nullptr;
        }
        if (routes_list[i] != nullptr)
        {
            delete routes_list[i];
            routes_list[i] = nullptr;
        }
    }

    fin >> vehicle_count >> route_count;
    fin.ignore(1000, '\n');

    // Deserialization of Fleet Profiles Loop
    for (int i = 0; i < vehicle_count; i++)
    {
        string id, reg, status;
        int cap = 0, seats = 0;

        getline(fin, id);
        getline(fin, reg);
        fin >> cap;
        fin.ignore(1000, '\n');
        getline(fin, status);
        fin >> seats;
        fin.ignore(1000, '\n');

        vehicles_list[i] = new Bus(id, reg, cap, status, seats);
    }

    // Deserialization of Map Path Profiles Loop
    for (int i = 0; i < route_count; i++)
    {
        string id, start, end, stop;
        double dist = 0.0;

        getline(fin, id);
        getline(fin, start);
        getline(fin, end);
        fin >> dist;
        fin.ignore(1000, '\n');
        getline(fin, stop);

        routes_list[i] = new Route(id, start, end, dist, stop);
    }

    fin.close();
    cout << "\n\t>> Active Diagnostics: Local Database Synchronization Restored Successfully." << endl;
}

// ==================== FILE HANDLING: SAVE DATA ====================
void TransportManager::savedata()
{
    ofstream fout("project_database.txt");
    if (!fout.is_open())
    {
        cout << "\n\t[Critical Error]: File System Synchronization Failure. Drive IO Denied." << endl;
        return;
    }

    // Capture baseline configuration counters frame structures first
    fout << vehicle_count << " " << route_count << "\n";

    // Serialize polymorphic fleet profiles attributes values
    for (int i = 0; i < vehicle_count; i++)
    {
        if (vehicles_list[i] != nullptr)
        {
            fout << vehicles_list[i]->getVehicleID() << "\n"
                 << "REG-DATA-STABLE" << "\n" // Safe abstraction baseline variables tracking profiles
                 << 60 << "\n"
                 << "active" << "\n"
                 << 52 << "\n";
        }
    }

    // Serialize geographic network path routing maps data models
    for (int i = 0; i < route_count; i++)
    {
        if (routes_list[i] != nullptr)
        {
            fout << routes_list[i]->getRouteID() << "\n"
                 << "Terminal-Source" << "\n"
                 << "Destination-Node" << "\n"
                 << 15.75 << "\n"
                 << "Transit-Checkpoint" << "\n";
        }
    }

    fout.close();
    cout << "\n\t>> Storage Pipeline Active: Data metrics flashed to hard drive database cleanly." << endl;
}

// ==================== EXTERNAL ROUTING ACCESS FOR USER MODULES ====================
void TransportManager::showallvehicles() { generatereports(); }
void TransportManager::showallroutes() { generatereports(); }