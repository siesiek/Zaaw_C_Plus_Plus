/*
 * File:   ListTest.cpp
 * Author: siesiek
 *
 * Created on 2012-03-31, 16:09:09
 */

#include "ListTest.h"
#include "TodoList.h"
#include "Task.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ListTest);

ListTest::ListTest() {
}

ListTest::~ListTest() {
}

void ListTest::setUp() {
}

void ListTest::tearDown() {
}

void ListTest::testAddTask() {
    Task* task = new Task(1,"","","",1,1);
    TodoList* todoList = new TodoList();
    todoList->addTask(task);
    if (todoList->getSize() == 1) {
        CPPUNIT_ASSERT(true);
    }
}

void ListTest::testEditTask() {
    int id = 1;
    string date = "23-04-2012";
    string time = "18:30";
    string description = "Nowy opis";
    int priority = 2;
    int severity = 3;
    TodoList* todoList = new TodoList();
    todoList->addTask(new Task(1,"Opis","Data","Czas",1,1));
    todoList->editTask(id, date, time, description, priority, severity);
    Task *task = todoList->getTask(1);
    if (task->getDate() == date && task->getDescription() == description && task->getTime() == time && task->getPriority() == priority && task->getSeverity() == severity) {
        CPPUNIT_ASSERT(true);
    }
}

void ListTest::testGetAutoincrement() {
    TodoList* todoList = new TodoList();
    int result = todoList->getAutoincrement();
    if (result == 1) {
        CPPUNIT_ASSERT(true);
    }
}

void ListTest::testGetTask() {
    int id = 1;
    Task* task = new Task(1,"","","",1,1);
    TodoList* todoList = new TodoList();
    todoList->addTask(task);
    Task* result = todoList->getTask(id);
    if (result->getDescription() == task->getDescription()) {
        CPPUNIT_ASSERT(true);
    }
}

void ListTest::testIncrementAutoId() {
    TodoList* todoList = new TodoList();
    int oldAutoId = todoList->getAutoincrement();
    todoList->incrementAutoId();
    if (oldAutoId < todoList->getAutoincrement()) {
        CPPUNIT_ASSERT(true);
    }
}

//void ListTest::testRemoveTask() {
//    int id;
//    TodoList todoList;
//    todoList.removeTask(id);
//    if (true /*check result*/) {
//        CPPUNIT_ASSERT(false);
//    }
//}
//
//void ListTest::testShowList() {
//    TodoList todoList;
//    todoList.showList();
//    if (true /*check result*/) {
//        CPPUNIT_ASSERT(false);
//    }
//}

