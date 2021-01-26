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
    cout << "6. Экспортировать данные из файла" << endl;
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

void ImportToFile (vector<Student>& students, string path){
    Student student;
    string tempData;

    ifstream file;
    file.open(path, ios_base::in);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, student.firstName, ';');
            getline(file, student.lastName, ';');
            getline(file, tempData, '.');
            student.dateOfBirth.day = stoi(tempData);
            getline(file, tempData, '.');
            student.dateOfBirth.month = stoi(tempData);
            getline(file, tempData, ';');
            student.dateOfBirth.year = stoi(tempData);
            getline(file, tempData, ';');
            student.sex = StringToSex(stoi(tempData));
            getline(file, tempData, ';');
            student.faculty = StringToFaculty(stoi(tempData));
            getline(file, tempData);
            student.isStudy = stoi(tempData);
        }
        students.push_back(student);
        file.close();
    } else {
        cout << "Файл не открылся" << endl;
    }
}