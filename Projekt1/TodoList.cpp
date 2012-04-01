/* 
 * File:   TodoList.cpp
 * Author: Grzegorz Kolasa
 * 
 * Created on 19 marzec 2012, 15:41
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "TodoList.h"

TodoList::TodoList() {
    this->autoincrement = 0;
}

TodoList::TodoList(const TodoList& orig) {
}

TodoList::~TodoList() {
    map<int, Task*>::iterator it;
    for(it=taskList.begin(); it!=taskList.end(); it++){
        delete it->second;
    }
    taskList.clear();
}

void TodoList::addTask(Task* task){
    taskList.insert(pair<int, Task*>(task->getId(), task));
}

void TodoList::editTask(int id, string date, string time, string description, int priority, int severity){
    Task* task = taskList.at(id);
    task->setDate(date);
    task->setTime(time);
    task->setDescription(description);
    task->setPriority(priority);
    task->setSeverity(severity);
}

void TodoList::loadFromFile(string filename){
    string line = "";
    string* parts;
    ifstream file(filename.c_str());
    while(getline(file, line)){
        parts = this->explode(line);
        if(parts != NULL){
            Task* task = new Task(atoi(parts[0].c_str()),parts[1],parts[2],parts[3],atoi(parts[4].c_str()),atoi(parts[5].c_str()));
            this->addTask(task);
            if(autoincrement <= task->getId()){
                autoincrement = task->getId()+1;
            }
            delete[] parts;
        }
    }
//    file.close();
}

void TodoList::removeTask(int id){
    if(!taskList.empty()){
        Task* task = taskList.at(id);
        delete task;
        taskList.erase(id);
    }
}

void TodoList::saveToFile(string filename){
    ofstream file(filename.c_str());
    map<int, Task*>::iterator it;
    for(it=taskList.begin(); it!=taskList.end(); it++){
        file << it->second->getId() << ";" << it->second->getDescription() << ";" << it->second->getDate() << ";" << it->second->getTime() << ";" << it->second->getPriority() << ";" << it->second->getSeverity() << ";" << endl;
    }
//    file.close();
}

void TodoList::showList(){
    map<int, Task*>::iterator it;
    cout << "ID | Data | Czas | Opis | Priorytet | Waznosc" << endl << endl;
    for(it=taskList.begin(); it!=taskList.end(); it++){
        cout << it->second->getId() << " | " << it->second->getDate() << " | " << it->second->getTime() << " | " << it->second->getDescription() << " | " << it->second->getPriority() << " | " << it->second->getSeverity() << endl;
    }
}

void TodoList::showTask(int id){
    Task* task = taskList.at(id);
    cout << "ID: " << task->getId() << endl;
    cout << "Do: " << task->getDate() << " " << task->getTime() << endl;
    cout << "Priorytet: " << task->getPriority() << " | Waznosc: " << task->getSeverity() << endl;
    cout << "Opis:" << endl;
    cout << task->getDescription() << endl;
}

void TodoList::incrementAutoId(){
    this->autoincrement++;
}

int TodoList::getAutoincrement(){
    return this->autoincrement;
}

string* TodoList::explode(string line){
    if(line.empty()){
        return NULL;
    }
    string* result = new string[6];
    string temp;
    int left = 0;
    int right = 0;
    int i = 0;
    while(true){
        right = line.find(";",left);
        if(right == string::npos){
            break;
        }
        temp = line.substr(left,right-left);
        result[i++] = temp;
        left = right+1;
    }
    return result;
}

Task* TodoList::getTask(int id){
    return this->taskList.at(id);
}

int TodoList::getSize(){
    return this->taskList.size();
}