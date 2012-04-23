/* 
 * File:   Task.cpp
 * Author: siesiek
 * 
 * Created on 18 marzec 2012, 18:50
 */

#include "Task.h"

Task::Task(int id, string description, string date, string time, int priority, int severity) {
    this->id = id;
    this->description = description;
    this->date = date;
    this->time = time;
    this->priority = priority;
    this->severity = severity;
}

Task::Task(const Task& orig) {
}

Task::~Task() {
}

string Task::getDate(){
    return date;
}

void Task::setDate(string date){
    this->date = date;
}

void Task::setDescription(string description){
    this->description = description;
}

string Task::getDescription(){
    return description;
}

void Task::setId(int id){
    this->id = id;
}

int Task::getId(){
    return id;
}

string Task::getTime(){
    return this->time;
}

void Task::setTime(string time){
    this->time = time;
}

int Task::getPriority(){
    return this->priority;
}

void Task::setPriority(int priority){
    this->priority = priority;
}

int Task::getSeverity(){
    return this->severity;
}

void Task::setSeverity(int severity){
    this->severity = severity;
}