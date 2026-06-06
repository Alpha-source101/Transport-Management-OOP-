#ifndef STUDENTPASSENGER_H      // Header guards duplicate inclusion se bachane ke liye
#define STUDENTPASSENGER_H

#include <iostream>
#include <string>
#include "Passenger.h"          // Parent class ki header include ki
using namespace std;

class StudentPassenger : public Passenger 
{
private:              // Student ka apna data private rahega encapsulation ke liye
    string rollnumber;
    string department;
    int semester;

public:
    // Constructors
    StudentPassenger();
    
    StudentPassenger(string n, int a, string ph, string c,
                     int id, string pickup, string dest, int t,
                     string roll, string dept, int sem);

    void setrollnumber(string roll);        // Setters (alag se value set karne ke liye)
    void setdepartment(string dept);
    void setsemester(int sem);

    string getrollnumber();                // Getters (single value retrieve karne ke liye)
    string getdepartment();
    int getsemester();

    void inputstudent();                          // Complete data input lene ke liye
    void calculatetransportfee() override;        // Fixed UET 3360 fee lagane ke liye override kiya
    void display() override;                      // Sub details hierarchy ke sath print karne ke liye
    
    virtual ~StudentPassenger();                  // Compiler/Linker safety aur clean pointer deletion ke liye};
#endif

/*
                         +----------------------+
                         |      Passenger       |
                         +----------------------+
                                    ▲
                                    |
                               Inheritance
                                    |
                         +----------------------+
                         |   StudentPassenger   |
                         +----------------------+
                         | - rollnumber : string|
                         | - department : string|
                         | - semester : int     |
                         +----------------------+
                         | + StudentPassenger() |
                         | + setrollnumber()    |
                         | + setdepartment()    |
                         | + setsemester()      |
                         | + getrollnumber()    |
                         | + getdepartment()    |
                         | + getsemester()      |
                         | + inputstudent()     |
                         | + calcfee() override |
                         | + display() override |
                         | + ~StudentPassenger()|
                         +----------------------+ 
*/
