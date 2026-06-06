
#ifndef USER_H      //isa guard kahta ha - prevent karta ha duplicate inclusion karta ha
#define USER_H      // agar nhi define tu karta ha 

#include <iostream>
#include <string>
using namespace std;

class User {
protected:              // protected taky derived classes (Student, Admin) direct use kar sakein
    string username;
    string password;
    string name;
    int age;
    string phone;
    string cnic;

public:             
                        // Constructors (multiple = overloading)
    User();                                      
    User(string un, string pass, string n, int a, string p, string c);  // (Full user) mean para constructor
    
                        // Setters (alag alag value ko input karny ka lya na ky saty akathy)
    void setusername(string un);
    void setpassword(string pass);
    void setname(string n);
    void setage(int a);
    void setphone(string p);
    void setcnic(string c);
    
                        // Getters (hma agar sirf name ya ak chiz ko retreive karna ka lya )
    string getusername();
    string getpassword();
    string getname();
    int getage();
    string getphone();
    string getcnic();

    // Pure Virtual Function for Login (PDF Requirement for Abstract Class)
    virtual bool login(string un, string pass) = 0; 
    
                        // VIRTUAL ka concept = derived classes ka andar isi same name ka function or parameteres ko use karna ka lya 
    virtual void display(); 
    virtual ~User();
};

#endif

                                                    //ROOT KA MAIN :
/*
                                      <<Abstract>>
                +----------------------+
                |         User         |
                +----------------------+
                | # username : string  |
                | # password : string  |
                | # name : string      |
                | # age : int          |
                | # phone : string     |
                | # cnic : string      |
                +----------------------+
                | + User()             |
                | + User(Full Para)    |
                | + setusername()      |
                | + setpassword()      |
                | + setname()          |
                | + setage()           |
                | + setphone()         |
                | + setcnic()          |
                | + getusername()      |
                | + getpassword()      |
                | + getname()          |
                | + getage()           |
                | + getphone()         |
                | + getcnic()          |
                | + virtual login() = 0| <-- Makes it Abstract Base Class
                | + virtual display()  |
                | + virtual ~User()    |
                +----------------------+ 
*/
