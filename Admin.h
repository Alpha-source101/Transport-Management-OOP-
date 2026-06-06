#ifndef ADMIN_H
#define ADMIN_H
#include "User.h" 
class Admin:public User{
private:        
    string adminid;

public:
    Admin();
    Admin(string n,int a,string ph,string c,string un,string pass,string aid);

    void setadminid(string aid);
    string getadminid();

    ~Admin() override;                  // destructor override 

    void inputadmin();
    void display() override;
    bool login(string un,string pass) override;                 // credentials override matching check
};
#endif

/* //Bae INHERIT FROM USER// base user link ki header file
+------------------+
|user|
+------------------+
^
|
inheritance
|
+------------------+
|admin|
+------------------+
|-adminid:string|
+------------------+
|+admin()|
|+admin(string,int,string,string,string,string,string)|
|+getadminid()|
|+setadminid()|
|+~admin()override|
|+inputadmin()|
|+display()override|
|+login()override|
+------------------+
*/
