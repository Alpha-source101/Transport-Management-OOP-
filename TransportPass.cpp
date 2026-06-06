#include "TransportPass.h"

TransportPass::TransportPass() {
    pass_id = "unknown";
    issue_date = "unknown";
    expiry_date = "unknown";
    student_roll = "unknown";
}

TransportPass::TransportPass(string pid, string idate, string edate, string roll) {
    pass_id = pid;
    issue_date = idate;
    expiry_date = edate;
    student_roll = roll;
}

string TransportPass::getpassid() {
    return pass_id;
}

string TransportPass::getstudentroll() {
    return student_roll;
}

void TransportPass::inputpass() {
    cout << "enter pass identification id: ";
    getline(cin, pass_id);
    cout << "enter card issue date (dd-mm-yyyy): ";
    getline(cin, issue_date);
    cout << "enter card expiry date (dd-mm-yyyy): ";
    getline(cin, expiry_date);
    cout << "enter holder student roll number: ";
    getline(cin, student_roll);
}

void TransportPass::displaypass() {
    cout << "\n===== TRANSPORT PASS CARD =====" << endl;
    cout << "pass serial id: " << pass_id << endl;
    cout << "allotted issue date: " << issue_date << endl;
    cout << "card system expiry: " << expiry_date << endl;
    cout << "bound student roll: " << student_roll << endl;
}
