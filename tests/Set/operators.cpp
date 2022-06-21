/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:30:35 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 08:32:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_operators);

// Assignment operator
TYPED_TEST(Set_operators, assignmentOperator) {
    SET my_set;
    SET my_set2;
    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set2.insert(11);
    my_set2.insert(12);
    my_set2 = my_set;
    EXPECT_EQ(my_set2.size(), 3);
}