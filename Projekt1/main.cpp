/* 
 * File:   main.cpp
 * Author: siesiek
 *
 * Created on 18 marzec 2012, 18:49
 */

#include <cstdlib>
#include "TodoList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Task* task = new Task();
    task->setId(1);
    task->setTitle("Task 1");
    TodoList* list = new TodoList();
    list->addTask(task);
    list->showList();
    return 0;
}

