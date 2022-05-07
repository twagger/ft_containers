#include "gtest/gtest.h"
#include "Vector.hpp"
#include "fixtures.hpp"

/* ************************************************************************** */
/*  OPERATORS TESTS                                                           */
/* ************************************************************************** */
TEST_F(VectorTest, equalOperatorFalse) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(43);
	MyTmpVector.push_back(1);
	MyTmpVector.push_back(2);
	EXPECT_EQ(MyVector == MyTmpVector, false);
}

TEST_F(VectorTest, equalOperatorTrue) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(43);
	MyTmpVector.push_back(41);
	MyTmpVector.push_back(42);
	MyTmpVector.push_back(43);
	EXPECT_EQ(MyVector == MyTmpVector, true);
}

TEST_F(VectorTest, equalOperatorEmpty) {
	EXPECT_EQ(MyVector == MyTmpVector, true);
}

TEST_F(VectorTest, greaterThanOperatorFalse) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(43);
	MyTmpVector.push_back(41);
	MyTmpVector.push_back(42);
	MyTmpVector.push_back(43);
	EXPECT_EQ(MyVector > MyTmpVector, false);
}

TEST_F(VectorTest, greaterThanOperatorTrue) {
	MyVector.push_back(41);
	MyVector.push_back(43);
	MyVector.push_back(43);
	MyTmpVector.push_back(41);
	MyTmpVector.push_back(42);
	MyTmpVector.push_back(43);
	EXPECT_EQ(MyVector > MyTmpVector, true);
}

TEST_F(VectorTest, greaterThanOrEqualOperatorFalse) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(42);
	MyTmpVector.push_back(41);
	MyTmpVector.push_back(42);
	MyTmpVector.push_back(43);
	EXPECT_EQ(MyVector >= MyTmpVector, false);
}

TEST_F(VectorTest, greaterThanOrEqualOperatorTrue) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(43);
	MyTmpVector.push_back(41);
	MyTmpVector.push_back(42);
	MyTmpVector.push_back(43);
	EXPECT_EQ(MyVector >= MyTmpVector, true);
}