#include "gtest/gtest.h"
#include "Vector.hpp"

/* ************************************************************************** */
/*  CONSTRUCTOR TESTS                                                         */
/* ************************************************************************** */
// Default constructor
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

// Fill constructor
TEST(VectorTest_Constructor, fillConstructor) {
    ft::vector<int> MyVector(5, 42);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(MyVector[i], 42)
            << "Filled vector should contain n elements with the given value";
    }
}

// Range constructor
// Test to do

// Copy constructor
TEST(VectorTest_Constructor, copyConstructor) {
    ft::vector<int> MyInitialVector(10, 42);
    ft::vector<int> MyCopiedVector(MyInitialVector);
    EXPECT_EQ(MyCopiedVector.size(), MyInitialVector.size())
        << "Copied vector should be the same size as the original one";
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(MyCopiedVector[i], 42)
            << "Copied vector should contain n elements with the given value";
    }
}
