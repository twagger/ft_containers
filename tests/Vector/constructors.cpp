/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:28:38 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:29:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_constructors);

// Default constructor
TYPED_TEST(Vector_constructors, defaultConstructorEmptySize) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.size(), 0);
}

TYPED_TEST(Vector_constructors, defaultConstructorEmptyCapacity) {
    VECTOR my_vector;
    EXPECT_EQ(my_vector.capacity(), 0);
}

// Fill constructor
TYPED_TEST(Vector_constructors, fillConstructor) {
    VECTOR my_vector(5, 42);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(my_vector[i], 42);
    }
}

// Range constructor
TYPED_TEST(Vector_constructors, rangeConstructor) {
    VECTOR my_vector(5, 42);
    VECTOR my_vector2(my_vector.begin(), my_vector.end());
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(my_vector[i], my_vector2[i]);
    }
    EXPECT_EQ(my_vector.size(), my_vector2.size());
    EXPECT_EQ(my_vector.capacity(), my_vector2.capacity());
}

// Copy constructor
TYPED_TEST(Vector_constructors, copyConstructor) {
    VECTOR my_vector(10, 42);
    VECTOR my_vector2(my_vector);
    EXPECT_EQ(my_vector.size(), my_vector2.size());
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(my_vector2[i], my_vector[i]);
    }
}
