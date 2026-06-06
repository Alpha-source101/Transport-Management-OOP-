include "StudentPassenger.h"
    StudentPassenger::StudentPassenger() : Passenger()
{
    rollnumber = "Unknown";
    department = "Unknown";
    semester = 0 ;
}

     StudentPassenger :: StudentPassenger(string n, int a, string ph, string c,
                     int id, string pickup, string dest, int t,
                     string roll, string dept, int sem) : Passenger(n,a,ph,c,id,pickup,dest,t) ,rollnumber(roll),department(dept),semester(sem){}

void StudentPassenger :: setrollnumber(string roll){
        rollnumber = roll;     }
void StudentPassenger :: setdepartment(string dept){
                department =dept ;    }
void StudentPassenger :: setsemester(string sem){
        semester = sem;    }


   string StudentPassenger :: getrollnumber(){
        return rollnumber;     }
   string StudentPassenger :: getdepartment(){
        return department;     }
   int StudentPassenger :: getsemester(){
        return semester;     }

    void StudentPassenger::inputstudent(){
                                          // Parent class ka input function call karo.Yeh automatic user se Name, Age, Phone, CNIC, ID, Pickup, aur Destination mangega.
    Passenger::inputpassenger();
                                        // Ab buffer safety ke liye cin.ignore() lagao,  kyun ke parent function 'transportfee' (integer) par khatam hua tha.
    cin.ignore();
                                                // Student ka apna specific data input lo
    cout<<"Enter your Rollno (e.g., 2024-CS-101): " << endl;
    getline(cin, rollnumber);
    
    cout<<"Enter Your Department: "<<endl;
    getline(cin, department);
    
    cout<<"Enter Your Current Semester: "<<endl;
    cin >> semester;
                                            //End par automatic fee calculation call huja ga 
    calculatetransportfee();
}

void StudentPassenger::calculatetransportfee() {
                transportfee = 3360;             // UET Day Scholar per Semester Fee add ki ha 
}
   
void StudentPassenger::display(){               //secondly overide //
    Passenger::display();
    cout<<"Roll no : "<<rollnumber<<endl;
    cout<<"Department : "<<department<<endl;
    cout<<"Semester : "<<semester<<endl;
}

// StudentPassenger.cpp ke bilkul end par yeh add kar lo:
StudentPassenger::~StudentPassenger()
{
    cout << "StudentPassenger Destructor Called" << endl;
}




                                                          //Extra i do :
// void StudentPassenger::inputstudent(){
//         string roll; string dept; int sem ;
//         string n;     
//         int a;        
//         string ph;    
//         string c;     
//         int id;       
//         string pickup;
//         string dest;  
//     cout << "Enter your Rollno : "<<endl;
//     cin.ignore();
//     getline(cin, roll);
//     cout << "Enter Your Department : "<<endl;
//     cin.ignore();
//     getline(cin, dept);
//     cout<<"Enter Your Current Semester(1/2) : "<<endl;
//     cin>>sem;

//     setname(n);
//     setage(a);
//     setphone(ph);
//     setcnic(c);
//     setpassengerid(id);
//     setpickuppoint(pickup);
//     setdestination( dest);
//     settransportfee(t);
//     rollnumber = roll;
//     department = dept;
//     semester = sem;

//     //End par automatic fee calculation call
//     calculatetransportfee();
// }

