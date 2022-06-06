/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:45:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/06 12:55:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_modifiers);

// Erase
TYPED_TEST(Map_modifiers, eraseByPosition) {
    MAP my_map;
    ITERATOR it;
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.find('b');
    my_map.erase(it);
    EXPECT_EQ(my_map['a'], 44);
    EXPECT_EQ(my_map['c'], 42);
}
