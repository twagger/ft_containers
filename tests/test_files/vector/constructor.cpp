#include "Vector.hpp"
#include <gtest/gtest.h>

/* ************************************************************************** */
/*  CONSTRUCTOR TESTS                                                         */
/* ************************************************************************** */

TEST(VectorTest_Constructor, defaultConstructorEmptySize) {
	ft::vector<int> MyVector;
	EXPECT_EQ(MyVector.size(), 0)
		<< "Default vector should have a 0 size";
}

TEST(VectorTest_Constructor, defaultConstructorEmptyCapacity) {
	ft::vector<int> MyVector;
	EXPECT_EQ(MyVector.capacity(), 0)
		<< "Default vector should have a 0 capacity";
}

TEST(VectorTest_Constructor, fillConstructor) {
	ft::vector<int> MyVector(5, 42);
	for (int i = 0; i < 5; ++i)
	{
		EXPECT_EQ(MyVector[i], 42)
			<< "Filled vector should contain n elements with the given value";
	}
}