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
    vector<pair<string, string>> ranges;
    bool processing_range = false;
    string start_month;
    string end_month;
    for (int i = 1; i <= 12; i++) 
    {
        if (am.is_month_active(i))
        {
            if (processing_range == false) 
            {
                processing_range = true;
                start_month = am.get_month_name(i);
            }
            end_month = am.get_month_name(i);
        }
        else
        {
            if (processing_range == true) 
            {
                processing_range = false;
                ranges.push_back(make_pair(start_month, end_month));
            }
        }
    }

    if (processing_range == true) 
    {
        ranges.push_back(make_pair(start_month, end_month));
    }

    if (ranges.front().first == "January" && ranges.back().second == "December")
    {
        if (ranges.size() == 1)
        {
            output << "all year";
            return output;
        }
        else 
        {
            ranges[ranges.size() - 1].second = ranges.front().second;
            ranges.erase(ranges.begin());
        }
    }

    for (int i = 0; i < ranges.size(); i++) 
    {
        output << ranges[i].first << " - " << ranges[i].second;
        if (i != ranges.size() - 1) 
        {
            output << ", ";
        }
    }

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
