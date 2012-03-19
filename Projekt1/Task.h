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
    Task();
    Task(const Task& orig);
    virtual ~Task();
    int getId();
    void setId(int id);
    string getTitle();
    void setTitle(string title);
    string getDate();
    void setDate(string date);
private:
    int id;
    string title;
    string date;
};

#endif	/* TASK_H */
