#include "gtest/gtest.h"
#include "Vector.hpp"
#include "fixtures.hpp"

/* ************************************************************************** */
/*  ELEMENT ACCESS TESTS                                                      */
/* ************************************************************************** */
// operator[]
TEST_F(VectorTest, operatorBracketInRange) {
	MyVector.push_back(42);
	MyVector.push_back(43);
	StdVector.push_back(42);
	StdVector.push_back(43);
	EXPECT_EQ(MyVector[1], 43);
	EXPECT_EQ(MyVector[1], StdVector[1]);
}

TEST_F(VectorTest, operatorBracketOutOfRange) {
	MyVector.push_back(42);
	MyVector.push_back(43);
	EXPECT_THROW(MyVector[2], std::out_of_range);
}

// at
TEST_F(VectorTest, atInRange) {
	MyVector.push_back(42);
	MyVector.push_back(43);
	StdVector.push_back(42);
	StdVector.push_back(43);
	EXPECT_EQ(MyVector.at(1), 43);
	EXPECT_EQ(MyVector.at(1), StdVector.at(1));
}

TEST_F(VectorTest, atOutOfRange) {
	MyVector.push_back(42);
	MyVector.push_back(43);
	EXPECT_THROW(MyVector.at(2), std::out_of_range);
}

// front
TEST_F(VectorTest, frontOnNonEmpty) {
	MyVector.push_back(41);
	MyVector.push_back(43);
	StdVector.push_back(41);
	StdVector.push_back(43);
	EXPECT_EQ(MyVector.front(), 41);
	EXPECT_EQ(MyVector.front(), StdVector.front());
}

TEST_F(VectorTest, frontOnEmpty) {
	EXPECT_THROW(MyVector.front(), std::out_of_range);
}

// back
TEST_F(VectorTest, backOnNonEmpty) {
	MyVector.push_back(41);
	MyVector.push_back(43);
	StdVector.push_back(41);
	StdVector.push_back(43);
	EXPECT_EQ(MyVector.back(), 43);
	EXPECT_EQ(MyVector.back(), StdVector.back());
}

TEST_F(VectorTest, backOnEmpty) {
	EXPECT_THROW(MyVector.back(), std::out_of_range);
}
