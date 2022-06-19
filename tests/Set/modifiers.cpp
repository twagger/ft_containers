/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:45:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/19 10:39:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_modifiers);

// Insert
// By val
TYPED_TEST(Set_modifiers, insertByVal) {
    SET         my_set;
    ITERATOR    it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 42);
    }
}

// By Range
TYPED_TEST(Set_modifiers, insertByRange) {
    SET         my_set;
    SET         my_set2;
    ITERATOR    it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);
    my_set.insert(46);
    my_set.insert(47);
    my_set2.insert(my_set.begin(), my_set.end());
    it = my_set2.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 45);
        EXPECT_EQ(*it++, 46);
        EXPECT_EQ(*it, 47);
    }
    else
    {
        EXPECT_EQ(*it++, 47);
        EXPECT_EQ(*it++, 46);
        EXPECT_EQ(*it++, 45);
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 42);
    }
    EXPECT_EQ(my_set2.size(), 6);
}

TYPED_TEST(Set_modifiers, insertByRangeWithDoubleKey) {
    SET         my_set;
    SET         my_set2;
    ITERATOR    it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);
    my_set.insert(46);
    my_set.insert(47);
    my_set2.insert(55);
    my_set2.insert(11);
    my_set2.insert(my_set.begin(), my_set.end());
    it = my_set2.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 11);
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 45);
        EXPECT_EQ(*it++, 46);
        EXPECT_EQ(*it++, 47);
        EXPECT_EQ(*it, 55);
    }
    else
    {
        EXPECT_EQ(*it++, 55);
        EXPECT_EQ(*it++, 47);
        EXPECT_EQ(*it++, 46);
        EXPECT_EQ(*it++, 45);
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it, 11);
    }
    EXPECT_EQ(my_set2.size(), 8);
}

