/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 07:36:10 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:28:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_operators);

// Array index operator
TYPED_TEST(Map_operators, arrayIndexOperator) {
    MAP my_map;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = my_map['a'];
    EXPECT_EQ(my_map['c'], 44);
    EXPECT_EQ(my_map['d'], 42);
}

TYPED_TEST(Map_operators, arrayIndexNonExistingOperator) {
    MAP my_map;
    ITERATOR it;
    
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    EXPECT_EQ(my_map['t'], 0);
}

// Assignment operator
TYPED_TEST(Map_operators, assignmentOperator) {
    MAP my_map;
    MAP my_map2;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = my_map['a'];
    my_map2['p'] = 38;
    my_map2['g'] = 44;
    my_map2 = my_map;
    EXPECT_EQ(my_map2.size(), 4);
}
