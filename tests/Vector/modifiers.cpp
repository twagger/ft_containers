#include "gtest/gtest.h"
#include "Vector.hpp"
#include "fixtures.hpp"

/* ************************************************************************** */
/*  MODIFIER TESTS                                                            */
/* ************************************************************************** */
// assign
TEST_F(VectorTest, assignRangeExtendsCapacity) {
    MyTmpVector.push_back(41);
    MyTmpVector.push_back(42);
    MyTmpVector.push_back(43);
    EXPECT_EQ(MyVector.capacity(), 0);
    EXPECT_EQ(MyTmpVector.capacity(), 4);
    MyVector.assign(MyTmpVector.begin(), MyTmpVector.end());
    EXPECT_EQ(MyVector.capacity(), 3);
}

TEST_F(VectorTest, assignRangeChangesSize) {
    MyTmpVector.push_back(41);
    MyTmpVector.push_back(42);
    MyTmpVector.push_back(43);
    MyVector.assign(MyTmpVector.begin(), MyTmpVector.end());
    EXPECT_EQ(MyVector.size(), 3);
}

TEST_F(VectorTest, assignRangeCopiesValues) {
    MyTmpVector.push_back(41);
    MyTmpVector.push_back(42);
    MyTmpVector.push_back(43);
    MyVector.assign(MyTmpVector.begin(), MyTmpVector.end());
    EXPECT_EQ(std::equal(MyVector.begin(), MyVector.end(), \
        MyTmpVector.begin()), true);
}

TEST_F(VectorTest, assignFillExtendsCapacity) {
    EXPECT_EQ(MyVector.capacity(), 0);
    MyVector.assign(5, 42);
    EXPECT_EQ(MyVector.capacity(), 5);
}

TEST_F(VectorTest, assignFillChangesSize) {
    EXPECT_EQ(MyVector.size(), 0);
    MyVector.assign(5, 42);
    EXPECT_EQ(MyVector.size(), 5);
}

TEST_F(VectorTest, assignFillCopiesValues) {
    MyVector.assign(5, 42);
    for (int i = 0; i < MyVector.size(); ++i)
        EXPECT_EQ(MyVector[i], 42);
}

// push back
TEST_F(VectorTest, pushBackOk) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
}

TEST_F(VectorTest, pushBackDoubleCapacity) {
    MyVector.push_back(41);
    EXPECT_EQ(MyVector.capacity(), 1);
    MyVector.push_back(42);
    EXPECT_EQ(MyVector.capacity(), 2);
    MyVector.push_back(43);
    EXPECT_EQ(MyVector.capacity(), 4);
    MyVector.push_back(44);
    MyVector.push_back(45);
    EXPECT_EQ(MyVector.capacity(), 8);
}

// pop back
TEST_F(VectorTest, popBackOk) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    StdVector.push_back(41);
    StdVector.push_back(42);
    StdVector.push_back(43);
    EXPECT_EQ(MyVector.back(), 43);
    EXPECT_EQ(StdVector.back(), 43);
    MyVector.pop_back();
    StdVector.pop_back();
    EXPECT_EQ(MyVector.back(), 42);
    EXPECT_EQ(StdVector.back(), 42);
}

TEST_F(VectorTest, popBackEmptyNoThrow) {
    EXPECT_NO_THROW(MyVector.pop_back());
    EXPECT_NO_THROW(StdVector.pop_back());
}

// clear
TEST_F(VectorTest, clearOk) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    StdVector.push_back(41);
    StdVector.push_back(42);
    StdVector.push_back(43);
    MyVector.clear();
    StdVector.clear();
    MyVector.push_back(666);
    StdVector.push_back(666);
    EXPECT_EQ(MyVector.front(), 666);
    EXPECT_EQ(StdVector.front(), 666);
}

TEST_F(VectorTest, clearChangesSizeToZero) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    StdVector.push_back(41);
    StdVector.push_back(42);
    StdVector.push_back(43);
    MyVector.clear();
    StdVector.clear();
    EXPECT_EQ(MyVector.size(), 0);
    EXPECT_EQ(StdVector.size(), 0);
}

TEST_F(VectorTest, clearDoesntAffectCapacity) {
    ft::vector<int>::size_type	capaMy;
    std::vector<int>::size_type	capaStd;
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    capaMy = MyVector.capacity();
    StdVector.push_back(41);
    StdVector.push_back(42);
    StdVector.push_back(43);
    capaStd = StdVector.capacity();
    MyVector.clear();
    StdVector.clear();
    EXPECT_EQ(MyVector.capacity(), capaMy);
    EXPECT_EQ(StdVector.capacity(), capaStd);
}

