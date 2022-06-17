/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 08:20:24 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:29:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <vector>
#include "vector.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Vector_iterators);

// Iterators
TYPED_TEST(Vector_iterators, iteratorBasic) {
    VECTOR      my_vector;
    ITERATOR    it;
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    my_vector.push_back(42);
    it = my_vector.begin();
    it++;
    it--;
    EXPECT_EQ(it, my_vector.begin());
}
