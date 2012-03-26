/* 
 * File:   main.cpp
 * Author: siesiek
 *
 * Created on 18 marzec 2012, 18:49
 */

#include <cstdlib>
#include <list>
#include "TodoList.h"
#include "ProgramMenu.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TodoList* list = new TodoList();
    ifstream passFile("pass.dat");
    string password;
    string myPassword;
    passFile >> password;
    cout << "Prosze podac haslo, aby sie zalogowac" << endl;
    cin >> myPassword;
    if(password == myPassword){
        ProgramMenu* menu = new ProgramMenu(list);
        menu->clear();
        list->loadFromFile(ProgramMenu::filename);
        list->showList();
        menu->showMenu();
        menu->getUserChoice();
        delete menu;
    }
    else{
        cout << "Haslo nie jest prawidlowe. Koniec programu.";
    }
    
    delete list;
    return 0;
}

