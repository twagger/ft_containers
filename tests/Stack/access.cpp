/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:51:22 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 07:55:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <stack>
#include "Stack.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Stack_access);

// Top
//TYPED_TEST(Stack_access, topOnEmptyStack) {
//    STACK my_stack;
//    EXPECT_DEATH_IF_SUPPORTED(my_stack.top());
//}

TYPED_TEST(Stack_access, topOnNonEmptyStack) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(43);
    my_stack.push(44);
    my_stack.push(45);
    EXPECT_EQ(my_stack.top(), 45);
}

TYPED_TEST(Stack_access, topAfterPop) {
    STACK my_stack;
    my_stack.push(42);
    my_stack.push(43);
    my_stack.push(44);
    my_stack.push(45);
    my_stack.pop();
    EXPECT_EQ(my_stack.top(), 44);
}
