#include "User.h"
#include <iostream>
using namespace std;

User::User(){               // empty constructor , default values
    name="";
    age =0;
    phone ="";
    cnic ="";
    username= "";
    password= "";
}
User::User(string n,int a,string ph,string c,string un,string pass){
    name = n;
    age = a;
    phone = ph;
    cnic = c;
    username = un;
    password = pass;
}
void User::setname(string n){
    name = n;
}
void User::setage(int a){
    if(a>0 && a<100){ // validation check simple standard model
        age = a;
    }else{
        age = 0;
    }
}
void User::setphone(string ph){
    phone = ph;
}
void User::setcnic(string c){
    cnic = c;
}
void User::setusername(string un){
    username = un;
}

void User::setpassword(string pass){
    password = pass;
}

string User::getname(){            // gettersgive single attributes values
    return name;
}
int User::getage(){
    return age;
}
string User::getphone(){
    return phone;
}

string User::getcnic(){
    return cnic;
}

string User::getusername(){
    return username;
}

string User::getpassword(){
    return password;
}

void User::display(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"phone: "<<phone<<endl;
    cout<<"cnic: "<<cnic<<endl;
    cout<<"username: "<<username<<endl;
}
        // virtual destructor safety clear
User::~User(){
    cout<<"user destructor called"<<endl;
}
