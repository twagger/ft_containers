/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_operators.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:39:44 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 07:50:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gtest/gtest.h"
#include <stack>
#include "Stack.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Stack_relational_operators);

// ==
TYPED_TEST(Stack_relational_operators, equalEmpty) {
    STACK my_stack;
    STACK my_stack2;
    EXPECT_EQ(my_stack == my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, equalNonEmpty) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack.push(43);
    my_stack.push(44);
    my_stack2.push(42);
    my_stack2.push(43);
    my_stack2.push(44);
    EXPECT_EQ(my_stack == my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, equalFalseIfNotEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack.push(43);
    my_stack.push(44);
    my_stack2.push(42);
    my_stack2.push(45);
    my_stack2.push(44);
    EXPECT_EQ(my_stack == my_stack2, false);
}

// !=
TYPED_TEST(Stack_relational_operators, nonEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack2.push(43);
    EXPECT_EQ(my_stack != my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, nonEqualFalseIfEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack.push(43);
    my_stack.push(44);
    my_stack2.push(42);
    my_stack2.push(43);
    my_stack2.push(44);
    EXPECT_EQ(my_stack != my_stack2, false);
}

// <
TYPED_TEST(Stack_relational_operators, less) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack2.push(43);
    EXPECT_EQ(my_stack < my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, lessFalseIfEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(43);
    EXPECT_EQ(my_stack < my_stack2, false);
}

TYPED_TEST(Stack_relational_operators, lessFalseIfGreater) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(44);
    my_stack2.push(43);
    EXPECT_EQ(my_stack < my_stack2, false);
}

// >
TYPED_TEST(Stack_relational_operators, greater) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(42);
    EXPECT_EQ(my_stack > my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, greaterFalseIfEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(43);
    EXPECT_EQ(my_stack > my_stack2, false);
}

TYPED_TEST(Stack_relational_operators, greaterFalseIfLess) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(44);
    EXPECT_EQ(my_stack > my_stack2, false);
}

// <=
TYPED_TEST(Stack_relational_operators, lessOrEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(42);
    my_stack2.push(43);
    EXPECT_EQ(my_stack <= my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, lessOrEqualTrueIfEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(43);
    EXPECT_EQ(my_stack <= my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, lessOrEqualFalseIfGreater) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(44);
    my_stack2.push(43);
    EXPECT_EQ(my_stack <= my_stack2, false);
}

// >=
TYPED_TEST(Stack_relational_operators, greaterOrEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(42);
    EXPECT_EQ(my_stack >= my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, greaterOrEqualTrueIfEqual) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(43);
    EXPECT_EQ(my_stack >= my_stack2, true);
}

TYPED_TEST(Stack_relational_operators, greaterOrEqualFalseIfLess) {
    STACK my_stack;
    STACK my_stack2;
    my_stack.push(43);
    my_stack2.push(44);
    EXPECT_EQ(my_stack >= my_stack2, false);
}
