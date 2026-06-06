#include "Student.h"

Student::Student() : User()
{
    rollnumber = "Unknown";
    department = "Unknown";
    semester = 0;
}

Student::Student(string un, string pass, string n, int a, string ph, string c,
                 string roll, string dept, int sem) 
    : User(un, pass, n, a, ph, c), rollnumber(roll), department(dept), semester(sem) {}

void Student::setrollnumber(string roll){
    rollnumber = roll;     }
void Student::setdepartment(string dept){
    department = dept;    }
void Student::setsemester(int sem){
    semester = sem;    }

string Student::getrollnumber(){
    return rollnumber;     }
string Student::getdepartment(){
    return department;     }
int Student::getsemester(){
    return semester;     }

// Checking credentials for UET Portal login menu
bool Student::login(string un, string pass) {
    return (username == un && password == pass);
}

void Student::inputstudent(){
    // Member 2 ne jo vehicle/route banana hai, yeh input direct uske sath integration mein chalega
    cin.ignore();
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    cout << "Enter Your Name: ";
    getline(cin, name);
    cout << "Enter Your Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter CNIC: ";
    getline(cin, cnic);
    
    // Student ka apna specific data input lo
    cout << "Enter your Rollno (e.g., 2024-CS-101): " << endl;
    getline(cin, rollnumber);
    
    cout << "Enter Your Department: " << endl;
    getline(cin, department);
    
    cout << "Enter Your Current Semester: " << endl;
    cin >> semester;
    
    // End par automatic fee calculation call huja ga 
    calculatetransportfee();
}

void Student::calculatetransportfee() {
    // Member 2 is variable ko direct use kar ke Bill class mein Invoice generate karega (Composition)
    // PDF rule ke mutabiq fee monthly base par calculate karni hai to hum isko split bhi kar sakte hain baad mein
    // Abhi UET structure ke mutabiq total store rakh rahe hain
    transportfee = 3360;             // UET Day Scholar per Semester Fee add ki ha 
}
   
void Student::display(){               //secondly overide //
    User::display();
    cout << "Roll no : " << rollnumber << endl;
    cout << "Department : " << department << endl;
    cout << "Semester : " << semester << endl;
}

Student::~Student()
{
    cout << "Student Destructor Called" << endl;
}