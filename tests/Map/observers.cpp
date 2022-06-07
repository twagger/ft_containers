/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:57:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/07 15:18:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_observers);

// Key compare
TYPED_TEST(Map_observers, keyCompare) {
    MAP my_map;
    MAP::key_compare my_comp = my_map.key_comp();
    ITERATOR it;
    ITERATOR it2;
     
    my_map['a'] = 42;
    my_map['b'] = 43;
    my_map['c'] = 44;
    it = my_map.begin();
    it2 = my_map.begin();
    ++it2;
    EXPECT_EQ(my_comp((*it).first, (*it2).first), true);
}
