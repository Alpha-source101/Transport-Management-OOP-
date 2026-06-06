#include "StaffPassenger.h"
StaffPassenger::StaffPassenger() : Passenger()
{
    staffid= "Unknown";
    jobrole = "Unknown";
    officeblock = "Unknown";
}

StaffPassenger::StaffPassenger(string n, int a, string ph, string c,
                               int id, string pickup, string dest, int t,
                               string sid, string role, string block) 
    : Passenger(n,a, ph, c,id,pickup, dest,t), staffid(sid),jobrole(role),officeblock(block)
{}

void StaffPassenger::setstaffid(string sid) {
    staffid = sid;
}

void StaffPassenger::setjobrole(string role) {
    jobrole = role;
}

void StaffPassenger::setofficeblock(string block) {
    officeblock = block;
}

string StaffPassenger::getstaffid() {
    return staffid;
}

string StaffPassenger::getjobrole() {
    return jobrole;
}

string StaffPassenger::getofficeblock() {
    return officeblock;
}

void StaffPassenger::inputstaff() {
    Passenger::inputpassenger();
    
    // Integer input ke baad buffer clear karne ke liye
    cin.ignore();
    
    // Staff ka apna specific data input
    cout << "Enter Staff ID: " << endl;
    getline(cin, staffid);
    
    cout << "Enter Job Role (e.g.Clerk,Lab Attendant): " << endl;
    getline(cin, jobrole);
    
    cout << "Enter Office Block (e.g., Admin Block, Block-A): " << endl;
    getline(cin, officeblock);
    
    // Automatic fixed fee calculation call
    calculatetransportfee();
}

void StaffPassenger::calculatetransportfee() {
    transportfee = 1500; // Fixed subsidized semester pass for UET staff
}

void StaffPassenger::display() {                         
                        //display all ,in hirarichical substitization Pehle parent ka data screen par print Phir staff ki apni details print kareg
    Passenger::display();
    cout << "Staff ID: " << staffid << endl;
    cout << "Job Role: " << jobrole << endl;
    cout << "Office Block: " << officeblock << endl;
    cout << "-----------------------------------" << endl;
}

StaffPassenger::~StaffPassenger() {
    cout << "StaffPassenger Destructor Called" << endl;
}
