#include "Driver.h"
#include <iostream>
using namespace std;

Driver::Driver():User(){                //defaulty //
    licensenumber="unknown";
    salary=0.0;
}
                            // data directly goes directly as protected in user
Driver::Driver(string n,int a,string ph,string c,string un,string pass,string ln,double sal):User(n,a,ph,c,un,pass){
    licensenumber = ln;
    salary = sal;
}

void Driver::setlicensenumber(string ln){
    licensenumber = ln;
}

void Driver::setsalary(double sal){
    if(sal >= 0.0){
        salary = sal;
    }else{
        salary = 0.0;
    }
}

string Driver::getlicensenumber(){
    return licensenumber;
}

double Driver::getsalary(){
    return salary;
}
                                    // override login portal checking systems matching strings
bool Driver::login(string un,string pass){
    if(username == un && password == pass){                     // parent data variables checked directly
        return true;
    }else{
        return false;
    }
}

void Driver::inputdriver(){
    // parent variables loading directly because of protected structure
    cout<<"enter driver name: ";
    getline(cin,name);
    cout<<"enter driver age: ";
    cin>>age;
    
    if(age<=0 || age>100){             // validation mirror check from user logic
        age = 0;
    }
    
         cin.ignore();                 // cleaning buffer stream
    cout<<"enter driver phone number: ";
    getline(cin,phone);
    
    cout<<"enter driver cnic: ";
    getline(cin,cnic);
    
    cout<<"create driver system username: ";
    getline(cin,username);
    
    cout<<"create driver system password: ";
    getline(cin,password);
    
    // driver unique attributes captured
    cout<<"enter driver official commercial license number: ";
    getline(cin,licensenumber);
    
    cout<<"enter monthly salary allocated (pkr): ";
    cin>>salary;
    cin.ignore(); // safe clearance for next loop chains
}

    void Driver::display(){
        User::display(); // prints name, age, phone, cnic, username automatically
        cout<<"license identification number: "<<licensenumber<<endl;
        cout<<"allocated system salary: "<<salary<<" pkr"<<endl;
    }

                                // object life termination trigger clean message
Driver::~Driver(){
    cout<<"driver destructor called safely"<<endl;
}
