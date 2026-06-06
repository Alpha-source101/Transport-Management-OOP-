
#ifndef STAFFPASSENGER_H      // Header guards duplicate inclusion se bachane ke liye
#define STAFFPASSENGER_H

#include <iostream>
#include <string>
#include "Passenger.h"          // Parent class ki header include ki
using namespace std;

class StaffPassenger : public Passenger {
  private:
      string staffid;
      string jobrole;
      string officeblock;
  public:
      StaffPassenger() ;
      StaffPassenger(string n, int a, string ph, string c, int id, string pickup, string dest, int t,string sid, string role, string block);

      void setstaffid(string sid);
      void setjobrole(string role);
      void setofficeblock(string block);

      string getstaffid();
      string getjobrole();
      string getofficeblock();

      void inputstaff();
      void calculatetransportfee() override;
      void display() override;

      virtual ~StaffPassenger();
};
#endif


/*
                         +----------------------+
                         |      Passenger       |
                         +----------------------+
                                    ▲
                                    |
                               Inheritance
                                    |
                         +----------------------+
                         |    StaffPassenger    |
                         +----------------------+
                         | - staffid : string   |
                         | - jobrole : string   |
                         | - officeblock : string|
                         +----------------------+
                         | + StaffPassenger()   |
                         | + setstaffid()       |
                         | + setjobrole()       |
                         | + setofficeblock()   |
                         | + getstaffid()       |
                         | + getjobrole()       |
                         | + getofficeblock()   |
                         | + inputstaff()       |
                         | + calcfee() override |
                         | + display() override |
                         | + ~StaffPassenger()  |
                         +----------------------+ 
*/
