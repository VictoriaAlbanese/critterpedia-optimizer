////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : active_months.cpp
//
//    Purpose : To represent the active months of an animal
//              in Animal Crossing New Horizons  
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "active_hours.hpp"
#include "active_months.hpp"

using std::cout;
using std::endl;

////////////////////////////////////////////////////////////////////////////////

// Main Functionality

int main(int argc, char * argv[]) 
{
    ActiveMonths active_months;
    ActiveHours active_hours;

    cout << "Active Months : " << active_months << endl;
    cout << "Active Hours : " << active_hours << endl;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
