#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_iterators);

// Increment iterator
TYPED_TEST(Map_iterators, incrementIterator) {
    MAP my_map;
    MAP::iterator it;

    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));

    it = my_map.begin();
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
        EXPECT_EQ(it->first, 'a');
    else
        EXPECT_EQ(it->first, 'd');
    ++it;
    ++it;
    if (t_comp == t_less)
        EXPECT_EQ(it->first, 'c');
    else
        EXPECT_EQ(it->first, 'b');
}

// End iterator
TYPED_TEST(Map_iterators, endIterator) {
    MAP my_map;
    MAP::iterator it;

    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));

    it = my_map.end();
    --it;
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
        EXPECT_EQ(it->first, 'd');
    else
        EXPECT_EQ(it->first, 'a');
}

// Reverse iterator
TYPED_TEST(Map_iterators, reverseIterator) {
    MAP my_map;
    MAP::reverse_iterator it;

    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));
    
    it = my_map.rbegin();
    const std::type_info &t_comp = typeid(MAP::key_compare);
    if (t_comp == t_less)
    {
        EXPECT_EQ(it->first, 'd');
        ++it;
        EXPECT_EQ(it->first, 'c');
    }
    else
    {
        EXPECT_EQ(it->first, 'a');
        ++it;
        EXPECT_EQ(it->first, 'b');
    }
}
