/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:24:08 by marvin            #+#    #+#             */
/*   Updated: 2022/06/07 16:10:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_operations);

// Find
TYPED_TEST(Map_operations, findExisting) {
    MAP my_map;
    ITERATOR it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('b');
    EXPECT_EQ((*it).first, 'b');
    EXPECT_EQ((*it).second, 43);
}

TYPED_TEST(Map_operations, findNonExisting) {
    MAP my_map;
    ITERATOR it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('t');
    EXPECT_EQ(it, my_map.end());
}

TYPED_TEST(Map_operations, findConst) {
    MAP my_map;
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
    MAP my_map;
    ITERATOR it;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    EXPECT_EQ(my_map.count('a'), 1);
    EXPECT_EQ(my_map.count('z'), 0);
}
