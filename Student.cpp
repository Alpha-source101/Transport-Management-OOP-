#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : User()
{
    rollnumber = "unknown";
    department = "unknown";
    semester = 0;
}

Student::Student(string n, int a, string ph, string c, string un, string pass, string roll, string dept, int sem)
    : User(n, a, ph, c, un, pass)
{
    rollnumber = roll;
    department = dept;
    semester = sem;
}

string Student::getrollnumber()
{
    return rollnumber;
}
string Student::getdepartment()
{
    return department;
}
int Student::getsemester()
{
    return semester;
}

bool Student::login(string un, string pass)
{
    if (username == un && password == pass)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Student::inputstudent()
{
    cout << "enter student name: ";
    getline(cin, name);
    cout << "enter student age: ";
    cin >> age;

    if (age <= 0 || age > 100)
    {
        age = 0;
    }

    cin.ignore();
    cout << "enter student phone number: ";
    getline(cin, phone);

    cout << "enter student cnic: ";
    getline(cin, cnic);

    cout << "create student system username: ";
    getline(cin, username);

    cout << "create student system password: ";
    getline(cin, password);

    cout << "enter roll number (e.g., 2024-cs-101): ";
    getline(cin, rollnumber);

    cout << "enter student department: ";
    getline(cin, department);

    cout << "enter current student semester: ";
    cin >> semester;
    cin.ignore();
}

void Student::display()
{
    User::display();
    cout << "roll number: " << rollnumber << endl;
    cout << "department: " << department << endl;
    cout << "semester: " << semester << endl;
}

Student::~Student()
{
    cout << "student destructor called safely" << endl;
}