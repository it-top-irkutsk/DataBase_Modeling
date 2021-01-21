#pragma once

#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;

    string ToString()
    {
        string temp;
        temp = to_string(day) + "." + to_string(month) + "." + to_string(year);
        return temp;
    }
};
