#include "TransportManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// VS CODE TERMINAL COLOR ENGINE (ANSI ESCAPE CODES)
void setConsoleColor(int colorCode)
{
    if (colorCode == 6)
    {
        cout << "\033[33m"; // VS Code Force Yellow
    }
    else if (colorCode == 13)
    {
        cout << "\033[35m"; // VS Code Force Pink/Magenta
    }
    else
    {
        cout << "\033[0m"; // VS Code Reset to Default White
    }
}

// Parallel Arrays to hold real user input string data safely
string real_v_id[50];
string real_v_reg[50];
string real_v_status[50];
string real_v_type[50];
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
        setConsoleColor(13); // Pink for alerts
        cout << "\n\t[Alert]: Fleet inventory limit reached (Max 50)!" << endl;
        setConsoleColor(7);
        return;
    }

    int choice = 0;
    string type_str = "Bus";

    setConsoleColor(6); // YELLOW FOR MENUS
    cout << "\n\t=========================================" << endl;
    cout << "\t         SELECT VEHICLE ASSET TYPE       " << endl;
    cout << "\t=========================================" << endl;
    cout << "\t  1. Add Bus Fleet Asset" << endl;
    cout << "\t  2. Add Van Fleet Asset" << endl;

    setConsoleColor(13); // PINK FOR INPUTS
    cout << "\t  Enter choice (1-2): ";
    cin >> choice;
    if (cin.fail() || choice < 1 || choice > 2)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\t[Error]: Invalid choice selection!" << endl;
        setConsoleColor(7);
        return;
    }
    cin.ignore(1000, '\n');

    if (choice == 2)
    {
        type_str = "Van";
    }

    string id, reg, status;
    int cap = 0, seats = 0;

    setConsoleColor(6); // YELLOW FOR SUB-MENU
    cout << "\n\t=========================================" << endl;
    cout << "\t         LOG NEW " << (choice == 1 ? "BUS" : "VAN") << " ASSET           " << endl;
    cout << "\t=========================================" << endl;

    setConsoleColor(13); // PINK FOR DATA ENTRY
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
        setConsoleColor(7);
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
        setConsoleColor(7);
        return;
    }
    cin.ignore(1000, '\n');

    real_v_id[vehicle_count] = id;
    real_v_reg[vehicle_count] = reg;
    real_v_status[vehicle_count] = status;
    real_v_type[vehicle_count] = type_str;
    real_v_cap[vehicle_count] = cap;
    real_v_seats[vehicle_count] = seats;

    vehicles_list[vehicle_count] = (Bus *)nullptr;
    vehicle_count++;

    cout << "\n\t>> " << type_str << " registered successfully!" << endl;
    setConsoleColor(7); // Reset to Default White
}

// ==================== EDIT VEHICLE ====================
void TransportManager::editvehicle()
{
    if (vehicle_count == 0)
    {
        setConsoleColor(13);
        cout << "\n\t[Alert]: Fleet inventory is empty!" << endl;
        setConsoleColor(7);
        return;
    }
    string search_id;
    setConsoleColor(13); // Pink for entry
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
            setConsoleColor(7);
            return;
        }
    }
    cout << "\t[Error]: Vehicle ID not found." << endl;
    setConsoleColor(7);
}

// ==================== REMOVE VEHICLE ====================
void TransportManager::removevehicle()
{
    setConsoleColor(13);
    if (vehicle_count == 0)
    {
        cout << "\n\t[Alert]: Inventory empty!" << endl;
        setConsoleColor(7);
        return;
    }
    vehicle_count--;
    cout << "\n\t>> Last fleet asset purged successfully." << endl;
    setConsoleColor(7);
}

// ==================== ADD ROUTE ====================
void TransportManager::addroute()
{
    if (route_count >= 50)
    {
        setConsoleColor(13);
        cout << "\n\t[Alert]: Paths limit full!" << endl;
        setConsoleColor(7);
        return;
    }
    string id, start, end, stop;
    double dist = 0.0;

    setConsoleColor(6); // YELLOW FOR ROUTE MENU
    cout << "\n\t=========================================" << endl;
    cout << "\t       MAP NEW UNIVERSITY ROUTE          " << endl;
    cout << "\t=========================================" << endl;

    setConsoleColor(13); // PINK FOR DATA ENTRY
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
        setConsoleColor(7);
        return;
    }
    cin.ignore(1000, '\n');
    cout << "\t  Enter Central Checkpoint   : ";
    getline(cin, stop);

    real_r_id[route_count] = id;
    real_r_start[route_count] = start;
    real_r_end[route_count] = end;
    real_r_dist[route_count] = dist;
    real_r_stop[route_count] = stop;

    routes_list[route_count] = (Route *)nullptr;
    route_count++;
    cout << "\n\t>> Map path initialized successfully." << endl;
    setConsoleColor(7);
}

