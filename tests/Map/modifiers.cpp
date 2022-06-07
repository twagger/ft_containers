/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:45:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/07 14:36:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_modifiers);

// Erase
// By position
TYPED_TEST(Map_modifiers, eraseByPositionRoot) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('b');
    my_map.erase(it);
    EXPECT_EQ(my_map['a'], 42);
    EXPECT_EQ(my_map['c'], 44);
}

TYPED_TEST(Map_modifiers, eraseByPositionNonRoot) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('a');
    my_map.erase(it);
    EXPECT_EQ(my_map['b'], 43);
    EXPECT_EQ(my_map['c'], 44);
}

TYPED_TEST(Map_modifiers, eraseByPositionOnlyNode) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    it = my_map.find('a');
    my_map.erase(it);
    EXPECT_EQ(my_map['a'], 0);
}

// By value
TYPED_TEST(Map_modifiers, eraseByValueRoot) {
    MAP my_map;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map.erase('b');
    EXPECT_EQ(my_map['a'], 42);
    EXPECT_EQ(my_map['c'], 44);
}

TYPED_TEST(Map_modifiers, eraseByValueNonRoot) {
    MAP my_map;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map.erase('a');
    EXPECT_EQ(my_map['b'], 43);
    EXPECT_EQ(my_map['c'], 44);
}

TYPED_TEST(Map_modifiers, eraseByValueOnlyNode) {
    MAP my_map;
    my_map['a'] = 42;
    my_map.erase('a');
    EXPECT_EQ(my_map['a'], 0);
}

// By range
TYPED_TEST(Map_modifiers, eraseByRangeIncludingRoot) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('b');
    my_map.erase(it, my_map.end());
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_map['a'], 42);
        EXPECT_EQ(my_map['c'], 0);
    }
    else
    {
        EXPECT_EQ(my_map['a'], 0);
        EXPECT_EQ(my_map['c'], 44);
    }
}

TYPED_TEST(Map_modifiers, eraseByRangeNonIncludingRoot) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = 48;
    it = my_map.find('c');
    my_map.erase(it, my_map.end());
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_map['a'], 42);
        EXPECT_EQ(my_map['b'], 43);
        EXPECT_EQ(my_map['c'], 0);
        EXPECT_EQ(my_map['d'], 0);
    }
    else
    {
        EXPECT_EQ(my_map['a'], 0);
        EXPECT_EQ(my_map['b'], 0);
        EXPECT_EQ(my_map['c'], 0);
        EXPECT_EQ(my_map['d'], 48);
    }
}

TYPED_TEST(Map_modifiers, eraseByRangeOneNode) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    it = my_map.find('a');
    my_map.erase(it, my_map.end());
    EXPECT_EQ(my_map['a'], 0);
}

TYPED_TEST(Map_modifiers, eraseByRangeIncludingBegin) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = 48;
    it = my_map.find('c');
    my_map.erase(my_map.begin(), it);
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_map['a'], 0);
        EXPECT_EQ(my_map['b'], 0);
        EXPECT_EQ(my_map['c'], 44);
        EXPECT_EQ(my_map['d'], 48);
    }
    else
    {
        EXPECT_EQ(my_map['a'], 42);
        EXPECT_EQ(my_map['b'], 43);
        EXPECT_EQ(my_map['c'], 44);
        EXPECT_EQ(my_map['d'], 0);
    }
}

TYPED_TEST(Map_modifiers, eraseByRangeAllTree) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = 48;
    my_map.erase(my_map.begin(), my_map.end());
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_map['a'], 0);
        EXPECT_EQ(my_map['b'], 0);
        EXPECT_EQ(my_map['c'], 0);
        EXPECT_EQ(my_map['d'], 0);
    }
    else
    {
        EXPECT_EQ(my_map['a'], 0);
        EXPECT_EQ(my_map['b'], 0);
        EXPECT_EQ(my_map['c'], 0);
        EXPECT_EQ(my_map['d'], 0);
    }
}

// Clear
TYPED_TEST(Map_modifiers, clear) {
    MAP my_map;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map.clear();
    EXPECT_EQ(my_map.size(), 0);
    EXPECT_EQ(my_map['a'], 0);
    EXPECT_EQ(my_map['b'], 0);
    EXPECT_EQ(my_map['c'], 0);
}

TYPED_TEST(Map_modifiers, swap) {
    MAP my_map;
    MAP my_map2;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map2['a'] = 12;
    my_map2['b'] = 13;
    my_map2['c'] = 14;
    my_map2['d'] = 15;
    my_map2['e'] = 16;
    my_map.swap(my_map2);
    EXPECT_EQ(my_map.size(), 5);
    EXPECT_EQ(my_map2.size(), 3);
    EXPECT_EQ(my_map['a'], 12);
    EXPECT_EQ(my_map['b'], 13);
    EXPECT_EQ(my_map['c'], 14);
    EXPECT_EQ(my_map['d'], 15);
    EXPECT_EQ(my_map['e'], 16);
    EXPECT_EQ(my_map2['a'], 42);
    EXPECT_EQ(my_map2['b'], 43);
    EXPECT_EQ(my_map2['c'], 44);
}
