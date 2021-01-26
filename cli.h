#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Student.h"

using namespace std;

void Welcome() {
    cout << "=========================" << endl;
    cout << "=== Data base student ===" << endl;
    cout << "=== ----------------- ===" << endl;
    cout << "== (c) IT Step Academy ==" << endl;
    cout << "=========================" << endl;
    cout << endl;
}

void ShowMenu() {
    system("cls");
    cout << "+++ МЕНЮ +++" << endl;
    cout << "1. Показать информацию о всех студентах" << endl;
    cout << "2. Найти студента" << endl;
    cout << "3. Изменить данные студента" << endl;
    cout << "4. Удалить студента" << endl;
    cout << "5. Экспортировать данные в файл" << endl;
    cout << "0. Выход из программы" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
}

void ShowStudent(Student student) {
    cout << "--- Данные студента ---" << endl;
    cout << "Фамилия: " << student.lastName << endl;
    cout << "Имя: " << student.firstName << endl;
    cout << "Дата рождения: " << student.dateOfBirth.ToString() << endl;
    cout << "Пол: " << SexToString(student.sex) << endl;
    cout << "Факультет: " << FacultyToString(student.faculty) << endl;
    cout << "Учится?: " << student.IsStudyToString() << endl;
}

void ShowStudents(vector<Student> students) {
    for (Student element : students) {
        ShowStudent(element);
    }
}

void ExportToFile(vector<Student> students, string path) {
    ofstream file;
    file.open(path);
    if (file.is_open()) {
        for (Student element : students) {
            file << element.firstName << ";" << element.lastName << ";" << element.dateOfBirth.ToString() << ";"
                 << element.sex << ";" <<
                 element.faculty << ";" << element.IsStudyToString() << endl;
        }
    } else {
        cout << "Файл не открылся" << endl;
    }
    file.close();
}

void ImportFromFile(vector<Student> &students, string path) {
    Student tempStudent;
    string tempStr;
    int ind;

    ifstream file;
    file.open(path, ios_base::in);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, tempStudent.firstName, ';');
            getline(file, tempStudent.lastName, ';');
            getline(file, tempStr, ';');
            tempStudent.dateOfBirth.ParseStrDate(tempStr);
            getline(file, tempStr, ';');
            if (tempStr == "мужской") {
                tempStudent.sex = Sex::Male;
            } else if (tempStr == "женский") {
                tempStudent.sex = Sex::Female;
            } else if (tempStr == "другой") {
                tempStudent.sex = Sex::Other;
            }
            getline(file, tempStr, ';');
          if (tempStr == "Разработка ПО") {
                tempStudent.faculty = Faculty::SofDev;
            } else {
                tempStudent.faculty = Faculty::Design;
            }
            getline(file, tempStr, ';');
            if (tempStr == "учится") {
                tempStudent.isStudy = true;
            } else {
                tempStudent.isStudy = false;
            }
            students.push_back(tempStudent);
        }

    }
}