// ==================== EDIT ROUTE ====================
void TransportManager::editroute()
{
    if (route_count == 0)
    {
        setConsoleColor(13);
        cout << "\n\t[Alert]: Route inventory empty!" << endl;
        setConsoleColor(7);
        return;
    }
    string search_id;
    setConsoleColor(13);
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
            setConsoleColor(7);
            return;
        }
    }
    cout << "\t[Error]: Route ID not found." << endl;
    setConsoleColor(7);
}

// ==================== ASSIGN VEHICLE TO ROUTE ====================
void TransportManager::assignvehicletoroute()
{
    string v_id, r_id;
    setConsoleColor(13);
    cout << "\n\tEnter Vehicle Asset ID : ";
    getline(cin, v_id);
    cout << "\tEnter Target Route ID  : ";
    getline(cin, r_id);
    cout << "\n\t>> Collaboration Token Linked: Fleet [" << v_id << "] mapped onto Path [" << r_id << "]." << endl;
    setConsoleColor(7);
}

// ==================== VIEW APPLICATIONS ====================
void TransportManager::viewapplications()
{
    setConsoleColor(6); // YELLOW HEADER
    cout << "\n\t=======================================================" << endl;
    cout << "\t             PENDING INCOMING TRANSIT APPLICATIONS       " << endl;
    cout << "\t=======================================================" << endl;

    setConsoleColor(13); // PINK LIST DATA
    for (int i = 0; i < app_count; i++)
        cout << "\t  [" << i + 1 << "] -> " << applications_list[i] << endl;
    setConsoleColor(7);
}

// ==================== APPROVE / REJECT REQUESTS ====================
void TransportManager::approverejectrequests()
{
    if (app_count == 0)
        return;
    int index;
    setConsoleColor(13);
    cout << "\n\tEnter Application Index No to process: ";
    cin >> index;
    cin.ignore(1000, '\n');
    if (index < 1 || index > app_count)
    {
        setConsoleColor(7);
        return;
    }
    for (int i = index - 1; i < app_count - 1; i++)
        applications_list[i] = applications_list[i + 1];
    app_count--;
    cout << "\t>> Queue compacted successfully." << endl;
    setConsoleColor(7);
}

// ==================== GENERATE REPORTS ====================
void TransportManager::generatereports()
{
    setConsoleColor(6); // YELLOW HEADERS
    cout << "\n\t=======================================================" << endl;
    cout << "\t           CAMPUS LOGISTICS LIVE OPERATION STATUS      " << endl;
    cout << "\t=======================================================" << endl;

    setConsoleColor(13); // PINK OPERATIONAL NUMBERS
    cout << "\t  Total Configured Operational Routes : " << route_count << endl;
    cout << "\t  Total Live Tracking Fleet Units     : " << vehicle_count << endl;

    setConsoleColor(6); // YELLOW MATRIX SECTION
    cout << "\n\t-----------------[ ACTIVE FLEET MATRIX ]-----------------" << endl;

    setConsoleColor(13); // PINK MATRIX DATA
    if (vehicle_count == 0)
    {
        cout << "\t  [Notification]: Zero assets registered inside the inventory." << endl;
    }
    else
    {
        for (int i = 0; i < vehicle_count; i++)
        {
            cout << "\t  [" << i + 1 << "] Type: " << real_v_type[i]
                 << " | ID: " << real_v_id[i]
                 << " | Reg No: " << real_v_reg[i]
                 << " | Capacity: " << real_v_cap[i] << " Seats"
                 << " | Status: " << real_v_status[i] << endl;
        }
    }

    setConsoleColor(6); // YELLOW SCHEDULER SECTION
    cout << "\n\t----------------[ SYSTEM ROUTES SCHEDULER ]----------------" << endl;

    setConsoleColor(13); // PINK SCHEDULER DATA
    if (route_count == 0)
    {
        cout << "\t  [Notification]: Zero system paths found inside local memory." << endl;
    }
    else
    {
        for (int i = 0; i < route_count; i++)
        {
            cout << "\t  [" << i + 1 << "] Route ID: " << real_r_id[i]
                 << " | Bound: " << real_r_start[i] << " -> " << real_r_end[i]
                 << " | Distance: " << real_r_dist[i] << " KM"
                 << " | Main Stop: " << real_r_stop[i] << endl;
        }
    }
    setConsoleColor(6);
    cout << "\t=======================================================" << endl;
    setConsoleColor(7);
}

// ==================== FILE HANDLING ====================
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
             << real_v_seats[i] << "\n"
             << real_v_type[i] << "\n";
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
    setConsoleColor(13);
    cout << "\n\t>> Data metrics synchronized cleanly to hard disk." << endl;
    setConsoleColor(7);
}

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
        getline(fin, real_v_type[i]);
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

void TransportManager::showallvehicles()
{
    generatereports();
    setConsoleColor(6);
    cout << "\n\tPress Enter to return to main menu...";
    setConsoleColor(7);
    cin.get();
}

void TransportManager::showallroutes()
{
    generatereports();
    setConsoleColor(6);
    cout << "\n\tPress Enter to return to main menu...";
    setConsoleColor(7);
    cin.get();
}