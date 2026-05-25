#include "Person.h"
#include <iostream>
using namespace std;
                                // EMPTY constructor
Person::Person(){
    name = "";
    age = 0;
    phone = "";
    cnic = "";
                      // Why empty , For when you create person first, fill data later
}
                                        // para constructor
Person::Person(string n, int a, string p, string c){
    name = n;
    age = a;
    phone = p ;
    cnic = c ;
 }
                                          // SETTERS - to set values of data alonly also
void Person::setname(string n ) {
    name = n; // For Private use : take value ? store in private variable
}
void Person :: setage(int a){
    if( a>0 && a<100 ) {  // Validation!so koe aam apny sa age na likh saca .
        age = a;
    } else {
        age = 0;  // Defaultly , set ujai at wrong input 
    }
}

void Person::setphone(string p) {
    phone = p;}
void Person::setcnic(string c){
    cnic = c;
}										// Getters used if i wanna retreive single value .
string Person::getname(){
    return name;
}
int Person::getage(){
    return age;
}
string Person::getphone() {
    return phone;
}
string Person::getcnic(){
    return cnic;
}
void Person::display() {
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Phone:" <<phone<<endl;
    cout<<"CNIC: "<<cnic<<endl;
}
