#include "Admin.h"
#include<iostream>
using namespace std;

    Admin::Admin():User(){
        adminid = "unknown";
    }

    Admin::Admin(string n,int a,string ph,string c,string un,string pass,string aid)
    :User(n,a,ph,c,un,pass){
            adminid = aid;
    }

void Admin::setadminid(string aid){
    adminid = aid;
}

string Admin::getadminid(){
    return adminid;
}

                        // core authentication check for office management desk logins
bool Admin::login(string un,string pass){
    if(username == un && password == pass){
        return true;
    }else{
        return false;
    }
}

                            // captures personal identity keys from user stream controls
void Admin::inputadmin(){
    cout<<"enter admin name: ";
    getline(cin,name);
    
    cout<<"enter admin age: ";
    cin>>age;
    
    if(age<=0 || age>100){                     // standard protection limits safety
        age = 0;
    }
    
    cin.ignore();
    cout<<"enter admin phone number: ";
    getline(cin,phone);
    
    cout<<"enter admin cnic card number: ";
    getline(cin,cnic);
    
    cout<<"create admin office username: ";
    getline(cin,username);
    
    cout<<"create admin office password: ";
    getline(cin,password);
    
    cout<<"enter office admin id reference (e.g., adm-2026): ";
    getline(cin,adminid);
}

                            // prints administrative console metrics safely
void Admin::display(){
            User::display();                     // loops up into username base variables output
    cout<<"admin identification string id: "<<adminid<<endl;
}

                                // system garbage destruction handler report trace
Admin::~Admin(){
    cout<<"admin destructor called safely"<<endl;
}
