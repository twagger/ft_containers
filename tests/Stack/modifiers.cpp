/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:37:44 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 07:58:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <stack>
#include "Stack.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Stack_modifiers);

// Push
TYPED_TEST(Stack_modifiers, push) {
    STACK my_stack;
    my_stack.push(42);
    EXPECT_EQ(my_stack.size(), 1);
}

TYPED_TEST(Stack_modifiers, pushALot) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    EXPECT_EQ(my_stack.size(), 13);
}

// Pop
TYPED_TEST(Stack_modifiers, pop) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.pop();
    EXPECT_EQ(my_stack.size(), 0);
}

TYPED_TEST(Stack_modifiers, popALot) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    EXPECT_EQ(my_stack.size(), 5);
}
