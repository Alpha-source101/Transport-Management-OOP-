#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"               // parent class inherit link
class Driver:public User{
private:        // driver ka apna data secure encapsulation mein
    string licensenumber;
    double salary;

public:
    Driver();
    Driver(string n,int a,string ph,string c,string un,string pass,
           string ln,double sal);

    string getlicensenumber();
    double getsalary();
    void setlicensenumber(string ln);
    void setsalary(double sal);

        ~Driver() override;                    //  virtual destructor overriding
        void inputdriver();        
        void display() override;
        bool login(string un,string pass) override; 
};
#endif

/*                             //BASE THAT INHERIT with Root User
+------------------+
|user|
+------------------+
^
|
inheritance
|
+------------------+
|driver|
+------------------+
|-licensenumber:string|
|-salary:double|
+------------------+
|+driver()|
|+driver(string,int,string,string,string,string,string,double)|
|+getlicensenumber()|
|+getsalary()|
|+~driver()override|
|+inputdriver()|
|+display()override|
|+login()override|
+------------------+
*/
