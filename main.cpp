#include "TransportManager.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    TransportManager manager;
    int portal_choice = 0;

    while (true)
    {
        cout << "\n=====[ uet main transport terminal panel ]=====" << endl;
        cout << "1. admin control portal login\n";
        cout << "2. student services view\n";
        cout << "3. exit core application manager\n";
        cout << "select active screen portal option: ";
        cin >> portal_choice;
        cin.ignore();

        if (portal_choice == 1)
        {
            string input_user;
            string input_pass;

            cout << "\n--- security authentication checkpoint ---" << endl;
            cout << "enter master admin username: ";
            getline(cin, input_user);
            cout << "enter master admin password: ";
            getline(cin, input_pass);

            // strict verification match for specialized secure access shield
            if (input_user == "admin" && input_pass == "uet2026")
            {
                cout << "\naccess granted! welcome to corporate command station." << endl;

                int admin_option = 0;
                while (true)
                {
                    cout << "\n--- admin functional controls console ---" << endl;
                    cout << "1. add vehicle\n";
                    cout << "2. edit vehicle\n";
                    cout << "3. remove vehicle\n";
                    cout << "4. add route\n";
                    cout << "5. edit route\n";
                    cout << "6. assign vehicle to route\n";
                    cout << "7. view applications\n";
                    cout << "8. approve / reject requests\n";
                    cout << "9. generate reports\n";
                    cout << "10. save data\n";
                    cout << "11. logout\n";
                    cout << "enter admin action code: ";
                    cin >> admin_option;
                    cin.ignore();

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
                    } // connects directly to backend logic
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
                        cout << "admin logged out safely" << endl;
                        break;
                    }
                    else
                    {
                        cout << "invalid admin operation option selection" << endl;
                    }
                }
            }
            else
            {
                cout << "security alert: invalid credentials! access denied." << endl;
            }
        }
        else if (portal_choice == 2)
        {
            cout << "\n--- Student View Dashboard panel ---" << endl;
            cout << "displaying operational active route details tracking lists..." << endl;
            manager.showallroutes();
        }
        else if (portal_choice == 3)
        {
            cout << "application runtime state safely closed." << endl;
            break;
        }
        else
        {
            cout << "invalid portal option targeted" << endl;
        }
    }
    return 0;
}
