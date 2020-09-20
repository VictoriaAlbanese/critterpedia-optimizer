////////////////////////////////////////////////////////////////////////////////
//
// Programmer : Victoria Albanese
//   Filename : active_hours.hpp
//
//    Purpose : To represent the active hours of an animal
//              in Animal Crossing New Horizons  
//
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::find;
using std::map;
using std::ostream;
using std::string;
using std::to_string;
using std::vector;

////////////////////////////////////////////////////////////////////////////////

class ActiveHours 
{
    private:

        map<int, bool> active_hours;        


    public:

        ActiveHours();
        ActiveHours(vector<int> hours);

        bool is_hour_active(int hour_index) const;

        friend ostream &operator<<(ostream &output, const ActiveHours &h);
};

////////////////////////////////////////////////////////////////////////////////
