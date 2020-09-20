////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : active_months.cpp
//
//    Purpose : To represent the active months of an animal
//              in Animal Crossing New Horizons  
//
////////////////////////////////////////////////////////////////////////////////

#include "active_months.hpp"

////////////////////////////////////////////////////////////////////////////////

// Public Methods -------------------------------------------------------------

// DEFAULT CONSTRUCTOR
// fill out the active months structure,
// setting all the months to be active
ActiveMonths::ActiveMonths() 
: active_months{}
{
    for (int i = 1; i <= 12; i++)
    {
        this->active_months[i] = true;
    }
}

// CONSTRUCTOR
// fill out the active months structure,
// setting only the specified months to be active
ActiveMonths::ActiveMonths(vector<int> months)
: active_months{}
{
    for (int i = 1; i <= 12; i++)
    {
        vector<int>::iterator find_result = find(months.begin(), months.end(), i);
        bool is_found = (find_result != months.end()) ? true : false;
        this->active_months[i] = is_found;
    }
}

// GET MONTH NAME
// return the name of the month associated with the month index
string ActiveMonths::get_month_name(int month_index) const 
{
    return this->month_names.at(month_index);
}

// IS MONTH ACTIVE
// return a bool indicating if the given month is active or not
bool ActiveMonths::is_month_active(int month_index) const
{
    return this->active_months.at(month_index);
}


// Friend Methods -------------------------------------------------------------

// OVERLOADED OSTREAM OPERATOR
// print the ActiveMonths object 
ostream &operator<<(ostream &output, const ActiveMonths &am) 
{
    string months = "";
    for (int i = 1; i <= 12; i++) 
    {
        if (am.is_month_active(i))
        {
            months+= am.get_month_name(i) + ", ";
        }
    }
    months.pop_back();
    months.pop_back();
    output << months;

    return output;
}


// Static Member Definitions --------------------------------------------------

map<int, string> ActiveMonths::month_names = { { 1, "January" }
                                             , { 2, "February" } 
                                             , { 3, "March" }
                                             , { 4, "April" }
                                             , { 5, "May" }
                                             , { 6, "June" }
                                             , { 7, "July" }
                                             , { 8, "August" }
                                             , { 9, "September" }
                                             , { 10, "October" }
                                             , { 11, "November" }
                                             , { 12, "December" } };  

////////////////////////////////////////////////////////////////////////////////
