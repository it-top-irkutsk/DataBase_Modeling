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
    void ParseStrDate(string date){
        year=stoi(date.substr(0, date.find(".")));
        month=stoi(date.substr(date.find(".")+1, date.find(".")));
        day = stoi(date.substr(date.find_last_of(".")+1));
    }
};
