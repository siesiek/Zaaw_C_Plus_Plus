/* 
 * File:   ProgramMenu.h
 * Author: siesiek
 *
 * Created on 26 marzec 2012, 16:07
 */

#ifndef PROGRAMMENU_H
#define	PROGRAMMENU_H

#include<string>
#include "TodoList.h"

using namespace std;

class ProgramMenu {
public:
    ProgramMenu(TodoList* list);
    ProgramMenu(const ProgramMenu& orig);
    virtual ~ProgramMenu();
    void showMenu();
    void getUserChoice();
    void showTask();
    void addTask();
    void changePass();
    static const string filename;
    void clear();
    void editTask(int id);
private:
    TodoList* list;
};

#endif	/* PROGRAMMENU_H */

