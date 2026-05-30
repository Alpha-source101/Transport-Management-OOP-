
#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Passenger : public Person
{
protected:
    int passengerid;
    string pickuppoint;
    string destination;
    int transportfee;
public:
    Passenger();

    // Parameterized Constructor
    Passenger(string n, int a, string ph,
              int id, string pickup, string dest,int t);

    void setpassengerid(int id);          //set karny ka lya values
    void setpickuppoint(string pickup);
    void setdestination(string dest);
      void settransportfee(int t);

int getpassengerid();           //single retreive ka lya 
    string getpickuppoint();
    string getdestination();
      int transportfee();
    
    void inputpassenger();    //input all
    void transportfee();
    void display();             //display kary ga all      ----> its override used
    ~Passenger();
};
#endif


                                        # Passenger.cpp
#include "Passenger.h"
Passenger::Passenger() : Person()
{
    passengerid = 0;
    pickuppoint = "Unknown";
    destination = "Unknown";
    transportfee = 0 ;
}
Passenger::Passenger(string n, int a, string ph,
                     int id, string pickup, string dest,int t)
    : Person(n, a, ph)
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

// Getter for Destination
string Passenger::getDestination()
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
    int t;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, n);

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
    // Parent setters
    setame(n);
    setAge(a);
    setPhone(ph);
}

// Display Function (OVERRIDING)
void Passenger::display()
{
    // Calling Parent Display Function
    Person::display();

    cout << "Passenger ID: " << passengerID << endl;
    cout << "Pickup Point: " << pickupPoint << endl;
    cout << "Destination: " << destination << endl;
}

// Destructor
Passenger::~Passenger()
{
    cout << "Passenger Destructor Called" << endl;
}
```

---

# REQUIRED Person Class Features

Your Person class MUST already contain:

```cpp
private:
    string name;
    int age;
    string phone;
```

And these functions:

```cpp
Person();
Person(string n, int a, string ph);

void setName(string n);
void setAge(int a);
void setPhone(string ph);

string getName();
int getAge();
string getPhone();

virtual void display();
```

---

# MOST IMPORTANT OOP THINGS HAPPENING HERE

## 1. Inheritance

```cpp
class Passenger : public Person
```

Meaning:

```text
Passenger IS-A Person
```

---

## 2. Parent Constructor Call

```cpp
: Person(n, a, ph)
```

Meaning:

```text
First initialize Person part
Then Passenger part
```

---

## 3. Function Overriding

```cpp
void Passenger::display()
```

This overrides Person display.

---

## 4. Parent Function Call

```cpp
Person::display();
```

Meaning:

```text
Run Person display first
Then show Passenger extra data
```

---

# HOW TO TEST IN main.cpp

```cpp
Passenger p1;

p1.inputPassenger();

cout << "\n===== PASSENGER DETAILS =====\n";

p1.display();
```

---

# SAMPLE OUTPUT

```text
Enter Name: Ali
Enter Age: 20
Enter Phone Number: 03123456789
Enter Passenger ID: 101
Enter Pickup Point: UET Gate
Enter Destination: Lahore Station

===== PASSENGER DETAILS =====
Name: Ali
Age: 20
Phone: 03123456789
Passenger ID: 101
Pickup Point: UET Gate
Destination: Lahore Station
```

---

# WHY THIS STRUCTURE IS GOOD FOR UNIVERSITY

This single class demonstrates:

✅ Encapsulation
✅ Inheritance
✅ Constructor Chaining
✅ Function Overriding
✅ Polymorphism Base
✅ Header/CPP Separation
✅ OOP Design
✅ Real-World Modeling

