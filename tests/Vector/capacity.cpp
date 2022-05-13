#include "gtest/gtest.h"
#include "Vector.hpp"
#include "fixtures.hpp"

/* ************************************************************************** */
/*  CAPACITY TESTS                                                            */
/* ************************************************************************** */
// capacity
TEST_F(VectorTest, ZeroCapacity) {
    EXPECT_EQ(MyVector.capacity(), 0);
}

// Max size
TEST_F(VectorTest, maxSize) {
    EXPECT_EQ(MyVector.max_size(), StdVector.max_size());
}

// Resize
TEST_F(VectorTest, resizeBiggerSizeSameCapa)
{
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 8);
    MyVector.resize(7, 38);
    EXPECT_EQ(MyVector.size(), 7);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_EQ(MyVector[5], 38);
}

TEST_F(VectorTest, resizeBiggerSizeBiggerCapa)
{
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 8);
    MyVector.resize(22, 38);
    EXPECT_EQ(MyVector.size(), 22);
    EXPECT_EQ(MyVector.capacity(), 22);
    EXPECT_EQ(MyVector[20], 38);
}

TEST_F(VectorTest, resizeSmallerSize)
{
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 8);
    MyVector.resize(2, 38);
    EXPECT_EQ(MyVector.size(), 2);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_THROW(MyVector[3], std::out_of_range);
}

TEST_F(VectorTest, resizeSameSize)
{
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    MyVector.push_back(42);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 8);
    MyVector.resize(5, 38);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_EQ(MyVector[3], 42);
}

// Reserve
TEST_F(VectorTest, reserveBasic) {
    MyVector.reserve(10);
    EXPECT_EQ(MyVector.capacity(), 10);
}

TEST_F(VectorTest, doubleCapacityIfNeeded) {
    MyVector.reserve(10);
    for (int i = 0; i < 11; ++i)
    {
        MyVector.push_back(i);
    }
    EXPECT_EQ(MyVector.capacity(), 20);
}

TEST_F(VectorTest, reserveLessHasNoEffect) {
    MyVector.reserve(10);
    EXPECT_EQ(MyVector.capacity(), 10);
    MyVector.reserve(5);
    EXPECT_EQ(MyVector.capacity(), 10);
}

TEST_F(VectorTest, reserveTooMuchThrowExeption) {
    EXPECT_THROW(MyVector.reserve(MyVector.max_size() + 1), std::length_error);
}
