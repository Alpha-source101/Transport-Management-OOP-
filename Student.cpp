#include "Student.h"
#include <iostream>
using namespace std;

Student::student():User(){                //defaulty //
    rollnumber="unknown";
    department="unknown";
    semester =0;
}
                            // data directly goes directly as protected in user
Student::Student(string n,int a,string ph,string c,string un,string pass,string roll,string dept,int sem):User(n,a,ph,c,un,pass){
    rollnumber = roll;
    department = dept;
    semester = sem;
}

string Student::getrollnumber(){
    return rollnumber;
}
string Student::getdepartment(){
    return department;
}
int Student::getsemester(){
    return semester;
}
                                    // override login portal checking systems matching strings
bool Student::login(string un,string pass){
    if(username == un && password == pass){                     // parent data variables checked directly
        return true;
    }else{
        return false;
    }
}

void Student::inputstudent(){
    // parent variables loading directly because of protected structure
    cout<<"enter student name: ";
    getline(cin,name);
    cout<<"enter student age: ";
    cin>>age;
    
    if(age<=0 || age>100){             // validation mirror check from user logic
        age = 0;
    }
    
         cin.ignore();                 // cleaning buffer stream
    cout<<"enter student phone number: ";
    getline(cin,phone);
    
    cout<<"enter student cnic: ";
    getline(cin,cnic);
    
    cout<<"create student system username: ";
    getline(cin,username);
    
    cout<<"create student system password: ";
    getline(cin,password);
    
    // student unique attributes captured
    cout<<"enter roll number (e.g., 2024-cs-101): ";
    getline(cin,rollnumber);
    
    cout<<"enter student department: ";
    getline(cin,department);
    
    cout<<"enter current student semester: ";
    cin>>semester;
    cin.ignore(); // safe clearance for next loop chains
}

    void Student::display(){
        User::display(); // prints name, age, phone, cnic, username automatically
        cout<<"roll number: "<<rollnumber<<endl;
        cout<<"department: "<<department<<endl;
        cout<<"semester: "<<semester<<endl;
    }

                                // object life termination trigger clean message
Student::~Student(){
    cout<<"student destructor called safely"<<endl;
}
