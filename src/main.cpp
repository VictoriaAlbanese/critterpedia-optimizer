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
    vector<int> months;
    months.push_back(4);
    months.push_back(5);
    months.push_back(6);
    months.push_back(10);
    months.push_back(11);
    months.push_back(12);
    months.push_back(1);
    months.push_back(2);
    ActiveMonths active_months(months);
    cout << "Active Months : " << active_months << endl;
    
    vector<int> hours;
    hours.push_back(9);
    hours.push_back(10);
    hours.push_back(11);
    hours.push_back(12);
    hours.push_back(13);
    hours.push_back(14);
    hours.push_back(15);
    hours.push_back(22);
    hours.push_back(23);
    hours.push_back(24);
    hours.push_back(1);
    hours.push_back(2);
    ActiveHours active_hours(hours);
    cout << "Active Hours : " << active_hours << endl;

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
