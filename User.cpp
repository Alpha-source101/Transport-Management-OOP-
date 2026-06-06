#include "User.h"
#include <iostream>
using namespace std;

User::User(){
    username = "Unknown";
    password = "Unknown";
    name = "";
    age = 0;
    phone = "";
    cnic = "";
                      // Why empty , For when you create user first, fill data later
}

                                        // para constructor
User::User(string un, string pass, string n, int a, string p, string c){
    username = un;
    password = pass;
    name = n;
    age = a;
    phone = p;
    cnic = c;
}

                                          // SETTERS - to set values of data alonly also
void User::setusername(string un) {
    username = un;
}
void User::setpassword(string pass) {
    password = pass;
}
void User::setname(string n) {
    name = n; // For Private use : take value ? store in private variable
}
void User::setage(int a){
    if( a>0 && a<100 ) {  // Validation!so koe aam apny sa age na likh saca .
        age = a;
    } else {
        age = 0;  // Defaultly , set ujai at wrong input 
    }
}
void User::setphone(string p) {
    phone = p;
}
void User::setcnic(string c){
    cnic = c;
}

                                        // Getters used if i wanna retreive single value .
string User::getusername() {
    return username;
}
string User::getpassword() {
    return password;
}
string User::getname(){
    return name;
}
int User::getage(){
    return age;
}
string User::getphone() {
    return phone;
}
string User::getcnic(){
    return cnic;
}

void User::display() {
    cout<<"Username: "<<username<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Phone: " <<phone<<endl;
    cout<<"CNIC: "<<cnic<<endl;
}

User::~User()
{
    cout << "User Destructor Called" << endl;
}
