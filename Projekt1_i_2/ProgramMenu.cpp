/* 
 * File:   ProgramMenu.cpp
 * Author: siesiek
 * 
 * Created on 26 marzec 2012, 16:07
 */

#include "ProgramMenu.h"
#include "TodoList.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const std::string ProgramMenu::filename = "tasks.dat";

ProgramMenu::ProgramMenu(TodoList* list) {
    this->list = list;
}

ProgramMenu::ProgramMenu(const ProgramMenu& orig) {
}

ProgramMenu::~ProgramMenu() {
}

void ProgramMenu::showMenu() {
    cout << endl << endl;
    cout << "Dostępne opcje:" << endl;
    cout << "1: Pokaz zadanie" << endl;
    cout << "2: Dodaj nowe zadanie" << endl;
    cout << "3: Zmien haslo" << endl;
    cout << "4: Zakoncz program" << endl;
    cout << endl << endl;
}

void ProgramMenu::getUserChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (choice == 1) {
            clear();
            this->showTask();
        } else if (choice == 2) {
            clear();
            this->addTask();
        } else if (choice == 3) {
            this->changePass();
        } else if (choice == 4) {
            this->list->saveToFile(filename);
            break;
        }
    }
}

void ProgramMenu::addTask() {
    string description, date, time;
    int id, priority, severity;
    cout << "Dodawanie taska" << endl << endl;
    cout << "Podaj date terminu: ";
    cin >> date;
    cout << "Podaj godzine terminu: ";
    cin >> time;
    cout << "Podaj opis zadania: ";
    cin.ignore();
    getline(cin, description);
    cout << "Podaj priorytet (od 0 do 5): ";
    cin >> priority;
    while (priority > 5 || priority < 0) {
        cout << "Podaj cyfre od 0 do 5" << endl;
        cin >> priority;
    }
    cout << "Podaj waznosc zadania (od 0 do 5): ";
    cin >> severity;
    while (severity > 5 || severity < 0) {
        cout << "Podaj cyfre od 0 do 5" << endl;
        cin >> severity;
    }
    clear();
    id = list->getAutoincrement();
    list->incrementAutoId();
    list->addTask(new Task(id, description, date, time, priority, severity));
    this->list->showList();
    this->showMenu();
}

void ProgramMenu::changePass() {
    ofstream fileOut("pass.dat");
    string newPassword, confirmedPassword;
    cout << "Prosze podac nowe haslo" << endl;
    cin >> newPassword;
    cout << "Prosze powtorzyc haslo" << endl;
    cin >> confirmedPassword;
    if(newPassword == confirmedPassword){
        fileOut << newPassword;
        clear();
    }
    else{
        clear();
        cout << "Podane hasla nie sa takie same. Prosze sprobowac ponownie" << endl << endl;
    }
    this->list->showList();
    this->showMenu();
}

void ProgramMenu::showTask() {
    int id, choice;
    clear();
    cout << "Podaj ID zadania: ";
    cin >> id;
    list->showTask(id);
    cout << "1: Edytuj | 2: Usun | 3: Wroc ";
    cin >> choice;
    if (choice == 1) {
        clear();
        editTask(id);
    }
    if (choice == 2) {
        clear();
        list->removeTask(id);
        list->showList();
        showMenu();
    }
    if (choice == 3) {
        clear();
        list->showList();
        showMenu();
    }
}

void ProgramMenu::clear() {
    system("clear");
}

void ProgramMenu::editTask(int id) {
    string description, date, time;
    int priority, severity;
    Task* task = list->getTask(id);
    cout << "Edytuj zadanie" << endl << endl;
    cout << "Podaj date terminu: (" << task->getDate() << ")";
    cin >> date;
    task->setDate(date);
    cout << "Podaj godzine terminu: (" << task->getTime() << ")";
    cin >> time;
    task->setTime(time);
    cout << "Podaj opis zadania: (" << task->getDescription() << ")";
    cin.ignore();
    getline(cin, description);
    task->setDescription(description);
    cout << "Podaj priorytet (od 0 do 5): (" << task->getPriority() << ")";
    cin >> priority;
    while (priority > 5 || priority < 0) {
        cout << "Podaj cyfre od 0 do 5" << endl;
        cin >> priority;
    }
    task->setPriority(priority);
    cout << "Podaj waznosc zadania (od 0 do 5): (" << task->getSeverity() << ")";
    cin >> severity;
    while (severity > 5 || severity < 0) {
        cout << "Podaj cyfre od 0 do 5" << endl;
        cin >> severity;
    }
    task->setSeverity(severity);
    clear();
    this->list->showList();
    this->showMenu();
}