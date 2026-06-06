#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

class user{
    protected:      // niche waali classes use kar sakein gi direct
        string name;
        int age;
        string phone;
        string cnic;
        string username;
        string password;

    public:
        user();
        user(string n,int a,string ph,string c,string un,string pass);
    
    void setname(string n);            // setters alag alag value set karne k lya
    void setage(int a);
    void setphone(string ph);
    void setcnic(string c);
    void setusername(string un);
    void setpassword(string pass);

    // getters data retrieve karne k lya
    string getname();
    int getage();
    string getphone();
    string getcnic();
    string getusername();
    string getpassword();

    virtual ~user();         // destructor for safety no leakage
    
    virtual void display(); 
    virtual bool login(string un,string pass)=0;         // pure virtual function login abstract bana rha ha
};
#endif

/*
                                                <<abstract class>>
+------------------+
       |user|
+------------------+
|#name:string|
|#age:int|
|#phone:string|
|#cnic:string|
|#username:string|
|#password:string|
+------------------+
|+user()|
|+user(string,int,string,string,string,string)|
|+setname()|
|+setage()|
|+setphone()|
|+setcnic()|
|+getname()|
|+getage()|
|+getphone()|
|+getcnic()|
|+virtual~user()|
|+virtualdisplay()|
|+virtuallogin()=0|
+------------------+
*/
