/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:46:58 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 08:35:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_constructors);

// Default constructor
TYPED_TEST(Set_constructors, defaultConstructor) {
    SET my_set;
    EXPECT_EQ(my_set.size(), 0);
}

// Ranged constructor
TYPED_TEST(Set_constructors, rangeConstructor) {
    SET my_set;
    my_set.insert(100);
    my_set.insert(500);
    my_set.insert(1800);
    my_set.insert(20);

    SET my_set_2(my_set.begin(), my_set.end());
    EXPECT_EQ(my_set.size(), my_set_2.size());
}

// Copy constructor
TYPED_TEST(Set_constructors, copyConstructor) {
    SET my_set;
    my_set.insert(100);
    my_set.insert(500);
    my_set.insert(1800);
    my_set.insert(20);
    SET my_set2(my_set);
    EXPECT_EQ(my_set.size(), my_set2.size());
}
