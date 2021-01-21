#pragma once

#include <string>

using namespace std;

enum Faculty {
    SofDev, Design
};

string FacultyToString(Faculty faculty)
{
    switch (faculty) {
        case SofDev:
            return "Разработка ПО";
        case Design:
            return "Дизайн";
    }
}