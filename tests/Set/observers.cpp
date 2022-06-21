/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:57:02 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 09:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_observers);

// Key compare
TYPED_TEST(Set_observers, keyCompare) {
    SET my_set;
    SET::key_compare my_comp = my_set.key_comp();
    ITERATOR it;
    ITERATOR it2;
     
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    it = my_set.begin();
    it2 = my_set.begin();
    ++it2;
    EXPECT_EQ(my_comp(*it, *it2), true);
}

// Value Compare
TYPED_TEST(Set_observers, valueCompare) {
    SET                 my_set;
    ITERATOR            it;
    SET::value_compare  comp = my_set.value_comp();
    int                 i = 41;
    SET::value_type     highest;
    
    my_set.insert(41);
    my_set.insert(42);
    my_set.insert(43);
    it = my_set.begin();
    highest = *(my_set.rbegin());
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        while (comp(*it, highest)) // I can now compare value_types
        {
            EXPECT_EQ(*it, i++);
            ++it;
        }
    }
    else
    {
        i = 43;
        while (comp(*it, highest))
        {
            EXPECT_EQ(*it, i--);
            ++it;
        }
    }
}
