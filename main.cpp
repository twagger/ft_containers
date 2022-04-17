/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:17:50 by twagner           #+#    #+#             */
/*   Updated: 2022/04/17 15:26:54 by twagner          ###   ########.fr       */
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
		ft::vector<int>	MyVector;
		std::vector<int> StdVector;
};

/* ************************************************************************** */
/*  CONSTRUCTOR TESTS                                                         */
/* ************************************************************************** */

TEST(VectorTest_Constructor, defaultConstructor) {
	ft::vector<int> MyVector;
	EXPECT_EQ(MyVector.size(), 0)
		<< "Default vector should be empty";
}

TEST(VectorTest_Constructor, fillConstructor) {
	ft::vector<int> MyVector(5, 42);
	for (int i = 0; i < 5; ++i)
	{
		EXPECT_EQ(MyVector[i], 42)
			<< "Filled vector should contain n elements with the given value";
	}
	EXPECT_THROW(MyVector[6], std::out_of_range)
		<< "Access to out of range value should throw an error";
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
/*
TEST_F(VectorTest, resize) {
	MyVector.resize(15, 5);
	StdVector.resize(15, 5);
	EXPECT_EQ(MyVector.size(), StdVector.size());
	EXPECT_EQ(MyVector.capacity(), StdVector.capacity());
	EXPECT_EQ(MyVector[12], StdVector[12]);
	EXPECT_EQ(MyVector[12], 5);
	MyVector.resize(2, 5);
	StdVector.resize(2, 5);
	EXPECT_EQ(MyVector.size(), StdVector.size());
	EXPECT_EQ(MyVector.capacity(), StdVector.capacity());
}
*/
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

// Element access tests

// Modifier tests

// Allocator tests

// Relational operator tests

// Swap tests

// Performance tests
