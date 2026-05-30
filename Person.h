#ifndef PERSON_H      //isa guard kahta ha - prevent karta ha duplicate inclusion karta ha
#define PERSON_H      // agar nhi define tu karta ha 

#include <iostream>
#include <string>
using namespace std;

class Person {
private:              //  taky nobody outside can modify it directly
    string name;
    int age;
    string phone;
    string cnic;

public:             
                          // Constructors (multiple = overloading)
    Person();                                     
    Person(string n, int a, string p, string c);  // (Full person) mean para constructor
    
                                // Setters (alag alag value ko input karny ka lya na ky saty akathy)
    void setname(string n);
    void setage(int a);
    void setphone(string p);
    void setcnic(string c);
    
                                  // Getters (hma agar sirf name ya ak chiz ko retreive karna ka lya )
    string getname();
    int getage();
    string getphone();
    string getcnic();
                              // VIRTUAL ka concept  = derived classes ka andar isi same name ka function or parameteres ko use karna ka lya 
    virtual void display(); 
    virtual ~Person();
};

#endif
