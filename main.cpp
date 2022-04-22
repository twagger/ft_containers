/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:17:50 by twagner           #+#    #+#             */
/*   Updated: 2022/04/22 15:04:47 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "containers/Vector.hpp"

#include <gtest/gtest.h>

/*
** ------------------------
** Commands to launch tests
** ------------------------
**  cmake -S . -B build && cmake --build build && cd build && ctest ; cd ..
**  cmake -S . -B build && cmake --build build && cd build && ctest --verbose ; cd ..
*/

class VectorTest : public ::testing::Test {
	protected:
		ft::vector<int>		MyVector;
		ft::vector<int>		MyTmpVector;
		std::vector<int>	StdVector;
		std::vector<int>	StdTmpVector;
};

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

/*
TEST(VectorTest_NoFixture, rangeConstructor) {
	ft::vector<int> MyVector;
	EXPECT_EQ(MyVector.size(), 0)
		<< "Ranged vector should";
}
*/

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

// Member type tests > SFINAE ?

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

/* ************************************************************************** */
/*  CAPACITY TESTS                                                            */
/* ************************************************************************** */
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
	EXPECT_EQ(std::equal(MyVector.begin(), MyVector.end(), MyTmpVector.begin()), true);
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
TEST_F(VectorTest, insertBegin) {
	MyVector.push_back(41);
	MyVector.push_back(42);
	MyVector.push_back(43);
	EXPECT_EQ(MyVector.size(), 3);
	EXPECT_EQ(MyVector.capacity(), 4);
	MyVector.insert(MyVector.begin(), 40);
	EXPECT_EQ(MyVector.size(), 1);
	EXPECT_EQ(MyVector.capacity(), 4);
	EXPECT_EQ(MyVector[0], 40);
	EXPECT_EQ(MyVector[1], 41);
	EXPECT_EQ(MyVector[2], 42);
	EXPECT_EQ(MyVector[3], 43);
}