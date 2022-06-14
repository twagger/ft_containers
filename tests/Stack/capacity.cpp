/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:32:16 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 07:37:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <stack>
#include "Stack.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Stack_capacity);

// Empty
TYPED_TEST(Stack_capacity, empty) {
    STACK my_stack;
    EXPECT_EQ(my_stack.empty(), true);
}

TYPED_TEST(Stack_capacity, notEmpty) {
    STACK my_stack;
    my_stack.push(42);
    EXPECT_EQ(my_stack.empty(), false);
}


// Size
TYPED_TEST(Stack_capacity, sizeZero) {
    STACK my_stack;
    EXPECT_EQ(my_stack.size(), 0);
}

TYPED_TEST(Stack_capacity, sizeNonZero) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    EXPECT_EQ(my_stack.size(), 7);
}

TYPED_TEST(Stack_capacity, sizeIsModifiedByPop) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.push(42);
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    EXPECT_EQ(my_stack.size(), 3);
}
