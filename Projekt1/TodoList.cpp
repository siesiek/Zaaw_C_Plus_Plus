/* 
 * File:   TodoList.cpp
 * Author: siesiek
 * 
 * Created on 19 marzec 2012, 15:41
 */

#include <iostream>
#include <fstream>
#include "TodoList.h"

TodoList::TodoList() {
}

TodoList::TodoList(const TodoList& orig) {
}

TodoList::~TodoList() {
}

void TodoList::addTask(Task* task){
    taskList.insert(pair<int, Task*>(task->getId(), task));
}

void TodoList::editTask(){
    
}

void TodoList::loadFromFile(string filename){
//    char line[1024];
    string line;
    ifstream file("tasks.dat");
    while(getline(file, line)){
        
    }
}

void TodoList::removeTask(int id){
    if(!taskList.empty()){
        taskList.erase(id);
    }
}

void TodoList::saveToFile(string filename){
    
}

void TodoList::showList(){
    map<int, Task*>::iterator it;
    for(it=taskList.begin(); it!=taskList.end(); it++){
        cout << it->second->getId() << " " << it->second->getTitle() << endl;
    }
}