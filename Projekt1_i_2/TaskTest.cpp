/*
 * File:   TaskTest.cpp
 * Author: siesiek
 *
 * Created on 2012-03-26, 21:44:26
 */

#include "TaskTest.h"
#include "Task.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TaskTest);

TaskTest::TaskTest() {
}

TaskTest::~TaskTest() {
}

void TaskTest::setUp() {
}

void TaskTest::tearDown() {
}

void TaskTest::testSetDate() {
    string date;
    Task* task = new Task(1,"","","",1,1);
    task->setDate(date);
    if (task->getDate() == date) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}

void TaskTest::testSetDescription() {
    string description;
    Task* task = new Task(1,"","","",1,1);
    task->setDescription(description);
    if (task->getDescription() == description) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}

void TaskTest::testSetId() {
    int id;
    Task* task = new Task(1,"","","",1,1);
    task->setId(id);
    if (task->getId() == id) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}

void TaskTest::testSetPriority() {
    int priority;
    Task* task = new Task(1,"","","",1,1);
    task->setPriority(priority);
    if (task->getPriority() == priority) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}

void TaskTest::testSetSeverity() {
    int severity;
    Task* task = new Task(1,"","","",1,1);
    task->setSeverity(severity);
    if (task->getSeverity() == severity) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}

void TaskTest::testSetTime() {
    string time;
    Task* task = new Task(1,"","","",1,1);
    task->setTime(time);
    if (task->getTime() == time) {
        CPPUNIT_ASSERT(true);
    }
    else{
        CPPUNIT_ASSERT(false);
    }
    delete task;
}
