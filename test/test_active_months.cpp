////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : test_active_months.cpp
//
//    Purpose : To test the active_months class
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "../src/active_months.hpp"

using std::cout;
using std::endl;
using std::vector;

////////////////////////////////////////////////////////////////////////////////

// Unit Tests

TEST(ActiveMonthsTest, DefaultConstructor) 
{ 
    ActiveMonths active_months;
    
    for (int i = 1; i <= 12; i++)
    {
        ASSERT_EQ(true, active_months.is_month_active(i));
    }   
}

TEST(ActiveMonthsTest, CustomConstructor) 
{
    vector<int> months;
    months.push_back(2); 
    months.push_back(4); 
    months.push_back(6); 
    months.push_back(8); 
    months.push_back(10); 
    months.push_back(12); 
    ActiveMonths active_months(months);
     
    for (int i = 1; i <= 12; i++)
    {
        if (i % 2 == 0) 
        {
            ASSERT_EQ(true, active_months.is_month_active(i));
        }
        else
        {
            ASSERT_EQ(false, active_months.is_month_active(i));
        }
    }   
}

TEST(ActiveMonthsTest, GetMonthName) 
{ 
    ActiveMonths active_months;
    
    ASSERT_EQ("January", active_months.get_month_name(1));
    ASSERT_EQ("February", active_months.get_month_name(2));
    ASSERT_EQ("March", active_months.get_month_name(3));
    ASSERT_EQ("April", active_months.get_month_name(4));
    ASSERT_EQ("May", active_months.get_month_name(5));
    ASSERT_EQ("June", active_months.get_month_name(6));
    ASSERT_EQ("July", active_months.get_month_name(7));
    ASSERT_EQ("August", active_months.get_month_name(8));
    ASSERT_EQ("September", active_months.get_month_name(9));
    ASSERT_EQ("October", active_months.get_month_name(10));
    ASSERT_EQ("November", active_months.get_month_name(11));
    ASSERT_EQ("December", active_months.get_month_name(12));
}


////////////////////////////////////////////////////////////////////////////////

// Main Functionality ---------------------------------------------------------
 
int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

////////////////////////////////////////////////////////////////////////////////
