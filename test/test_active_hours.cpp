////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : test_active_hours.cpp
//
//    Purpose : To test the active_hours class
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../src/active_hours.hpp"

using std::cout;
using std::endl;
using std::vector;

////////////////////////////////////////////////////////////////////////////////

// Unit Tests

TEST(ActiveHoursTest, DefaultConstructor) 
{ 
    ActiveHours active_hours;
    
    for (int i = 1; i <= 24; i++)
    {
        ASSERT_EQ(true, active_hours.is_hour_active(i));
    }   
}

TEST(ActiveHoursTest, CustomConstructor) 
{
    vector<int> hours;
    hours.push_back(2); 
    hours.push_back(4); 
    hours.push_back(6); 
    hours.push_back(8); 
    hours.push_back(10); 
    hours.push_back(12); 
    hours.push_back(14); 
    hours.push_back(16); 
    hours.push_back(18); 
    hours.push_back(20); 
    hours.push_back(22); 
    hours.push_back(24); 
    ActiveHours active_hours(hours);
     
    for (int i = 1; i <= 24; i++)
    {
        if (i % 2 == 0) 
        {
            ASSERT_EQ(true, active_hours.is_hour_active(i));
        }
        else
        {
            ASSERT_EQ(false, active_hours.is_hour_active(i));
        }
    }   
}


////////////////////////////////////////////////////////////////////////////////

// Main Functionality ---------------------------------------------------------
 
int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

////////////////////////////////////////////////////////////////////////////////
