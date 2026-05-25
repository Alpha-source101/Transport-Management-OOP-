#include <iostream>
#include "Person.h" // Include your header file
#include "Person.cpp"
int main() {
    // Calling the parametric constructor to create objects
    Person p1("Bilal", 1022,"02335456","3545365645");
    Person p2("Honda", 2025,"08438494","3259574646");

    // Calling the method for each object
    p1.display();
    p1.setage(2025);
    cout<<"Age is not big than 100 , if yes then default show 0 "<<endl;
    p1.display();
    p2.display();

    return 0;
}
