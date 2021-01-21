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
