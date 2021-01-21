#pragma once

#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

enum Sex {
    Male, Female, Other
};

enum Faculty {
    SofDev, Design
};

struct Student {
    string lastName;
    string firstName;
    Date dateOfBirth;
    Sex sex;
    Faculty faculty;
    bool isStudy;
};