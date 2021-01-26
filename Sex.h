#pragma once

#include <string>

using namespace std;

enum Sex {
    Male, Female, Other
};

string SexToString(Sex sex)
{
    switch (sex) {
        case Male:
            return "мужской";
        case Female:
            return "женский";
        case Other:
            return "другой";
    }
}
Sex StringToSex(int number) {
    switch (number) {
        case 0:
            return Male;
        case 1:
            return Female;
        case 2:
            return Other;
    }
}
