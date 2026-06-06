  #include "Transport System.h"

TransportSystem::TransportSystem(string name,int routes,int bookings)
{                               
    system_Name = name;
    total_Routes = routes;
    total_Bookings = bookings;
}

void TransportSystem::generateReport()
{
    cout << "System Report" << endl;
}

TransportSystem::~TransportSystem()
{
}

                


  
