/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 06:55:56 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:29:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_modifiers);

// Assign
TYPED_TEST(Vector_modifiers, assignRangeExtendsCapacity) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector.capacity(), 0);
    EXPECT_EQ(my_vector2.capacity(), 4);
    my_vector.assign(my_vector2.begin(), my_vector2.end());
    EXPECT_EQ(my_vector.capacity(), 3);
}

TYPED_TEST(Vector_modifiers, assignRangeChangesSize) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    my_vector.assign(my_vector2.begin(), my_vector2.end());
    EXPECT_EQ(my_vector.size(), 3);
}

TYPED_TEST(Vector_modifiers, assignRangeCopiesValues) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    my_vector.assign(my_vector2.begin(), my_vector2.end());
    EXPECT_EQ(std::equal(my_vector.begin(), my_vector.end(), \
        my_vector2.begin()), true);
}

TYPED_TEST(Vector_modifiers, assignFillExtendsCapacity) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.capacity(), 0);
    my_vector.assign(5, 42);
    EXPECT_EQ(my_vector.capacity(), 5);
}

TYPED_TEST(Vector_modifiers, assignFillChangesSize) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.size(), 0);
    my_vector.assign(5, 42);
    EXPECT_EQ(my_vector.size(), 5);
}

TYPED_TEST(Vector_modifiers, assignFillCopiesValues) {
    VECTOR my_vector;
    my_vector.assign(5, 42);
    for (int i = 0; i < my_vector.size(); ++i)
        EXPECT_EQ(my_vector[i], 42);
}

// push back
TYPED_TEST(Vector_modifiers, pushBackOk) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
}

TYPED_TEST(Vector_modifiers, pushBackDoubleCapacity) {
    VECTOR my_vector;
    my_vector.push_back(41);
    EXPECT_EQ(my_vector.capacity(), 1);
    my_vector.push_back(42);
    EXPECT_EQ(my_vector.capacity(), 2);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector.capacity(), 4);
    my_vector.push_back(44);
    my_vector.push_back(45);
    EXPECT_EQ(my_vector.capacity(), 8);
}

// pop back
TYPED_TEST(Vector_modifiers, popBackOk) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector.back(), 43);
    my_vector.pop_back();
    EXPECT_EQ(my_vector.back(), 42);
}

TYPED_TEST(Vector_modifiers, popBackEmptyNoThrow) {
    VECTOR my_vector;
    EXPECT_NO_THROW(my_vector.pop_back());
}

// clear
TYPED_TEST(Vector_modifiers, clearOk) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.clear();
    my_vector.push_back(666);
    EXPECT_EQ(my_vector.front(), 666);
}

TYPED_TEST(Vector_modifiers, clearChangesSizeToZero) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.clear();
    EXPECT_EQ(my_vector.size(), 0);
}

TYPED_TEST(Vector_modifiers, clearDoesntAffectCapacity) {
    VECTOR              my_vector;
    VECTOR::size_type   capa;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    capa = my_vector.capacity();
    my_vector.clear();
    EXPECT_EQ(my_vector.capacity(), capa);
}

// Insert
TYPED_TEST(Vector_modifiers, insertSingleBegin) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.begin(), 40);
    EXPECT_EQ(my_vector.size(), 4);
    EXPECT_EQ(my_vector.capacity(), 4);
    EXPECT_EQ(my_vector[0], 40);
    EXPECT_EQ(my_vector[1], 41);
    EXPECT_EQ(my_vector[2], 42);
    EXPECT_EQ(my_vector[3], 43);
}

TYPED_TEST(Vector_modifiers, insertSingleEnd) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.end(), 44);
    EXPECT_EQ(my_vector.size(), 4);
    EXPECT_EQ(my_vector.capacity(), 4);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
    EXPECT_EQ(my_vector[3], 44);
}

TYPED_TEST(Vector_modifiers, insertSingleMiddle) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.begin() + 2, 88);
    EXPECT_EQ(my_vector.size(), 4);
    EXPECT_EQ(my_vector.capacity(), 4);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 88);
    EXPECT_EQ(my_vector[3], 43);
}

TYPED_TEST(Vector_modifiers, insertIncreaseCapacity) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.begin() + 2, 88);
    my_vector.insert(my_vector.begin(), 100);
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[0], 100);
    EXPECT_EQ(my_vector[1], 41);
    EXPECT_EQ(my_vector[2], 42);
    EXPECT_EQ(my_vector[3], 88);
    EXPECT_EQ(my_vector[4], 43);
}

TYPED_TEST(Vector_modifiers, insertFillBegin) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.begin(), 1, 42);
    EXPECT_EQ(my_vector.size(), 4);
    EXPECT_EQ(my_vector.capacity(), 4);
    EXPECT_EQ(my_vector[0], 42);
    EXPECT_EQ(my_vector[1], 41);
    EXPECT_EQ(my_vector[2], 42);
    EXPECT_EQ(my_vector[3], 43);
}

TYPED_TEST(Vector_modifiers, insertFillIncreaseCapacity) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.insert(my_vector.begin(), 5, 42);
    EXPECT_EQ(my_vector.size(), 8);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[0], 42);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 42);
    EXPECT_EQ(my_vector[3], 42);
    EXPECT_EQ(my_vector[4], 42);
    EXPECT_EQ(my_vector[5], 41);
    EXPECT_EQ(my_vector[6], 42);
    EXPECT_EQ(my_vector[7], 43);
}

