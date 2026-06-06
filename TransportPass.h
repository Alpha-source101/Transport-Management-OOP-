#ifndef TRANSPORTPASS_H
#define TRANSPORTPASS_H

#include <iostream>
#include <string>
using namespace std;

class TransportPass {
private:
    string pass_id;
    string issue_date;
    string expiry_date;
    string student_roll;

public:
    TransportPass();
    TransportPass(string pid, string idate, string edate, string roll);
    
    string getpassid();
    string getstudentroll();
    
    void inputpass();
    void displaypass();
};

#endif