// Insert
TEST_F(VectorTest, insertSingleBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.begin(), 40);
    EXPECT_EQ(MyVector.size(), 4);
    EXPECT_EQ(MyVector.capacity(), 4);
    EXPECT_EQ(MyVector[0], 40);
    EXPECT_EQ(MyVector[1], 41);
    EXPECT_EQ(MyVector[2], 42);
    EXPECT_EQ(MyVector[3], 43);
}

TEST_F(VectorTest, insertSingleEnd) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.end(), 44);
    EXPECT_EQ(MyVector.size(), 4);
    EXPECT_EQ(MyVector.capacity(), 4);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
    EXPECT_EQ(MyVector[3], 44);
}

TEST_F(VectorTest, insertSingleMiddle) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.begin() + 2, 88);
    EXPECT_EQ(MyVector.size(), 4);
    EXPECT_EQ(MyVector.capacity(), 4);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 88);
    EXPECT_EQ(MyVector[3], 43);
}

TEST_F(VectorTest, insertIncreaseCapacity) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.begin() + 2, 88);
    MyVector.insert(MyVector.begin(), 100);
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 5);
    EXPECT_EQ(MyVector[0], 100);
    EXPECT_EQ(MyVector[1], 41);
    EXPECT_EQ(MyVector[2], 42);
    EXPECT_EQ(MyVector[3], 88);
    EXPECT_EQ(MyVector[4], 43);
}

TEST_F(VectorTest, insertFillBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.begin(), 1, 42);
    EXPECT_EQ(MyVector.size(), 4);
    EXPECT_EQ(MyVector.capacity(), 4);
    EXPECT_EQ(MyVector[0], 42);
    EXPECT_EQ(MyVector[1], 41);
    EXPECT_EQ(MyVector[2], 42);
    EXPECT_EQ(MyVector[3], 43);
}

TEST_F(VectorTest, insertFillIncreaseCapacity) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.insert(MyVector.begin(), 5, 42);
    EXPECT_EQ(MyVector.size(), 8);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_EQ(MyVector[0], 42);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 42);
    EXPECT_EQ(MyVector[3], 42);
    EXPECT_EQ(MyVector[4], 42);
    EXPECT_EQ(MyVector[5], 41);
    EXPECT_EQ(MyVector[6], 42);
    EXPECT_EQ(MyVector[7], 43);
}

TEST_F(VectorTest, insertFillEnd) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyVector.insert(MyVector.end(), 2, 42);
    EXPECT_EQ(MyVector.size(), 7);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
    EXPECT_EQ(MyVector[3], 44);
    EXPECT_EQ(MyVector[4], 45);
    EXPECT_EQ(MyVector[5], 42);
    EXPECT_EQ(MyVector[6], 42);
}

TEST_F(VectorTest, insertFillMiddle) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyVector.insert(MyVector.begin() + 3, 2, 42);
    EXPECT_EQ(MyVector.size(), 7);
    EXPECT_EQ(MyVector.capacity(), 8);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
    EXPECT_EQ(MyVector[3], 42);
    EXPECT_EQ(MyVector[4], 42);
    EXPECT_EQ(MyVector[5], 44);
    EXPECT_EQ(MyVector[6], 45);
}

TEST_F(VectorTest, insertRangeBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyTmpVector.push_back(1);
    MyTmpVector.push_back(2);
    MyTmpVector.push_back(3);
    MyVector.insert(MyVector.begin(), MyTmpVector.begin(), MyTmpVector.end());
    EXPECT_EQ(MyVector.size(), 6);
    EXPECT_EQ(MyVector.capacity(), 6);
    EXPECT_EQ(MyVector[0], 1);
    EXPECT_EQ(MyVector[1], 2);
    EXPECT_EQ(MyVector[2], 3);
    EXPECT_EQ(MyVector[3], 41);
    EXPECT_EQ(MyVector[4], 42);
    EXPECT_EQ(MyVector[5], 43);
}

TEST_F(VectorTest, insertPartRangeBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyTmpVector.push_back(1);
    MyTmpVector.push_back(2);
    MyTmpVector.push_back(3);
    MyVector.insert(MyVector.begin(), MyTmpVector.begin() + 1, \
        MyTmpVector.end());
    EXPECT_EQ(MyVector.size(), 5);
    EXPECT_EQ(MyVector.capacity(), 5);
    EXPECT_EQ(MyVector[0], 2);
    EXPECT_EQ(MyVector[1], 3);
    EXPECT_EQ(MyVector[2], 41);
    EXPECT_EQ(MyVector[3], 42);
    EXPECT_EQ(MyVector[4], 43);
}

