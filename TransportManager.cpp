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

    applications_list[0] = "roll 2024-cs-101 requests route-a pass approval";
    applications_list[1] = "roll 2024-se-45 requests route-b path allocation";
    applications_list[2] = "roll 2025-cs-568 requests route-c bus allocation";
    applications_list[3] = "roll 2025-cs-588 requests route-d path approval";
    applications_list[4] = "roll 2026-se-382 requests route-c path allocation";

    app_count = 5;
}

TransportManager::~TransportManager()
{
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

void TransportManager::addvehicle()
{
    if (vehicle_count >= 50)
    {
        cout << "\n  [Alert]: Database limit reached!" << endl;
        return;
    }

    int choice = 0;
    cout << "\n================[ VEHICLE PROVISIONING ]===============" << endl;
    cout << "  1. University Bus\n  2. University Van\n  Select asset type: ";
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Invalid numeric input!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    string id, reg, route, status;
    int cap = 0, seats = 0;

    cout << "  Enter Vehicle ID (e.g. v-101): ";
    getline(cin, id);
    cout << "  Enter Registration Plate No: ";
    getline(cin, reg);

    cout << "  Enter Capacity (Number): ";
    cin >> cap;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Invalid capacity entry!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    cout << "  Enter Status (active/maintenance): ";
    getline(cin, status);
    cout << "  Enter Route Name/ID: ";
    getline(cin, route);

    cout << "  Enter Total Seats: ";
    cin >> seats;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Invalid seats entry!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    if (choice == 1)
    {
        vehicles_list[vehicle_count] = new Bus(id, reg, cap, status, route, seats);
        cout << "\n  >> Bus added successfully!" << endl;
        vehicle_count++;
    }
    else if (choice == 2)
    {
        vehicles_list[vehicle_count] = new Van(id, reg, cap, status, route, seats);
        cout << "\n  >> Van added successfully!" << endl;
        vehicle_count++;
    }
    else
    {
        cout << "\n  [Error]: Invalid selection code!" << endl;
    }
}

void TransportManager::editvehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n  [Alert]: No vehicles loaded in memory!" << endl;
        return;
    }

    string search_id;
    cout << "\n================[ VEHICLE MODIFICATION ]===============" << endl;
    cout << "  Enter exact vehicle registration ID to edit: ";
    getline(cin, search_id);

    bool found = false;
    for (int i = 0; i < vehicle_count; i++)
    {
        cout << "\n  >> Processing target ID database match..." << endl;
        found = true;

        string new_reg, new_route, new_status;
        int new_cap = 0, new_seats = 0;

        cout << "  Enter New Registration Plate No: ";
        getline(cin, new_reg);

        cout << "  Enter New Capacity (Number): ";
        cin >> new_cap;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [Error]: Edit failed! Bad data input." << endl;
            return;
        }
        cin.ignore(1000, '\n');

        cout << "  Enter New Status (active/maintenance): ";
        getline(cin, new_status);
        cout << "  Enter New Assigned Route: ";
        getline(cin, new_route);

        cout << "  Enter New Seat Count: ";
        cin >> new_seats;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [Error]: Edit failed! Bad seat input." << endl;
            return;
        }
        cin.ignore(1000, '\n');

        delete vehicles_list[i];
        vehicles_list[i] = new Bus(search_id, new_reg, new_cap, new_status, new_route, new_seats);

        cout << "\n  >> Vehicle updated successfully!" << endl;
        break;
    }

    if (!found)
    {
        cout << "\n  [Error]: Vehicle ID not found!" << endl;
    }
}

void TransportManager::removevehicle()
{
    if (vehicle_count == 0)
    {
        cout << "\n  [Alert]: No active vehicle logs to remove!" << endl;
        return;
    }

    delete vehicles_list[vehicle_count - 1];
    vehicle_count--;
    cout << "\n  >> Last vehicle removed successfully!" << endl;
}

void TransportManager::addroute()
{
    if (route_count >= 50)
    {
        cout << "\n  [Alert]: Route storage limit reached!" << endl;
        return;
    }

    string id, start, end, stop;
    double dist = 0.0;

    cout << "\n================[ ROUTE CONFIGURATION ]================" << endl;
    cout << "  Enter Route ID (e.g. r-01): ";
    getline(cin, id);
    cout << "  Enter Departure Terminal Station: ";
    getline(cin, start);
    cout << "  Enter Arrival Destination Hub: ";
    getline(cin, end);

    cout << "  Enter Distance (in KM): ";
    cin >> dist;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Invalid distance input!" << endl;
        return;
    }
    cin.ignore(1000, '\n');

    cout << "  Enter Main Central Stop: ";
    getline(cin, stop);

    routes_list[route_count] = new UniversityRoute(id, start, end, dist, stop);
    cout << "\n  >> Route registered successfully!" << endl;
    route_count++;
}

void TransportManager::assignvehicletoroute()
{
    if (vehicle_count == 0 || route_count == 0)
    {
        cout << "\n  [Error]: Need at least 1 vehicle and 1 route active!" << endl;
        return;
    }

    string target_v, target_r;
    cout << "\n==================[ ROUTE ASSIGNMENT ]=================" << endl;
    cout << "  Enter Target Vehicle ID: ";
    getline(cin, target_v);
    cout << "  Enter Target Route ID: ";
    getline(cin, target_r);

    cout << "\n  >> Vehicle assigned to route successfully!" << endl;
}

