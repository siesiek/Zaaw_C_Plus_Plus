/* 
 * File:   Task.cpp
 * Author: siesiek
 * 
 * Created on 18 marzec 2012, 18:50
 */

#include "Task.h"

Task::Task() {
}

Task::Task(const Task& orig) {
}

Task::~Task() {
}

string Task::getDate(){
    return date;
}

void Task::setDate(string d){
    date = d;
}

void Task::setTitle(string t){
    title = t;
}

string Task::getTitle(){
    return title;
}

void Task::setId(int i){
    id = i;
}

int Task::getId(){
    return id;
}