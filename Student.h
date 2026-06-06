#ifndef STUDENT_H      // Header guards duplicate inclusion se bachane ke liye
#define STUDENT_H

#include <iostream>
#include <string>
#include "User.h"          // Parent class ki header include ki
using namespace std;

class Student : public User 
{
private:              // Student ka apna data private rahega encapsulation ke liye
    string rollnumber;
    string department;
    int semester;

public:
    // Constructors
    Student();
    
    Student(string un, string pass, string n, int a, string ph, string c,
            string roll, string dept, int sem);

    void setrollnumber(string roll);        // Setters (alag se value set karne ke liye)
    void setdepartment(string dept);
    void setsemester(int sem);

    string getrollnumber();                // Getters (single value retrieve karne ke liye)
    string getdepartment();
    int getsemester();

    // Overriding User class login function (PDF Mandatory Requirement)
    bool login(string un, string pass) override;

    void inputstudent();                          // Complete data input lene ke liye
    void calculatetransportfee() override;        // Fixed UET 3360 fee lagane ke liye override kiya
    void display() override;                      // Sub details hierarchy ke sath print karne ke liye
    
    virtual ~Student();                  // Compiler/Linker safety aur clean pointer deletion ke liye
};
#endif

/*
                         +----------------------+
                         |         User         |
                         +----------------------+
                                    ▲
                                    |
                               Inheritance
                                    |
                         +----------------------+
                         |       Student        |
                         +----------------------+
                         | - rollnumber : string|
                         | - department : string|
                         | - semester : int     |
                         +----------------------+
                         | + Student()          |
                         | + login() override   |
                         | + setrollnumber()    |
                         | + setdepartment()    |
                         | + setsemester()      |
                         | + getrollnumber()    |
                         | + getdepartment()    |
                         | + getsemester()      |
                         | + inputstudent()     |
                         | + calcfee() override |
                         | + display() override |
                         | + ~Student()         |
                         +----------------------+ 
*/