/*
 * File:   newtestclass1.h
 * Author: siesiek
 *
 * Created on 2012-03-31, 16:09:07
 */

#ifndef NEWTESTCLASS1_H
#define	NEWTESTCLASS1_H

#include <cppunit/extensions/HelperMacros.h>

class ListTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ListTest);

    CPPUNIT_TEST(testAddTask);
    CPPUNIT_TEST(testEditTask);
    CPPUNIT_TEST(testGetAutoincrement);
    CPPUNIT_TEST(testGetTask);
    CPPUNIT_TEST(testIncrementAutoId);
//    CPPUNIT_TEST(testRemoveTask);
//    CPPUNIT_TEST(testShowList);

    CPPUNIT_TEST_SUITE_END();

public:
    ListTest();
    virtual ~ListTest();
    void setUp();
    void tearDown();

private:
    void testAddTask();
    void testEditTask();
    void testGetAutoincrement();
    void testGetTask();
    void testIncrementAutoId();
//    void testRemoveTask();
//    void testShowList();

};

#endif	/* NEWTESTCLASS1_H */

