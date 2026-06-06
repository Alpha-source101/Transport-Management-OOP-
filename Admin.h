#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "User.h"          // Parent class include ki
using namespace std;

class admin : public User 
{
private:              // admin ka specific data private rahega encapsulation ke liye
    string adminid;

public:
    // Constructors
    admin();
    
    admin(string un, string pass, string n, int a, string ph, string c, string aid);

    void setadminid(string aid);        // Setter (value set karne ke liye)
    string getadminid();                // Getter (value retrieve karne ke liye)

    // Overriding User class login function (PDF Mandatory Requirement)
    bool login(string un, string pass) override;

    void inputadmin();                    // Admin register karne ke liye
    void display() override;              // Details print karne ke liye
    
    virtual ~admin();                     // Clean pointer deletion ke liye
};

#endif


//UML:
                        +----------------------+
                         |         User         |
                         +----------------------+
                                    ▲
                                    |
                               Inheritance
                                    |
                         +----------------------+
                         |        admin         |
                         +----------------------+
                         | - adminid : string   |
                         +----------------------+
                         | + admin()            |
                         | + login() override   |
                         | + inputadmin()       |
                         | + display() override |
                         | + ~admin()           |
                         +----------------------+
