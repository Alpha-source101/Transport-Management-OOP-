#include "admin.h"
#include<iostream>
using namespace std;

    admin::admin():user(){
        adminid = "unknown";
    }

    admin::admin(string n,int a,string ph,string c,string un,string pass,string aid)
    :user(n,a,ph,c,un,pass){
            adminid = aid;
    }

void admin::setadminid(string aid){
    adminid = aid;
}

string admin::getadminid(){
    return adminid;
}

                        // core authentication check for office management desk logins
bool admin::login(string un,string pass){
    if(username == un && password == pass){
        return true;
    }else{
        return false;
    }
}

                            // captures personal identity keys from user stream controls
void admin::inputadmin(){
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
void admin::display(){
            user::display();                     // loops up into username base variables output
    cout<<"admin identification string id: "<<adminid<<endl;
}

                                // system garbage destruction handler report trace
admin::~admin(){
    cout<<"admin destructor called safely"<<endl;
}
