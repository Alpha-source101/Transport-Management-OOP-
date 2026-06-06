#include "admin.h"

admin::admin() : User()
{
    adminid = "Unknown";
}

admin::admin(string un, string pass, string n, int a, string ph, string c, string aid) 
    : User(un, pass, n, a, ph, c), adminid(aid) {}

void admin::setadminid(string aid){
    adminid = aid;     }

string admin::getadminid(){
    return adminid;     }

// Checking credentials for Admin Portal login menu
bool admin::login(string un, string pass) {
    return (username == un && password == pass);
}

void admin::inputadmin(){
    cin.ignore();
    cout << "Enter Admin Username: ";
    getline(cin, username);
    cout << "Enter Admin Password: ";
    getline(cin, password);
    cout << "Enter Admin Name: ";
    getline(cin, name);
    cout << "Enter Admin Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter CNIC: ";
    getline(cin, cnic);
    
    // Admin ka apna specific data input lo
    cout << "Enter your Admin ID (e.g., ADMIN-2026): " << endl;
    getline(cin, adminid);
}
   
void admin::display(){               // Overriding parent display
    User::display();
    cout << "Admin ID : " << adminid << endl;
}

admin::~admin()
{
    cout << "admin Destructor Called" << endl;
}
