//StudentPassenger.h

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

    // Setters (alag se value set karne ke liye)
    void setrollnumber(string roll);
    void setdepartment(string dept);
    void setsemester(int sem);

    // Getters (single value retrieve karne ke liye)
    string getrollnumber();
    string getdepartment();
    int getsemester();

    // Core Functions
    void inputstudent();                          // Student ka details input lene ke liye
    void calculatetransportfee(int distance) override; // Fee par discount lagane ke liye override kiya
    void display() override;                      // Sub details print karne ke liye
    
    virtual ~StudentPassenger();                  // Safe cleanup ke liye virtual destructor
};

#endif
