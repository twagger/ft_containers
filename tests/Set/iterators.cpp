#include "gtest/gtest.h"
#include <set>
#include "set.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Set_iterators);

// Increment iterator
TYPED_TEST(Set_iterators, incrementIterator) {
    SET my_set;
    SET::iterator it;

    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);

    it = my_set.begin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
        EXPECT_EQ(*it, 42);
    else
        EXPECT_EQ(*it, 45);
    ++it;
    ++it;
    if (t_comp == t_less)
        EXPECT_EQ(*it, 44);
    else
        EXPECT_EQ(*it, 43);
}

// End iterator
TYPED_TEST(Set_iterators, endIterator) {
    SET my_set;
    SET::iterator it;

    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);

    it = my_set.end();
    --it;
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
        EXPECT_EQ(*it, 45);
    else
        EXPECT_EQ(*it, 42);
}

// Reverse iterator
TYPED_TEST(Set_iterators, reverseIterator) {
    SET my_set;
    SET::reverse_iterator it;

    my_set.insert(42);
    my_set.insert(43);
    my_set.insert(44);
    my_set.insert(45);
    
    it = my_set.rbegin();
    const std::type_info &t_comp = typeid(SET::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(*it, 45);
        ++it;
        EXPECT_EQ(*it, 44);
    }
    else
    {
        EXPECT_EQ(*it, 42);
        ++it;
        EXPECT_EQ(*it, 43);
    }
}
