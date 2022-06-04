/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 07:36:10 by marvin            #+#    #+#             */
/*   Updated: 2022/06/04 11:01:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_operators);

// Array index operator
TYPED_TEST(Map_operators, ArrayIndexOperator) {
    MAP my_map;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    my_map['d'] = my_map['a'];
    EXPECT_EQ(my_map['c'], 44);
    EXPECT_EQ(my_map['d'], 42);
}
