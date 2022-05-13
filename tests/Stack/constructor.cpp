#include "gtest/gtest.h"
#include "Stack.hpp"

/* ************************************************************************** */
/*  STACK CONSTRUCTOR TESTS                                                   */
/* ************************************************************************** */

TEST(StackTest_Constructor, defaultConstructor) {
    ft::stack<int> MyStack;
    EXPECT_EQ(MyStack.size(), 0)
        << "Default vector should have a 0 size";
}
