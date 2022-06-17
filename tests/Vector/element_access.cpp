/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:22:48 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:29:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_element_access);

// operator[]
TYPED_TEST(Vector_element_access, operatorBracketInRange) {
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector[1], 43);
}

TYPED_TEST(Vector_element_access, operatorBracketOutOfRange) {
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(43);
    my_vector.push_back(44);
    EXPECT_EQ(my_vector[3], VECTOR::value_type());
}

// at
TYPED_TEST(Vector_element_access, atInRange) {
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector.at(1), 43);
}

TYPED_TEST(Vector_element_access, atOutOfRange) {
    VECTOR my_vector;
    my_vector.push_back(42);
    my_vector.push_back(43);
    EXPECT_THROW(my_vector.at(2), std::out_of_range);
}

// front
TYPED_TEST(Vector_element_access, frontOnNonEmpty) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector.front(), 41);
}

// back
TYPED_TEST(Vector_element_access, backOnNonEmpty) {
    VECTOR my_vector;
    my_vector.push_back(41);
    my_vector.push_back(43);
    EXPECT_EQ(my_vector.back(), 43);
}
