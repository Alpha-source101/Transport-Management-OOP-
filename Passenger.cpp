#include "Passenger.h"
Passenger::Passenger() : Person()
{
    passengerid = 0;
    pickuppoint = "Unknown";
    destination = "Unknown";
    transportfee = 0 ;
}
Passenger::Passenger(string n, int a, string ph,string c,
                     int id, string pickup, string dest,int t)
    : Person(n, a, ph,c)
{
    passengerid = id;
    pickuppoint = pickup;
    destination= dest;
    transportfee =t;
}
void Passenger::setpassengerid(int id)
{
    passengerid = id;
}
void Passenger::setpickuppoint(string pickup)
{
    pickuppoint = pickup;
}
void Passenger::setdestination(string dest)
{
    destination = dest;
}
void Passenger::settransportfee(int t){
    transportfee = t;
}
int Passenger::getpassengerid()
{
    return passengerid;
}
string Passenger::getpickuppoint()
{
    return pickuppoint;
}
string Passenger::getdestination()
{
    return destination;
}
int Passenger::gettransportfee()
{
    return transportfee;
}
void Passenger::inputpassenger()
{
    string n;
    int a;
    string ph;
    string c;
    int t;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, n);
    
    cout << "Enter CNIC: ";
    cin.ignore();
    getline(cin, c);

    cout << "Enter Age: ";
    cin >> a;

    cin.ignore();

    cout << "Enter Phone Number: ";
    getline(cin, ph);

    cout << "Enter Passenger ID: ";
    cin >> passengerid;

    cin.ignore();
    
    cout << "Enter Pickup Point: ";
    getline(cin, pickuppoint);

    cout << "Enter Destination: ";
    getline(cin, destination);

    cout<<"Enter Transportfee: ";
    cin>>transportfee;
    
    setname(n);
    setage(a);
    setphone(ph);
    setcnic(c);

}
void Passenger::calculatetransportfee(){
    transportfee = 0;
}
                    
void Passenger::display()            //overiding
{
    // Calling Parent Display function
    Person::display();

    cout << "Passenger ID: " << passengerid << endl;
    cout << "Pickup Point: " << pickuppoint << endl;
    cout << "Destination: " << destination << endl;
    cout << "Transport Fee :" <<transportfee<<endl;
}

Passenger::~Passenger()
{
    cout << "Passenger Destructor Called" << endl;
}

