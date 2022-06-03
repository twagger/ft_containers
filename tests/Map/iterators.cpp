#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

#define MAP typename TestFixture::Types::first_type
#define PAIR typename TestFixture::Types::second_type

template<typename T>
struct Map_iterators : public testing::Test
{ using Types = T; };

using ContTypes = testing::Types
<
    std::pair<std::map<char, int>, std::pair<char, int>>,
    std::pair<ft::map<char, int>, ft::pair<char, int>>
    //std::pair<std::map<char, int, std::greater<char>>, std::pair<char, int>>,
    //std::pair<ft::map<char, int, std::greater<char>>, ft::pair<char, int>>
>;

TYPED_TEST_CASE(Map_iterators, ContTypes);
TYPED_TEST_SUITE_P(Map_iterators);

/* ************************************************************************** */

// Increment iterator
TYPED_TEST(Map_iterators, incrementIterator) {
    MAP my_map;
    MAP::iterator it;

    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'a');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'c');
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
    EXPECT_EQ(it->first, 'd');
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
    EXPECT_EQ(it->first, 'd');
    ++it;
    EXPECT_EQ(it->first, 'c');
}
