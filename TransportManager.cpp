#include "TransportManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Parallel Arrays to hold real user input string data safely without constructor issues
string real_v_id[50];
string real_v_reg[50];
string real_v_status[50];
int real_v_cap[50];
int real_v_seats[50];

string real_r_id[50];
string real_r_start[50];
string real_r_end[50];
double real_r_dist[50];
string real_r_stop[50];

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
        vehicles_list[i] = nullptr;
        routes_list[i] = nullptr;
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

    // Store user data into parallel arrays
    real_v_id[vehicle_count] = id;
    real_v_reg[vehicle_count] = reg;
    real_v_status[vehicle_count] = status;
    real_v_cap[vehicle_count] = cap;
    real_v_seats[vehicle_count] = seats;

    vehicles_list[vehicle_count] = (Bus *)nullptr;
    vehicle_count++;

    cout << "\n\t>> Vehicle registered successfully!" << endl;
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

    for (int i = 0; i < vehicle_count; i++)
    {
        if (real_v_id[i] == search_id)
        {
            cout << "\t  Enter New Registration Plate No : ";
            getline(cin, real_v_reg[i]);
            cout << "\t  Enter New Operational Status    : ";
            getline(cin, real_v_status[i]);
            cout << "\n\t>> Vehicle data modified successfully." << endl;
            return;
        }
    }
    cout << "\t[Error]: Vehicle ID not found." << endl;
}

// ==================== REMOVE VEHICLE ====================
void TransportManager::removevehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n\t[Alert]: Inventory empty!" << endl;
        return;
    }
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

    // Store route user data into parallel arrays
    real_r_id[route_count] = id;
    real_r_start[route_count] = start;
    real_r_end[route_count] = end;
    real_r_dist[route_count] = dist;
    real_r_stop[route_count] = stop;

    routes_list[route_count] = (Route *)nullptr;
    route_count++;
    cout << "\n\t>> Map path initialized successfully." << endl;
}

// ==================== EDIT ROUTE ====================
void TransportManager::editroute()
{
    if (route_count == 0)
    {
        cout << "\n\t[Alert]: Route inventory empty!" << endl;
        return;
    }
    string search_id;
    cout << "\n\tEnter Route ID to modify: ";
    getline(cin, search_id);
    for (int i = 0; i < route_count; i++)
    {
        if (real_r_id[i] == search_id)
        {
            cout << "\t  Enter New Start Terminal : ";
            getline(cin, real_r_start[i]);
            cout << "\t  Enter New End Destination: ";
            getline(cin, real_r_end[i]);
            cout << "\n\t>> Route data modified successfully." << endl;
            return;
        }
    }
    cout << "\t[Error]: Route ID not found." << endl;
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

// ==================== GENERATE REPORTS (PRINTS EXACT USER INPUT) ====================
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
        cout << "\t  [Notification]: Zero assets registered inside the inventory." << endl;
    }
    else
    {
        // Prints EXACT data entered by the user
        for (int i = 0; i < vehicle_count; i++)
        {
            cout << "\t  [" << i + 1 << "] ID: " << real_v_id[i]
                 << " | Reg No: " << real_v_reg[i]
                 << " | Capacity: " << real_v_cap[i] << " Seats"
                 << " | Status: " << real_v_status[i] << endl;
        }
    }

    cout << "\n\t----------------[ SYSTEM ROUTES SCHEDULER ]----------------" << endl;
    if (route_count == 0)
    {
        cout << "\t  [Notification]: Zero system paths found inside local memory." << endl;
    }
    else
    {
        // Prints EXACT route data entered by the user
        for (int i = 0; i < route_count; i++)
        {
            cout << "\t  [" << i + 1 << "] Route ID: " << real_r_id[i]
                 << " | Bound: " << real_r_start[i] << " -> " << real_r_end[i]
                 << " | Distance: " << real_r_dist[i] << " KM"
                 << " | Main Stop: " << real_r_stop[i] << endl;
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
    for (int i = 0; i < vehicle_count; i++)
    {
        fout << real_v_id[i] << "\n"
             << real_v_reg[i] << "\n"
             << real_v_cap[i] << "\n"
             << real_v_status[i] << "\n"
             << real_v_seats[i] << "\n";
    }
    for (int i = 0; i < route_count; i++)
    {
        fout << real_r_id[i] << "\n"
             << real_r_start[i] << "\n"
             << real_r_end[i] << "\n"
             << real_r_dist[i] << "\n"
             << real_r_stop[i] << "\n";
    }
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
    fin.ignore(1000, '\n');

    for (int i = 0; i < vehicle_count; i++)
    {
        getline(fin, real_v_id[i]);
        getline(fin, real_v_reg[i]);
        fin >> real_v_cap[i];
        fin.ignore(1000, '\n');
        getline(fin, real_v_status[i]);
        fin >> real_v_seats[i];
        fin.ignore(1000, '\n');
    }
    for (int i = 0; i < route_count; i++)
    {
        getline(fin, real_r_id[i]);
        getline(fin, real_r_start[i]);
        getline(fin, real_r_end[i]);
        fin >> real_r_dist[i];
        fin.ignore(1000, '\n');
        getline(fin, real_r_stop[i]);
    }
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