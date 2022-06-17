/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:34:22 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:29:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_operators);

// Equal
TYPED_TEST(Vector_operators, equalOperatorFalse) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(1);
    my_vector2.push_back(2);
    EXPECT_EQ(my_vector == my_vector2, false);
}

TYPED_TEST(Vector_operators, equalOperatorTrue) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector == my_vector2, true);
}

TYPED_TEST(Vector_operators, equalOperatorEmpty) {
    VECTOR my_vector;
    VECTOR my_vector2;
    EXPECT_EQ(my_vector == my_vector2, true);
}

TYPED_TEST(Vector_operators, greaterThanOperatorFalse) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector > my_vector2, false);
}

TYPED_TEST(Vector_operators, greaterThanOperatorTrue) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(43);
    my_vector.push_back(43);
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector > my_vector2, true);
}

TYPED_TEST(Vector_operators, greaterThanOrEqualOperatorFalse) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector >= my_vector2, false);
}

TYPED_TEST(Vector_operators, greaterThanOrEqualOperatorTrue) {
    VECTOR my_vector;
    VECTOR my_vector2;
    my_vector.push_back(41);
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector2.push_back(41);
    my_vector2.push_back(42);
    my_vector2.push_back(43);
    EXPECT_EQ(my_vector >= my_vector2, true);
}
