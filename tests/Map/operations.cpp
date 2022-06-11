/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:24:08 by marvin            #+#    #+#             */
/*   Updated: 2022/06/11 10:39:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_operations);

// Find
TYPED_TEST(Map_operations, findExisting) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('b');
    EXPECT_EQ((*it).first, 'b');
    EXPECT_EQ((*it).second, 43);
}

TYPED_TEST(Map_operations, findNonExisting) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('t');
    EXPECT_EQ(it, my_map.end());
}

TYPED_TEST(Map_operations, findConst) {
    MAP                 my_map;
    MAP::const_iterator it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    const MAP my_const_map = const_cast<MAP&>(my_map);
    it = my_const_map.find('a');
    EXPECT_EQ((*it).first, 'a');
    EXPECT_EQ((*it).second, 42);
}

// Count
TYPED_TEST(Map_operations, count) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    EXPECT_EQ(my_map.count('a'), 1);
    EXPECT_EQ(my_map.count('z'), 0);
}
 
// Lower bound
TYPED_TEST(Map_operations, lowerBound) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['d'] = 44;
    my_map['e'] = 45;
    my_map['p'] = 46;
    my_map['g'] = 47;
    my_map['h'] = 48;
    my_map['i'] = 49;
     const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ((*(my_map.lower_bound('a'))).first, 'a');
        EXPECT_EQ((*(my_map.lower_bound('e'))).first, 'e');
        EXPECT_EQ((*(my_map.lower_bound('h'))).first, 'h');
        EXPECT_EQ((*(my_map.lower_bound('i'))).first, 'i');
        EXPECT_EQ((*(my_map.lower_bound('f'))).first, 'g');
    }
    else
    {
        EXPECT_EQ((*(my_map.lower_bound('a'))).first, 'a');
        EXPECT_EQ((*(my_map.lower_bound('e'))).first, 'e');
        EXPECT_EQ((*(my_map.lower_bound('h'))).first, 'h');
        EXPECT_EQ((*(my_map.lower_bound('i'))).first, 'i');
        EXPECT_EQ((*(my_map.lower_bound('f'))).first, 'e');
    }
}

// Upper bound
TYPED_TEST(Map_operations, upperBound) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['d'] = 44;
    my_map['e'] = 45;
    my_map['f'] = 46;
    my_map['g'] = 47;
    my_map['h'] = 48;
    my_map['i'] = 49;
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ((*(my_map.upper_bound('a'))).first, 'b');
        EXPECT_EQ((*(my_map.upper_bound('e'))).first, 'f');
        EXPECT_EQ((*(my_map.upper_bound('h'))).first, 'i');
        EXPECT_EQ(my_map.upper_bound('i'), my_map.end());
    }
    else
    {
        EXPECT_EQ(my_map.upper_bound('a'), my_map.end());
        EXPECT_EQ((*(my_map.upper_bound('e'))).first, 'd');
        EXPECT_EQ((*(my_map.upper_bound('h'))).first, 'g');
        EXPECT_EQ((*(my_map.upper_bound('i'))).first, 'h');
    }
}

// Equal range
TYPED_TEST(Map_operations, equalRange) {
    MAP         my_map;
    ITERATOR    it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['d'] = 44;
    my_map['e'] = 45;
    my_map['f'] = 46;
    my_map['g'] = 47;
    my_map['h'] = 48;
    my_map['i'] = 49;
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ((*(my_map.equal_range('a').first)).first, 'a');
        EXPECT_EQ((*(my_map.equal_range('a').second)).first, 'b');
        EXPECT_EQ((*(my_map.equal_range('e').first)).first, 'e');
        EXPECT_EQ((*(my_map.equal_range('e').second)).first, 'f');
        EXPECT_EQ(my_map.equal_range('p').first, my_map.end());
        EXPECT_EQ(my_map.equal_range('p').second, my_map.end());
    }
    else
    {
        EXPECT_EQ((*(my_map.equal_range('a').first)).first, 'a');
        EXPECT_EQ((*(my_map.equal_range('e').first)).first, 'e');
        EXPECT_EQ((*(my_map.equal_range('e').second)).first, 'd');
        EXPECT_EQ((*(my_map.equal_range('p').first)).first, 'i');
        EXPECT_EQ((*(my_map.equal_range('p').second)).first, 'i');
    }
}