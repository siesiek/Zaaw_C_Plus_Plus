/*
 * File:   newtestclass.h
 * Author: siesiek
 *
 * Created on 2012-03-26, 21:44:25
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class TaskTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TaskTest);

    CPPUNIT_TEST(testSetDate);
    CPPUNIT_TEST(testSetDescription);
    CPPUNIT_TEST(testSetId);
    CPPUNIT_TEST(testSetPriority);
    CPPUNIT_TEST(testSetSeverity);
    CPPUNIT_TEST(testSetTime);

    CPPUNIT_TEST_SUITE_END();

public:
    TaskTest();
    virtual ~TaskTest();
    void setUp();
    void tearDown();

private:
    void testSetDate();
    void testSetDescription();
    void testSetId();
    void testSetPriority();
    void testSetSeverity();
    void testSetTime();

};

#endif	/* NEWTESTCLASS_H */

