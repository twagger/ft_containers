/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:30:37 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:35:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_performance);

// Insert 1000000 
TYPED_TEST(Vector_performance, pushBack1000000) {
    VECTOR my_vector;
    for(int i = 0; i < 1000000; ++i)
    {
        my_vector.push_back(i);
    }
    EXPECT_EQ(my_vector.size(), 1000000);
}

// Insert 10000000 
TYPED_TEST(Vector_performance, pushBack10000000) {
    VECTOR my_vector;
    for(int i = 0; i < 10000000; ++i)
    {
        my_vector.push_back(i);
    }
    EXPECT_EQ(my_vector.size(), 10000000);
}

// Insert 100000000
TYPED_TEST(Vector_performance, pushBack100000000) {
    VECTOR my_vector;
    for(int i = 0; i < 100000000; ++i)
    {
        my_vector.push_back(i);
    }
    EXPECT_EQ(my_vector.size(), 100000000);
}