/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:28:23 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 07:28:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <stack>
#include "stack.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Stack_constructors);

// Default constructor
TYPED_TEST(Stack_constructors, defaultConstructor) {
    STACK my_stack;
    EXPECT_EQ(my_stack.size(), 0);
}
