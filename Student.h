#ifndef STUDENT_H
#define STUDENT_H

#include "user.h" // parent class inherit link
class student:public user{
private:        // student ka apna data secure encapsulation mein
    string rollnumber;
    string department;
    int semester;

public:
    student();
    student(string n,int a,string ph,string c,string un,string pass,
            string roll,string dept,int sem);

    string getrollnumber();
    string getdepartment();
    int getsemester();

        ~student() override; `                    //  virtual destructor overriding
        void inputstudent();        
        void display() override;
        bool login(string un,string pass) override; 
};
#endif

/*                                    //BASE THAT INHERIT with Root User
+------------------+
|user|
+------------------+
^
|
inheritance
|
+------------------+
|student|
+------------------+
|-rollnumber:string|
|-department:string|
|-semester:int|
+------------------+
|+student()|
|+student(string,int,string,string,string,string,string,string,int)|
|+getrollnumber()|
|+getdepartment()|
|+getsemester()|
|+~student()override|
|+inputstudent()|
|+display()override|
|+login()override|
+------------------+
*/
