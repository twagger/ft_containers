/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:24:08 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 09:12:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_operations);

// Find
TYPED_TEST(Set_operations, findExisting) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.find(43);
    EXPECT_EQ(*it, 43);
}

TYPED_TEST(Set_operations, findNonExisting) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.find(58);
    EXPECT_EQ(it, my_set.end());
}

TYPED_TEST(Set_operations, findConst) {
    SET                 my_set;
    SET::const_iterator it;
     
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    const SET my_const_map = const_cast<SET&>(my_set);
    it = my_const_map.find(42);
    EXPECT_EQ(*it, 42);
}

// Count
TYPED_TEST(Set_operations, count) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    EXPECT_EQ(my_set.count(42), 1);
    EXPECT_EQ(my_set.count(58), 0);
}
 
// Lower bound
TYPED_TEST(Set_operations, lowerBound) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(41); //a
    my_set.insert(42); //b
    my_set.insert(44); //d
    my_set.insert(45); //e
    my_set.insert(50); //p
    my_set.insert(47); //g
    my_set.insert(48); //h
    my_set.insert(49); //i
     const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*(my_set.lower_bound(41)), 41);
        EXPECT_EQ(*(my_set.lower_bound(45)), 45);
        EXPECT_EQ(*(my_set.lower_bound(48)), 48);
        EXPECT_EQ(*(my_set.lower_bound(49)), 49);
        EXPECT_EQ(*(my_set.lower_bound(46)), 47);
    }
    else
    {
        EXPECT_EQ(*(my_set.lower_bound(41)), 41);
        EXPECT_EQ(*(my_set.lower_bound(45)), 45);
        EXPECT_EQ(*(my_set.lower_bound(48)), 48);
        EXPECT_EQ(*(my_set.lower_bound(49)), 49);
        EXPECT_EQ(*(my_set.lower_bound(46)), 45);
    }
}

// Upper bound
TYPED_TEST(Set_operations, upperBound) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(41); //a
    my_set.insert(42); //b
    my_set.insert(44); //d
    my_set.insert(45); //e
    my_set.insert(46); //f
    my_set.insert(47); //g
    my_set.insert(48); //h
    my_set.insert(49); //i
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*(my_set.upper_bound(41)), 42);
        EXPECT_EQ(*(my_set.upper_bound(43)), 44);
        EXPECT_EQ(*(my_set.upper_bound(48)), 49);
        EXPECT_EQ(my_set.upper_bound(49), my_set.end());
    }
    else
    {
        EXPECT_EQ(my_set.upper_bound(41), my_set.end());
        EXPECT_EQ(*(my_set.upper_bound(45)), 44);
        EXPECT_EQ(*(my_set.upper_bound(48)), 47);
        EXPECT_EQ(*(my_set.upper_bound(49)), 48);
    }
}

// Equal range
TYPED_TEST(Set_operations, equalRange) {
    SET         my_set;
    ITERATOR    it;
     
    my_set.insert(41); //a
    my_set.insert(42); //b
    my_set.insert(44); //d
    my_set.insert(45); //e
    my_set.insert(46); //f
    my_set.insert(47); //g
    my_set.insert(48); //h
    my_set.insert(49); //i
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*(my_set.equal_range(41).first), 41);
        EXPECT_EQ(*(my_set.equal_range(41).second), 42);
        EXPECT_EQ(*(my_set.equal_range(45).first), 45);
        EXPECT_EQ(*(my_set.equal_range(45).second),46);
        EXPECT_EQ(my_set.equal_range(50).first, my_set.end());
        EXPECT_EQ(my_set.equal_range(50).second, my_set.end());
    }
    else
    {
        EXPECT_EQ(*(my_set.equal_range(41).first), 41);
        EXPECT_EQ(*(my_set.equal_range(45).first), 45);
        EXPECT_EQ(*(my_set.equal_range(45).second), 44);
        EXPECT_EQ(*(my_set.equal_range(50).first), 49);
        EXPECT_EQ(*(my_set.equal_range(50).second), 49);
    }
}
