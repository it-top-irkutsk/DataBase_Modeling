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
Faculty StringToFaculty (int number){
    switch (number) {
        case 0:
            return SofDev;
        case 1:
            return Design;
    }
}