/*
// By val with hint
TYPED_TEST(Set_modifiers, insertByValWithHint) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['t'] = 43;
    my_set['g'] = 44;
    my_set['p'] = 45;
    my_set['b'] = 46;
    my_set['y'] = 47;
    it = my_set.lower_bound('h');
    my_set.insert(it, PAIR('h', 88));
    EXPECT_EQ(my_set['h'], 88);
    EXPECT_EQ(my_set.size(), 7);
}

// Erase
// By position
TYPED_TEST(Set_modifiers, eraseByPositionRoot) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    it = my_set.find('b');
    my_set.erase(it);
    EXPECT_EQ(my_set['a'], 42);
    EXPECT_EQ(my_set['c'], 44);
}

TYPED_TEST(Set_modifiers, eraseByPositionNonRoot) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    it = my_set.find('a');
    my_set.erase(it);
    EXPECT_EQ(my_set['b'], 43);
    EXPECT_EQ(my_set['c'], 44);
}

TYPED_TEST(Set_modifiers, eraseByPositionOnlyNode) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    it = my_set.find('a');
    my_set.erase(it);
    EXPECT_EQ(my_set['a'], 0);
}

// By value
TYPED_TEST(Set_modifiers, eraseByValueRoot) {
    SET my_set;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set.erase('b');
    EXPECT_EQ(my_set['a'], 42);
    EXPECT_EQ(my_set['c'], 44);
}

TYPED_TEST(Set_modifiers, eraseByValueNonRoot) {
    SET my_set;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set.erase('a');
    EXPECT_EQ(my_set['b'], 43);
    EXPECT_EQ(my_set['c'], 44);
}

TYPED_TEST(Set_modifiers, eraseByValueOnlyNode) {
    SET my_set;
    my_set['a'] = 42;
    my_set.erase('a');
    EXPECT_EQ(my_set['a'], 0);
}

TYPED_TEST(Set_modifiers, eraseALot) {
    SET         my_set;
    const char  *to_erase = "abcdefghijklmnopqrstuvwxyz";
    my_set['a'] = 42;
    my_set['b'] = 42;
    my_set['c'] = 42;
    my_set['d'] = 42;
    my_set['e'] = 42;
    my_set['f'] = 42;
    my_set['g'] = 42;
    my_set['h'] = 42;
    my_set['i'] = 42;
    my_set['j'] = 42;
    my_set['k'] = 42;
    my_set['l'] = 42;
    my_set['m'] = 42;
    my_set['n'] = 42;
    my_set['o'] = 42;
    my_set['p'] = 42;
    my_set['q'] = 42;
    my_set['r'] = 42;
    my_set['s'] = 42;
    my_set['t'] = 42;
    my_set['u'] = 42;
    my_set['v'] = 42;
    my_set['w'] = 42;
    my_set['x'] = 42;
    my_set['y'] = 42;
    my_set['z'] = 42;
    for (int i = 0; i < 26; ++i)
        my_set.erase(to_erase[i]);
    EXPECT_EQ(my_set['a'], 0);
}

// By range
TYPED_TEST(Set_modifiers, eraseByRangeIncludingRoot) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    it = my_set.find('b');
    my_set.erase(it, my_set.end());
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_set['a'], 42);
        EXPECT_EQ(my_set['c'], 0);
    }
    else
    {
        EXPECT_EQ(my_set['a'], 0);
        EXPECT_EQ(my_set['c'], 44);
    }
}

TYPED_TEST(Set_modifiers, eraseByRangeNonIncludingRoot) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set['d'] = 48;
    it = my_set.find('c');
    my_set.erase(it, my_set.end());
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_set['a'], 42);
        EXPECT_EQ(my_set['b'], 43);
        EXPECT_EQ(my_set['c'], 0);
        EXPECT_EQ(my_set['d'], 0);
    }
    else
    {
        EXPECT_EQ(my_set['a'], 0);
        EXPECT_EQ(my_set['b'], 0);
        EXPECT_EQ(my_set['c'], 0);
        EXPECT_EQ(my_set['d'], 48);
    }
}

TYPED_TEST(Set_modifiers, eraseByRangeOneNode) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    it = my_set.find('a');
    my_set.erase(it, my_set.end());
    EXPECT_EQ(my_set['a'], 0);
}

TYPED_TEST(Set_modifiers, eraseByRangeIncludingBegin) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set['d'] = 48;
    it = my_set.find('c');
    my_set.erase(my_set.begin(), it);
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_set['a'], 0);
        EXPECT_EQ(my_set['b'], 0);
        EXPECT_EQ(my_set['c'], 44);
        EXPECT_EQ(my_set['d'], 48);
    }
    else
    {
        EXPECT_EQ(my_set['a'], 42);
        EXPECT_EQ(my_set['b'], 43);
        EXPECT_EQ(my_set['c'], 44);
        EXPECT_EQ(my_set['d'], 0);
    }
}

TYPED_TEST(Set_modifiers, eraseByRangeAllTree) {
    SET my_set;
    ITERATOR it;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set['d'] = 48;
    my_set.erase(my_set.begin(), my_set.end());
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(my_set['a'], 0);
        EXPECT_EQ(my_set['b'], 0);
        EXPECT_EQ(my_set['c'], 0);
        EXPECT_EQ(my_set['d'], 0);
    }
    else
    {
        EXPECT_EQ(my_set['a'], 0);
        EXPECT_EQ(my_set['b'], 0);
        EXPECT_EQ(my_set['c'], 0);
        EXPECT_EQ(my_set['d'], 0);
    }
}

// Clear
TYPED_TEST(Set_modifiers, clear) {
    SET my_set;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set.clear();
    EXPECT_EQ(my_set.size(), 0);
    EXPECT_EQ(my_set['a'], 0);
    EXPECT_EQ(my_set['b'], 0);
    EXPECT_EQ(my_set['c'], 0);
}

TYPED_TEST(Set_modifiers, swap) {
    SET my_set;
    SET my_set2;
    my_set['a'] = 42;
    my_set['b'] = 43;
    my_set['c'] = 44;
    my_set2['a'] = 12;
    my_set2['b'] = 13;
    my_set2['c'] = 14;
    my_set2['d'] = 15;
    my_set2['e'] = 16;
    my_set.swap(my_set2);
    EXPECT_EQ(my_set.size(), 5);
    EXPECT_EQ(my_set2.size(), 3);
    EXPECT_EQ(my_set['a'], 12);
    EXPECT_EQ(my_set['b'], 13);
    EXPECT_EQ(my_set['c'], 14);
    EXPECT_EQ(my_set['d'], 15);
    EXPECT_EQ(my_set['e'], 16);
    EXPECT_EQ(my_set2['a'], 42);
    EXPECT_EQ(my_set2['b'], 43);
    EXPECT_EQ(my_set2['c'], 44);
}
*/