TEST_F(VectorTest, insertRangeEnd) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyTmpVector.push_back(1);
    MyTmpVector.push_back(2);
    MyTmpVector.push_back(3);
    MyVector.insert(MyVector.end(), MyTmpVector.begin(), MyTmpVector.end());
    EXPECT_EQ(MyVector.size(), 6);
    EXPECT_EQ(MyVector.capacity(), 6);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
    EXPECT_EQ(MyVector[3], 1);
    EXPECT_EQ(MyVector[4], 2);
    EXPECT_EQ(MyVector[5], 3);
}

TEST_F(VectorTest, insertRangeMiddle) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyTmpVector.push_back(1);
    MyTmpVector.push_back(2);
    MyTmpVector.push_back(3);
    MyVector.insert(MyVector.begin() + 2, MyTmpVector.begin(), \
        MyTmpVector.end());
    EXPECT_EQ(MyVector.size(), 6);
    EXPECT_EQ(MyVector.capacity(), 6);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 1);
    EXPECT_EQ(MyVector[3], 2);
    EXPECT_EQ(MyVector[4], 3);
    EXPECT_EQ(MyVector[5], 43);
}

// Erase
TEST_F(VectorTest, eraseSingleBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.erase(MyVector.begin());
    EXPECT_EQ(MyVector.size(), 2);
    EXPECT_EQ(MyVector[0], 42);
    EXPECT_EQ(MyVector[1], 43);
}

TEST_F(VectorTest, eraseSingleEnd) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.erase(MyVector.end() - 1);
    EXPECT_EQ(MyVector.size(), 2);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
}

TEST_F(VectorTest, eraseSingleMiddle) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.erase(MyVector.begin() + 1);
    EXPECT_EQ(MyVector.size(), 2);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 43);
}

TEST_F(VectorTest, eraseRangeBegin) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyVector.erase(MyVector.begin(), MyVector.begin() + 2);
    EXPECT_EQ(MyVector.size(), 3);
    EXPECT_EQ(MyVector[0], 43);
    EXPECT_EQ(MyVector[1], 44);
    EXPECT_EQ(MyVector[2], 45);
    // Test against std
    StdVector.push_back(41);
    StdVector.push_back(42);
    StdVector.push_back(43);
    StdVector.push_back(44);
    StdVector.push_back(45);
    StdVector.erase(StdVector.begin(), StdVector.begin() + 2);
    EXPECT_EQ(StdVector.size(), 3);
    EXPECT_EQ(StdVector[0], 43);
    EXPECT_EQ(StdVector[1], 44);
    EXPECT_EQ(StdVector[2], 45);

}

TEST_F(VectorTest, eraseRangeEnd) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyVector.erase(MyVector.end() - 2, MyVector.end());
    EXPECT_EQ(MyVector.size(), 3);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 42);
    EXPECT_EQ(MyVector[2], 43);
}

TEST_F(VectorTest, eraseRangeMiddle) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyVector.erase(MyVector.begin() + 1, MyVector.begin() + 3);
    EXPECT_EQ(MyVector.size(), 3);
    EXPECT_EQ(MyVector[0], 41);
    EXPECT_EQ(MyVector[1], 44);
    EXPECT_EQ(MyVector[2], 45);
}

// Swap
TEST_F(VectorTest, swapBasic) {
    MyVector.push_back(41);
    MyVector.push_back(42);
    MyVector.push_back(43);
    MyVector.push_back(44);
    MyVector.push_back(45);
    MyTmpVector.push_back(1);
    MyTmpVector.push_back(2);
    MyVector.swap(MyTmpVector);
    EXPECT_EQ(MyVector.size(), 2);
    EXPECT_EQ(MyVector.capacity(), 2);
    EXPECT_EQ(MyTmpVector.size(), 5);
    EXPECT_EQ(MyTmpVector.capacity(), 8);
    EXPECT_EQ(MyVector[0], 1);
    EXPECT_EQ(MyVector[1], 2);
    EXPECT_EQ(MyTmpVector[0], 41);
    EXPECT_EQ(MyTmpVector[1], 42);
    EXPECT_EQ(MyTmpVector[2], 43);
    EXPECT_EQ(MyTmpVector[3], 44);
    EXPECT_EQ(MyTmpVector[4], 45);
}
