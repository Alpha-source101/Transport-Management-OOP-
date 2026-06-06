#include "TransportManager.h"
#include <iostream>
using namespace std;

int main() {
    TransportManager manager;
    int choice = 0;
    
    while(true) {
        cout << "\n====={ uet Transit system main desk }=====" << endl;
        cout << "1. register student profile\n";
        cout << "2. issue network transport pass\n";
        cout << "3. register new fleet infrastructure (bus/van/routes)\n";
        cout << "4. print global tracking metrics lists\n";
        cout << "5. shut down terminal dashboard application\n";
        cout << "enter terminal route option choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            manager.addstudent();
        }
        else if(choice == 2) {
            manager.issuepass();
        }
        else if(choice == 3) {
            manager.addbus();
            manager.addroute();
        }
        else if(choice == 4) {
            manager.showallstudents();
            manager.showallpasses();
        }
        else if(choice == 5) {
            cout << "system memory flushed safely. exiting application frame..." << endl;
            break;
        }
        else {
            cout << "invalid selection retry parameters input sequence" << endl;
        }
    }
    return 0;
}