TYPED_TEST(Vector_modifiers, insertFillEnd) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector.insert(my_vector.end(), 2, 42);
    EXPECT_EQ(my_vector.size(), 7);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
    EXPECT_EQ(my_vector[3], 44);
    EXPECT_EQ(my_vector[4], 45);
    EXPECT_EQ(my_vector[5], 42);
    EXPECT_EQ(my_vector[6], 42);
}

TYPED_TEST(Vector_modifiers, insertFillMiddle) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector.insert(my_vector.begin() + 3, 2, 42);
    EXPECT_EQ(my_vector.size(), 7);
    EXPECT_EQ(my_vector.capacity(), 8);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
    EXPECT_EQ(my_vector[3], 42);
    EXPECT_EQ(my_vector[4], 42);
    EXPECT_EQ(my_vector[5], 44);
    EXPECT_EQ(my_vector[6], 45);
}

TYPED_TEST(Vector_modifiers, insertRangeBegin) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    my_vector2.push_back(3);
    my_vector.insert(my_vector.begin(), my_vector2.begin(), my_vector2.end());
    EXPECT_EQ(my_vector.size(), 6);
    EXPECT_EQ(my_vector.capacity(), 6);
    EXPECT_EQ(my_vector[0], 1);
    EXPECT_EQ(my_vector[1], 2);
    EXPECT_EQ(my_vector[2], 3);
    EXPECT_EQ(my_vector[3], 41);
    EXPECT_EQ(my_vector[4], 42);
    EXPECT_EQ(my_vector[5], 43);
}

TYPED_TEST(Vector_modifiers, insertPartRangeBegin) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    my_vector2.push_back(3);
    my_vector.insert(my_vector.begin(), my_vector2.begin() + 1, \
        my_vector2.end());
    EXPECT_EQ(my_vector.size(), 5);
    EXPECT_EQ(my_vector.capacity(), 6);
    EXPECT_EQ(my_vector[0], 2);
    EXPECT_EQ(my_vector[1], 3);
    EXPECT_EQ(my_vector[2], 41);
    EXPECT_EQ(my_vector[3], 42);
    EXPECT_EQ(my_vector[4], 43);
}

TYPED_TEST(Vector_modifiers, insertRangeEnd) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    my_vector2.push_back(3);
    my_vector.insert(my_vector.end(), my_vector2.begin(), my_vector2.end());
    EXPECT_EQ(my_vector.size(), 6);
    EXPECT_EQ(my_vector.capacity(), 6);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
    EXPECT_EQ(my_vector[3], 1);
    EXPECT_EQ(my_vector[4], 2);
    EXPECT_EQ(my_vector[5], 3);
}

TYPED_TEST(Vector_modifiers, insertRangeMiddle) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    my_vector2.push_back(3);
    my_vector.insert(my_vector.begin() + 2, my_vector2.begin(), \
        my_vector2.end());
    EXPECT_EQ(my_vector.size(), 6);
    EXPECT_EQ(my_vector.capacity(), 6);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 1);
    EXPECT_EQ(my_vector[3], 2);
    EXPECT_EQ(my_vector[4], 3);
    EXPECT_EQ(my_vector[5], 43);
}

// Erase
TYPED_TEST(Vector_modifiers, eraseSingleBegin) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.erase(my_vector.begin());
    EXPECT_EQ(my_vector.size(), 2);
    EXPECT_EQ(my_vector[0], 42);
    EXPECT_EQ(my_vector[1], 43);
}

TYPED_TEST(Vector_modifiers, eraseSingleEnd) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.erase(my_vector.end() - 1);
    EXPECT_EQ(my_vector.size(), 2);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
}

TYPED_TEST(Vector_modifiers, eraseSingleMiddle) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.erase(my_vector.begin() + 1);
    EXPECT_EQ(my_vector.size(), 2);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 43);
}

TYPED_TEST(Vector_modifiers, eraseRangeBegin) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector.erase(my_vector.begin(), my_vector.begin() + 2);
    EXPECT_EQ(my_vector.size(), 3);
    EXPECT_EQ(my_vector[0], 43);
    EXPECT_EQ(my_vector[1], 44);
    EXPECT_EQ(my_vector[2], 45);
}

TYPED_TEST(Vector_modifiers, eraseRangeEnd) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector.erase(my_vector.end() - 2, my_vector.end());
    EXPECT_EQ(my_vector.size(), 3);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 42);
    EXPECT_EQ(my_vector[2], 43);
}

TYPED_TEST(Vector_modifiers, eraseRangeMiddle) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector.erase(my_vector.begin() + 1, my_vector.begin() + 3);
    EXPECT_EQ(my_vector.size(), 3);
    EXPECT_EQ(my_vector[0], 41);
    EXPECT_EQ(my_vector[1], 44);
    EXPECT_EQ(my_vector[2], 45);
}

// Swap
TYPED_TEST(Vector_modifiers, swapBasic) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    my_vector.push_back(45);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    my_vector.swap(my_vector2);
    EXPECT_EQ(my_vector.size(), 2);
    EXPECT_EQ(my_vector.capacity(), 2);
    EXPECT_EQ(my_vector2.size(), 5);
    EXPECT_EQ(my_vector2.capacity(), 8);
    EXPECT_EQ(my_vector[0], 1);
    EXPECT_EQ(my_vector[1], 2);
    EXPECT_EQ(my_vector2[0], 41);
    EXPECT_EQ(my_vector2[1], 42);
    EXPECT_EQ(my_vector2[2], 43);
    EXPECT_EQ(my_vector2[3], 44);
    EXPECT_EQ(my_vector2[4], 45);
}
