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
: month_activity{}
{
    for (int i = 0; i < this->month_names.size(); i++)
    {
        int month_index = i + 1;
        this->month_activity[month_index] = true;
    }
}

// CONSTRUCTOR
// fill out the active months structure,
// setting only the specified months to be active
ActiveMonths::ActiveMonths(vector<int> months)
: month_activity{}
{
    for (int i = 0; i < this->month_names.size(); i++)
    {
        int month_index = i + 1;
        vector<int>::iterator find_result = find(months.begin(), months.end(), month_index);
        bool is_found = (find_result != months.end()) ? true : false;
        this->month_activity[month_index] = is_found;
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
bool ActiveMonths::get_month_activity(int month_index) const
{
    return this->month_activity.at(month_index);
}


// Friend Methods -------------------------------------------------------------

// OVERLOADED OSTREAM OPERATOR
// print the ActiveMonths object 
ostream &operator<<(ostream &output, const ActiveMonths &m) 
{
    string months = "";
    for (int i = 0; i < 12; i++) 
    {
        int month_index = i + 1;
        if (m.get_month_activity(month_index))
        {
            months+= m.get_month_name(month_index) + ", ";
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
