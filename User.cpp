#include "user.h"
#include <iostream>
using namespace std;

user::user(){        // empty constructor , default values
    name="";
    age =0;
    phone ="";
    cnic ="";
    username= "";
    password= "";
}
user::user(string n,int a,string ph,string c,string un,string pass){          
    name = n;
    age = a;
    phone = ph;
    cnic = c;
    username = un;
    password = pass;
}
void user::setname(string n){
    name = n;
}
void user::setage(int a){
    if(a>0 && a<100){ // validation check simple standard model
        age = a;
    }else{
        age = 0;
    }
}
void user::setphone(string ph){
    phone = ph;
}
void user::setcnic(string c){
    cnic = c;
}
void user::setusername(string un){
    username = un;
}

void user::setpassword(string pass){
    password = pass;
}

string user::getname(){            // gettersgive single attributes values
    return name;
}
int user::getage(){
    return age;
}
string user::getphone(){
    return phone;
}

string user::getcnic(){
    return cnic;
}

string user::getusername(){
    return username;
}

string user::getpassword(){
    return password;
}

void user::display(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"phone: "<<phone<<endl;
    cout<<"cnic: "<<cnic<<endl;
    cout<<"username: "<<username<<endl;
}
        // virtual destructor safety clear
user::~user(){
    cout<<"user destructor called"<<endl;
}
