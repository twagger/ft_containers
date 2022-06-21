/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:45:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 08:24:28 by marvin           ###   ########.fr       */
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


// By val with hint
TYPED_TEST(Set_modifiers, insertByValWithHint) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);
    my_set.insert(46);
    my_set.insert(47);
    it = my_set.lower_bound(46);
    my_set.insert(it, 48);
    EXPECT_EQ(my_set.size(), 7);
}

// Erase
// By position
TYPED_TEST(Set_modifiers, eraseByPositionRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.find(43);
    my_set.erase(it);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    EXPECT_EQ(my_set.size(), 2);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it, 42);
    }
}

TYPED_TEST(Set_modifiers, eraseByPositionNonRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.find(42);
    my_set.erase(it);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    EXPECT_EQ(my_set.size(), 2);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it, 43);
    }
}

TYPED_TEST(Set_modifiers, eraseByPositionOnlyNode) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    it = my_set.find(42);
    my_set.erase(it);
    EXPECT_EQ(my_set.size(), 0);
}

// By value
TYPED_TEST(Set_modifiers, eraseByValueRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.erase(43);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    EXPECT_EQ(my_set.size(), 2);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it, 42);
    }
}

TYPED_TEST(Set_modifiers, eraseByValueNonRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.erase(42);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    EXPECT_EQ(my_set.size(), 2);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it, 43);
    }
}

TYPED_TEST(Set_modifiers, eraseByValueOnlyNode) {
    SET my_set;
    my_set.insert(42);
    my_set.erase(42);
    EXPECT_EQ(my_set.size(), 0);
}

TYPED_TEST(Set_modifiers, eraseALot) {
    SET         my_set;
    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(3);
    my_set.insert(4);
    my_set.insert(5);
    my_set.insert(6);
    my_set.insert(7);
    my_set.insert(8);
    my_set.insert(9);
    my_set.insert(10);
    my_set.insert(11);
    my_set.insert(12);
    my_set.insert(13);
    my_set.insert(14);
    my_set.insert(15);
    my_set.insert(16);
    my_set.insert(17);
    my_set.insert(18);
    my_set.insert(19);
    my_set.insert(20);
    my_set.insert(21);
    my_set.insert(22);
    my_set.insert(23);
    my_set.insert(24);
    my_set.insert(25);
    my_set.insert(26);
    for (int i = 0; i < 26; ++i)
        my_set.erase(i + 1);
    EXPECT_EQ(my_set.size(), 0);
}

// By range
TYPED_TEST(Set_modifiers, eraseByRangeIncludingRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.find(43);
    my_set.erase(it, my_set.end());
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    EXPECT_EQ(my_set.size(), 1);
    if (t_comp == t_less)
        EXPECT_EQ(*it, 42);
    else
        EXPECT_EQ(*it, 44);
}

TYPED_TEST(Set_modifiers, eraseByRangeNonIncludingRoot) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(48);
    it = my_set.find(44);
    my_set.erase(it, my_set.end());
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it, 43);
        EXPECT_EQ(my_set.size(), 2);
    }
    else
    {
        EXPECT_EQ(*it, 48);
        EXPECT_EQ(my_set.size(), 1);
    }
}

TYPED_TEST(Set_modifiers, eraseByRangeOneNode) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    it = my_set.find(42);
    my_set.erase(it, my_set.end());
    EXPECT_EQ(my_set.size(), 0);
}

TYPED_TEST(Set_modifiers, eraseByRangeIncludingBegin) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(48);
    it = my_set.find(44);
    my_set.erase(my_set.begin(), it);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it, 48);
        EXPECT_EQ(my_set.size(), 2);
    }
    else
    {
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 42);
        EXPECT_EQ(my_set.size(), 3);
    }
}

TYPED_TEST(Set_modifiers, eraseByRangeAllTree) {
    SET my_set;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(48);
    my_set.erase(my_set.begin(), my_set.end());
    EXPECT_EQ(my_set.size(), 0);
}

// Clear
TYPED_TEST(Set_modifiers, clear) {
    SET my_set;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.clear();
    EXPECT_EQ(my_set.size(), 0);
}

TYPED_TEST(Set_modifiers, swap) {
    SET my_set;
    SET my_set2;
    ITERATOR it;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set2.insert(12);
    my_set2.insert(13);
    my_set2.insert(14);
    my_set2.insert(15);
    my_set2.insert(16);
    my_set.swap(my_set2);
    EXPECT_EQ(my_set.size(), 5);
    EXPECT_EQ(my_set2.size(), 3);
    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it++, 12);
        EXPECT_EQ(*it++, 13);
        EXPECT_EQ(*it++, 14);
        EXPECT_EQ(*it++, 15);
        EXPECT_EQ(*it, 16);
        it = my_set2.begin();
        EXPECT_EQ(*it++, 42);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it++, 16);
        EXPECT_EQ(*it++, 15);
        EXPECT_EQ(*it++, 14);
        EXPECT_EQ(*it++, 13);
        EXPECT_EQ(*it, 12);
        it = my_set2.begin();
        EXPECT_EQ(*it++, 44);
        EXPECT_EQ(*it++, 43);
        EXPECT_EQ(*it, 42);
    }
}
