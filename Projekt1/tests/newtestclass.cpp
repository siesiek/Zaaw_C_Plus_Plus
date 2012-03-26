/*
 * File:   newtestclass.cpp
 * Author: siesiek
 *
 * Created on 2012-03-26, 21:44:26
 */

#include "newtestclass.h"
#include "Task.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testSetDate() {
    string date;
    Task task;
    task.setDate(date);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetDescription() {
    string description;
    Task task;
    task.setDescription(description);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetId() {
    int id;
    Task task;
    task.setId(id);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetPriority() {
    int priority;
    Task task;
    task.setPriority(priority);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetSeverity() {
    int severity;
    Task task;
    task.setSeverity(severity);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetTime() {
    string time;
    Task task;
    task.setTime(time);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

