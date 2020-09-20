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
    vector<pair<int, int>> ranges;
    bool processing_range = false;
    int start_hour;
    int end_hour;
    for (int i = 1; i <= 24; i++) 
    {
        if (ah.is_hour_active(i))
        {
            if (processing_range == false) 
            {
                processing_range = true;
                start_hour = i;
            }
            end_hour = i;
        }
        else
        {
            if (processing_range == true) 
            {
                processing_range = false;
                ranges.push_back(make_pair(start_hour, end_hour));
            }
        }
    }

    if (processing_range == true) 
    {
        ranges.push_back(make_pair(start_hour, end_hour));
    }

    if (ranges.front().first == 1 && ranges.back().second == 24)
    {
        if (ranges.size() == 1)
        {
            output << "all day";
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
        string start_time;
        if (ranges[i].first < 12) 
        {
            start_time = to_string(ranges[i].first) + "am"; 
        }
        else 
        {
            start_time = to_string(ranges[i].first - 12) + "pm";
        }

        string end_time;
        if  (ranges[i].second < 12) 
        {
            end_time = to_string(ranges[i].second) + "am";
        }
        else
        {
            end_time = to_string(ranges[i].second - 12) + "pm";
        }

        output << start_time << " - " << end_time;

        if (i != ranges.size() - 1) 
        {
            output << ", ";
        }
    }

    return output;
}

////////////////////////////////////////////////////////////////////////////////
