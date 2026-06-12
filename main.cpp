#include "TransportManager.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    // VS Code Terminal ko fresh aur raw white color par start karne ke liye
    cout << "\033[0m";
    system("cls");

    TransportManager manager;
    int portal_choice = 0;

    // Program start hote hi sab se pehle purana data file se uthaye ga
    manager.loaddata();

    while (true)
    {
        // 🟡 MAIN MENU: FORCE YELLOW COLOR
        cout << "\033[33m";
        cout << "\n=======================================================" << endl;
        cout << "                    MAIN MENU                          " << endl;
        cout << "=======================================================" << endl;
        cout << "  [1] Admin Login" << endl;
        cout << "  [2] Student View" << endl;
        cout << "  [3] Exit" << endl;
        cout << "-------------------------------------------------------" << endl;

        // 🌸 OPTION SELECTION: FORCE PINK COLOR
        cout << "\033[35m";
        cout << "  Select option: ";
        cin >> portal_choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n  [Error]: Enter numbers (1-3) only!" << endl;
            cout << "\033[0m"; // Reset to default safely
            continue;
        }
        cin.ignore(1000, '\n');

        if (portal_choice == 1)
        {
            string input_user = "";
            string input_pass = "";

            // 🟡 ADMIN LOGIN TITLE: FORCE YELLOW COLOR
            cout << "\033[33m";
            cout << "\n=================[ ADMIN LOGIN PORTAL ]================" << endl;

            // 🌸 CREDENTIALS INPUT: FORCE PINK COLOR
            cout << "\033[35m";
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
                    // 🟡 ADMIN CONTROL PANEL: FORCE YELLOW COLOR
                    cout << "\033[33m";
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

                    // 🌸 ADMIN CHOICE INPUT: FORCE PINK COLOR
                    cout << "\033[35m";
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

                    // Reset background strings to default white before launching functions
                    cout << "\033[0m";

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
                        cout << "\033[35m"; // Pink logout alert
                        cout << "\n  >> Logged out successfully!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "\033[35m";
                        cout << "\n  [Error]: Invalid option selection!" << endl;
                    }
                }
            }
            else
            {
                cout << "\033[35m";
                cout << "\n  [Denied]: Invalid credentials!" << endl;
            }
        }
        else if (portal_choice == 2)
        {
            // 🟡 STUDENT DASHBOARD: FORCE YELLOW COLOR
            cout << "\033[33m";
            cout << "\n=================[ STUDENT DASHBOARD ]=================" << endl;

            cout << "\033[0m"; // Reset colors so internal vectors look crisp
            manager.showallroutes();

            cout << "\033[33m"; // Return to yellow for borders
            cout << "-------------------------------------------------------" << endl;

            cout << "\033[35m"; // Pink for return prompt
            cout << "  Press Enter to go back to Main Menu...";
            cin.get();
        }
        else if (portal_choice == 3)
        {
            cout << "\033[35m";
            cout << "\n  >> Management session ended successfully." << endl;
            cout << "\033[0m"; // Complete system reset on shutdown
            break;
        }
        else
        {
            cout << "\033[35m";
            cout << "\n  [Error]: Invalid selection!" << endl;
        }
    }
    return 0;
}