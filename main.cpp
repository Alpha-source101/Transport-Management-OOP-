#include "TransportManager.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    TransportManager manager;
    int portal_choice = 0;

    //  Program start hote hi sab se pehle purana data file se uthaye ga
    manager.loaddata();

    while (true)
    {
        // Centered Main Menu
        cout << "\n=======================================================" << endl;
        cout << "                       MAIN MENU                       " << endl;
        cout << "=======================================================" << endl;
        cout << "  [1] Admin Login" << endl;
        cout << "  [2] Student View" << endl;
        cout << "  [3] Exit" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "  Select option: ";
        cin >> portal_choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [Error]: Enter numbers (1-3) only!" << endl;
            continue;
        }
        cin.ignore(1000, '\n');

        if (portal_choice == 1)
        {
            string input_user = "";
            string input_pass = "";

            cout << "\n=================[ ADMIN LOGIN PORTAL ]================" << endl;
            cout << "  Username: ";
            getline(cin, input_user);
            cout << "  Password: ";
            getline(cin, input_pass);

            if (input_user == "admin" && input_pass == "uet2026")
            {
                cout << "\n  >> Access Granted! Welcome." << endl;

                int admin_option = 0;
                while (true)
                {
                    cout << "\n================[ ADMIN CONTROL PANEL ]================" << endl;
                    cout << "  1. Add Vehicle\n";
                    cout << "  2. Edit Vehicle\n";
                    cout << "  3. Remove Vehicle\n";
                    cout << "  4. Add Route\n";
                    cout << "  5. Edit Route\n";
                    cout << "  6. Assign Route\n";
                    cout << "  7. View Applications\n";
                    cout << "  8. Process Application\n";
                    cout << "  9. Generate Reports\n";
                    cout << "  10. Save Data\n";
                    cout << "  11. Logout\n";
                    cout << "-------------------------------------------------------" << endl;
                    cout << "  Enter option: ";
                    cin >> admin_option;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\n  [Error]: Enter numbers (1-11) only!" << endl;
                        continue;
                    }
                    cin.ignore(1000, '\n');

                    if (admin_option == 1)
                    {
                        manager.addvehicle();
                    }
                    else if (admin_option == 2)
                    {
                        manager.editvehicle();
                    }
                    else if (admin_option == 3)
                    {
                        manager.removevehicle();
                    }
                    else if (admin_option == 4)
                    {
                        manager.addroute();
                    }
                    else if (admin_option == 5)
                    {
                        manager.editroute();
                    }
                    else if (admin_option == 6)
                    {
                        manager.assignvehicletoroute();
                    }
                    else if (admin_option == 7)
                    {
                        manager.viewapplications();
                    }
                    else if (admin_option == 8)
                    {
                        manager.approverejectrequests();
                    }
                    else if (admin_option == 9)
                    {
                        manager.generatereports();
                    }
                    else if (admin_option == 10)
                    {
                        manager.savedata();
                    }
                    else if (admin_option == 11)
                    {
                        cout << "\n  >> Logged out successfully!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "\n  [Error]: Invalid option selection!" << endl;
                    }
                }
            }
            else
            {
                cout << "\n  [Denied]: Invalid credentials!" << endl;
            }
        }
        else if (portal_choice == 2)
        {
            cout << "\n=================[ STUDENT DASHBOARD ]=================" << endl;
            manager.showallroutes();

            cout << "-------------------------------------------------------" << endl;
            cout << "  Press Enter to go back to Main Menu...";
            cin.get();
        }
        else if (portal_choice == 3)
        {
            cout << "\n  >> Management session ended successfully." << endl;
            break;
        }
        else
        {
            cout << "\n  [Error]: Invalid selection!" << endl;
        }
    }
    return 0;
}