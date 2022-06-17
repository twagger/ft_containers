/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:46:58 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:27:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_constructors);

// Default constructor
TYPED_TEST(Map_constructors, defaultConstructor) {
    MAP my_map;
    EXPECT_EQ(my_map.size(), 0);
}

// Ranged constructor
TYPED_TEST(Map_constructors, rangeConstructor) {
    MAP my_map;
    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));

    MAP my_map_2(my_map.begin(), my_map.end());
    EXPECT_EQ(my_map.size(), my_map_2.size());
}

// Copy constructor
TYPED_TEST(Map_constructors, copyConstructor) {
    MAP my_map;
    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));
    MAP my_map2(my_map);
    EXPECT_EQ(my_map.size(), my_map2.size());
    EXPECT_EQ(my_map['b'], my_map2['b']);
}
