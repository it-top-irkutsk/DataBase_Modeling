#include <iostream>
#include "cli.h"

using namespace std;

int main()
{
    system("chcp 65001");

    char select;
    bool isRun = true;

    Student student;
    student.lastName = "Starinin";
    student.firstName = "Andrey";
    student.dateOfBirth.year = 1986;
    student.dateOfBirth.month = 2;
    student.dateOfBirth.day = 18;
    student.sex = Sex::Male;
    student.faculty = Faculty::SofDev;
    student.isStudy = false;

    Welcome();

    do {
        ShowMenu();
        cout << "Введите необходимый пункт меню: ";
        cin >> select;
        switch (select) {
            case '1':
                break;
            case '2':
                ShowStudent(student);
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '0':
                isRun = false;
                break;
            default:
                cout << "Вы ввели неправильный пункт меню" << endl;
                break;
        }
    } while (isRun);

    cout << "До встречи..." << endl;
}
