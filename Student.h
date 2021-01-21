#pragma once

#include <string>
#include "Date.h"
#include "Sex.h"
#include "Faculty.h"

using namespace std;

struct Student {
    string lastName;
    string firstName;
    Date dateOfBirth;
    Sex sex;
    Faculty faculty;
    bool isStudy;

    string IsStudyToString()
    {
        if (isStudy) {
            return "учится";
        } else {
            return "не учится";
        }
    }
};