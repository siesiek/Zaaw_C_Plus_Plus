/* 
 * File:   TodoList.h
 * Author: siesiek
 *
 * Created on 19 marzec 2012, 15:41
 */

#ifndef TODOLIST_H
#define	TODOLIST_H

#include <string>
#include <map>
#include "Task.h"

using namespace std;

class TodoList {
public:
    TodoList();
    TodoList(const TodoList& orig);
    virtual ~TodoList();
    void addTask(Task* task);
    void removeTask(int id);
    void editTask();
    void showList();
    void saveToFile(string filename);
    void loadFromFile(string filename);
private:
    map<int, Task*> taskList;
};

#endif	/* TODOLIST_H */

