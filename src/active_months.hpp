////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : active_months.hpp
//
//    Purpose : To represent the active months of an animal
//              in Animal Crossing New Horizons  
//
////////////////////////////////////////////////////////////////////////////////

#ifndef ACTIVE_MONTHS_H
#define ACTIVE_MONTHS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::find;
using std::map;
using std::ostream;
using std::string;
using std::vector;

////////////////////////////////////////////////////////////////////////////////

class ActiveMonths
{
    private:

        static map<int, string> month_names;
        map<int, bool> active_months;        


    public:

        ActiveMonths();
        ActiveMonths(vector<int> months);

        string get_month_name(int month_index) const;
        bool is_month_active(int month_index) const;

        friend ostream &operator<<(ostream &output, const ActiveMonths &months);
};

#endif // ACTIVE_MONTHS_H

////////////////////////////////////////////////////////////////////////////////
