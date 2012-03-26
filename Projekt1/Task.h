/* 
 * File:   Task.h
 * Author: siesiek
 *
 * Created on 18 marzec 2012, 18:50
 */

#ifndef TASK_H
#define	TASK_H

#include <string>

using namespace std;

class Task {
public:
    Task(int id, string description, string date, string time, int priority, int severity);
    Task(const Task& orig);
    virtual ~Task();
    int getId();
    void setId(int id);
    string getDescription();
    void setDescription(string description);
    string getDate();
    void setDate(string date);
    string getTime();
    void setTime(string time);
    int getPriority();
    void setPriority(int priority);
    int getSeverity();
    void setSeverity(int severity);
private:
    int id;
    string description;
    string date;
    string time;
    int priority;
    int severity;
};

#endif	/* TASK_H */
