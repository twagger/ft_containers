/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:36:12 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:35:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_performance);

// Insert 1000000 
TYPED_TEST(Map_performance, insert1000000) {
    MAP my_map;
    for(int i = 0; i < 1000000; ++i)
    {
        my_map.insert(PAIR(i, 'a'));
    }
    EXPECT_EQ(my_map.size(), 1000000);
}

// Insert 10000000 
TYPED_TEST(Map_performance, insert10000000) {
    MAP my_map;
    for(int i = 0; i < 10000000; ++i)
    {
        my_map.insert(PAIR(i, 'a'));
    }
    EXPECT_EQ(my_map.size(), 10000000);
}

// Copy big map (must recycle nodes to save time)
TYPED_TEST(Map_performance, copy10000000) {
    MAP my_map;
    for(int i = 0; i < 10000000; ++i)
    {
        my_map.insert(PAIR(i, 'a'));
    }
    MAP my_map2;
    for(int i = 0; i < 5000000; ++i)
    {
        my_map.insert(PAIR(i, 'b'));
    }
    my_map2 = my_map;
    EXPECT_EQ(my_map2.size(), 10000000);
}

// Copy constructor (must recycle nodes to save time)
TYPED_TEST(Map_performance, copyConstructor10000000) {
    MAP my_map;
    for(int i = 0; i < 10000000; ++i)
    {
        my_map.insert(PAIR(i, 'a'));
    }
    MAP my_map2(my_map);
    EXPECT_EQ(my_map2.size(), 10000000);
}

// Erase (must recycle nodes to save time)
TYPED_TEST(Map_performance, erase1000000) {
    MAP my_map;
    for(int i = 0; i < 1000000; ++i)
    {
        my_map.insert(PAIR(i, 'a'));
    }
    for(int i = 277; i < 1000000; i = i + 254)
    {
        my_map.erase(i);
    }
    EXPECT_EQ(my_map.size(), 996064);
}
