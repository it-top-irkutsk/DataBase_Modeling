#pragma once

#include <iostream>

using namespace std;

void Welcome()
{
    cout << "=========================" << endl;
    cout << "=== Data base student ===" << endl;
    cout << "=== ----------------- ===" << endl;
    cout << "== (c) IT Step Academy ==" << endl;
    cout << "=========================" << endl;
    cout << endl;
}

void ShowMenu()
{
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