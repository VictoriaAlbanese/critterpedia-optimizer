////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : active_hours.cpp
//
//    Purpose : To represent the active hours of an animal
//              in Animal Crossing New Horizons  
//
////////////////////////////////////////////////////////////////////////////////

#include <active_hours.hpp>

////////////////////////////////////////////////////////////////////////////////

// Public Methods -------------------------------------------------------------

// DEFAULT CONSTRUCTOR
// fill out the active time structure,
// setting all the hours to be active
ActiveHours::ActiveHours()
: active_hours{}
{
    for (int i = 1; i <= 24; i++)
    {
        this->active_hours[i] = true;
    }
}

// CONSTRUCTOR
// fill out the active time structure,
// setting only the specified hours to be active
ActiveHours::ActiveHours(vector<int> hours)
: active_hours{}
{
    for (int i = 1; i <= 24; i++)
    {
        vector<int>::iterator find_result = find(hours.begin(), hours.end(), i);
        bool is_found = (find_result != hours.end()) ? true : false;
        this->active_hours[i] = is_found;
    }
}

// IS HOUR ACTIVE
// return a bool indicating if the given hour is active or not
bool ActiveHours::is_hour_active(int hour_index) const
{
    return this->active_hours.at(hour_index);
}


// Friend Methods -------------------------------------------------------------

// OVERLOADED OSTREAM OPERATOR
// print the ActiveMonths object 
ostream &operator<<(ostream &output, const ActiveHours &ah)
{
    string hours = "";
    for (int i = 1; i <= 24; i++) 
    {
        if (ah.is_hour_active(i))
        {
            if (i <= 12) 
            {
                hours+= to_string(i) + "am, ";
            }
            else 
            {
                hours+= to_string(i - 12) + "pm, ";
            }
        }
    }
    hours.pop_back();
    hours.pop_back();
    output << hours;

    return output;
}

////////////////////////////////////////////////////////////////////////////////
