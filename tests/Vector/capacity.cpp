/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:22:31 by marvin            #+#    #+#             */
/*   Updated: 2022/06/12 09:28:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "Vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_capacity);

// capacity
TYPED_TEST(Vector_capacity, ZeroCapacity) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.capacity(), 0);
}

// Max size
TYPED_TEST(Vector_capacity, maxSize) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.max_size(), 2305843009213693951);
}

// Resize
TYPED_TEST(Vector_capacity, resizeBiggerSizeSameCapa){
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    my_vector.resize(7, 38);
    EXPECT_EQ(my_vector.size(), 7);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[5], 38);
}

TYPED_TEST(Vector_capacity, resizeBiggerSizeBiggerCapa){
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    my_vector.resize(22, 38);
    EXPECT_EQ(my_vector.size(), 22);
    EXPECT_EQ(my_vector.capacity(), 22);
    EXPECT_EQ(my_vector[20], 38);
}

TYPED_TEST(Vector_capacity, resizeSmallerSize){
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    my_vector.resize(2, 38);
    EXPECT_EQ(my_vector.size(), 2);
    EXPECT_EQ(my_vector.capacity(), 8);
}

TYPED_TEST(Vector_capacity, resizeSameSize){
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    my_vector.resize(5, 38);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[3], 42);
}

// Reserve
TYPED_TEST(Vector_capacity, reserveBasic) {
    VECTOR my_vector;
    my_vector.reserve(10);
    EXPECT_EQ(my_vector.capacity(), 10);
}

TYPED_TEST(Vector_capacity, doubleCapacityIfNeeded) {
    VECTOR my_vector;
    my_vector.reserve(10);
    for (int i = 0; i < 11; ++i)
    {
        my_vector.push_back(i);
    }
    EXPECT_EQ(my_vector.capacity(), 20);
}

TYPED_TEST(Vector_capacity, reserveLessHasNoEffect) {
    VECTOR my_vector;
    my_vector.reserve(10);
    EXPECT_EQ(my_vector.capacity(), 10);
    my_vector.reserve(5);
    EXPECT_EQ(my_vector.capacity(), 10);
}

TYPED_TEST(Vector_capacity, reserveTooMuchThrowExeption) {
    VECTOR my_vector;
    EXPECT_THROW(my_vector.reserve(my_vector.max_size() + 1), std::length_error);
}
