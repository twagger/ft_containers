/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:57:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:28:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <map>
#include "map.hpp"
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

// Value Compare
TYPED_TEST(Map_observers, valueCompare) {
    MAP                 my_map;
    ITERATOR            it;
    PAIR                highest;
    MAP::value_compare  comp = my_map.value_comp();
    std::string         check = "abc";
    std::string         rcheck = "cba";
    int                 i = 0;
    
    my_map['a'] = 41;
    my_map['b'] = 42;
    my_map['c'] = 43;
    it = my_map.begin();
    highest = *(my_map.rbegin());
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        while (comp(*it, highest)) // I can now compare value_types
        {
            EXPECT_EQ((*it).first, check[i++]);
            ++it;
        }
    }
    else
    {
        while (comp(*it, highest))
        {
            EXPECT_EQ((*it).first, rcheck[i++]);
            ++it;
        }
    }
}
