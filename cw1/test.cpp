#include "class.h"
#include "gtest/gtest.h"

TEST(Klasa, Positive){
	Klasa object;
	object.setTestDouble(2.5);
	EXPECT_TRUE(object.isBiggerThan(3));
	EXPECT_TRUE(object.isEven(4));
	EXPECT_TRUE(object.isSmallerThan(1.1));
}

TEST(Klasa, Negative){
	Klasa object;
	object.setTestDouble(2.5);
	EXPECT_FALSE(object.isBiggerThan(1.3));
	EXPECT_FALSE(object.isEven(1));
	EXPECT_FALSE(object.isSmallerThan(3.3));
}

int main(){
	RUN_ALL_TESTS();
	return 0;
}

