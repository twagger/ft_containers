#include "gtest/gtest.h"
#include "Vector.hpp"
#include "fixtures.hpp"

/* ************************************************************************** */
/*  ITERATOR TESTS                                                            */
/* ************************************************************************** */

TEST_F(VectorTest, iteratorBasic) {
	MyVector.push_back(42);
	MyVector.push_back(42);
	MyVector.push_back(42);
	MyVector.push_back(42);
	MyVector.push_back(42);
	ft::vector<int>::iterator	it = MyVector.begin();
	it++;
	it--;
	EXPECT_EQ(it, MyVector.begin());
}