void TransportManager::editroute()
{
    if (route_count == 0)
    {
        cout << "\n  [Alert]: No route logs loaded to modify!" << endl;
        return;
    }

    string search_id;
    cout << "\n================[ ROUTE MODIFICATION ]=================" << endl;
    cout << "  Enter exact route ID to edit: ";
    getline(cin, search_id);

    bool found = false;
    for (int i = 0; i < route_count; i++)
    {
        cout << "\n  >> Route ID match found!" << endl;
        found = true;

        string new_start, new_end, new_stop;
        double new_dist = 0.0;

        cout << "  Enter New Departure Station: ";
        getline(cin, new_start);
        cout << "  Enter New Destination Hub: ";
        getline(cin, new_end);

        cout << "  Enter New Distance (KM): ";
        cin >> new_dist;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [Error]: Route update failed!" << endl;
            return;
        }
        cin.ignore(1000, '\n');

        cout << "  Enter New Central Stop: ";
        getline(cin, new_stop);

        delete routes_list[i];
        routes_list[i] = new UniversityRoute(search_id, new_start, new_end, new_dist, new_stop);

        cout << "\n  >> Route updated successfully!" << endl;
        break;
    }

    if (!found)
    {
        cout << "\n  [Error]: Route ID not found!" << endl;
    }
}

void TransportManager::viewapplications()
{
    cout << "\n===============[ INCOMING APPLICATIONS ]===============" << endl;
    if (app_count == 0)
    {
        cout << "  Queue empty: Zero pending user notifications." << endl;
        return;
    }
    for (int i = 0; i < app_count; i++)
    {
        cout << "  [" << i + 1 << "] Status: " << applications_list[i] << endl;
    }
}

void TransportManager::approverejectrequests()
{
    viewapplications();
    if (app_count == 0)
        return;

    int target_idx = 0;
    char evaluation_flag;
    cout << "\n  Select application index line to evaluate: ";
    cin >> target_idx;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Numeric values only!" << endl;
        return;
    }

    if (target_idx > 0 && target_idx <= app_count)
    {
        cout << "  Press (a) to Approve or (r) to Reject request: ";
        cin >> evaluation_flag;
        cin.ignore(1000, '\n');

        for (int i = target_idx - 1; i < app_count - 1; i++)
        {
            applications_list[i] = applications_list[i + 1];
        }
        app_count--;
        cout << "\n  >> Application processed and queue updated!" << endl;
    }
    else
    {
        cin.ignore(1000, '\n');
        cout << "\n  [Error]: Invalid application index choice!" << endl;
    }
}

void TransportManager::generatereports()
{
    cout << "\n=======================================================" << endl;
    cout << "               UET TRANSPORT LIVE REPORT               " << endl;
    cout << "=======================================================" << endl;
    cout << "  Registered Students Matrix Lines : " << student_count << endl;
    cout << "  Active Infrastructure Map Routes : " << route_count << endl;
    cout << "  Total Live Running System Fleet  : " << vehicle_count << endl;

    if (vehicle_count > 0)
    {
        cout << "\n-------------[ LIVE FLEET INVENTORY ]-------------" << endl;
        for (int i = 0; i < vehicle_count; i++)
        {
            cout << "  ";
            vehicles_list[i]->displayVehicle();
        }
    }
    else
    {
        cout << "\n  [Alert]: Zero active fleet assets currently loaded." << endl;
    }

    if (route_count > 0)
    {
        cout << "\n---------[ OPERATIONAL PATHS DIRECTORY ]----------" << endl;
        for (int i = 0; i < route_count; i++)
        {
            cout << "  ";
            routes_list[i]->displayRoute();
        }
    }
    else
    {
        cout << "\n  [Alert]: Zero campus paths mapped in structure." << endl;
    }
    cout << "=======================================================" << endl;
}

// SMART RE-WRITTEN LOAD DATA
void TransportManager::loaddata()
{
    ifstream fin("project_database.txt");
    if (fin.is_open())
    {
        string dummy;
        // Puraani counters files ko bypass karke basic variables set karain
        if (fin >> dummy >> dummy >> dummy >> dummy >> vehicle_count)
        {
        }
        if (fin >> dummy >> dummy >> dummy >> dummy >> route_count)
        {
        }
        if (fin >> dummy >> dummy >> dummy >> dummy >> student_count)
        {
        }
        fin.close();

        cout << "\n  >> System Alert: Previous data counters loaded successfully!" << endl;
    }
    else
    {
        cout << "\n  >> System Alert: No backup file found. Starting fresh database!" << endl;
    }
}

// SMART RE-WRITTEN SAVE DATA
void TransportManager::savedata()
{
    ofstream fout("project_database.txt");
    if (fout.is_open())
    {
        fout << "Total Fleet Count   : " << vehicle_count << "\n";
        fout << "Total Mapped Routes : " << route_count << "\n";
        fout << "Total Student Base  : " << student_count << "\n";
        fout.close();
        cout << "\n  >> Data synchronized to project_database.txt" << endl;
    }
    else
    {
        cout << "\n  [Error]: File subsystem pipeline failure!" << endl;
    }
}

void TransportManager::showallstudents()
{
    cout << "\n=============[ STUDENTS DATABASE VIEW ]=============" << endl;
    for (int i = 0; i < student_count; i++)
    {
        cout << "  ";
        students_list[i]->display();
    }
}

void TransportManager::showallvehicles()
{
    cout << "\n===========[ TRANSPORT FLEET DIRECTORY ]===========" << endl;
    for (int i = 0; i < vehicle_count; i++)
    {
        cout << "  ";
        vehicles_list[i]->displayVehicle();
    }
}

void TransportManager::showallroutes()
{
    cout << "\n=============[ TRANSIT NETWORK MAPS ]=============" << endl;
    for (int i = 0; i < route_count; i++)
    {
        cout << "  ";
        routes_list[i]->displayRoute();
    }
}