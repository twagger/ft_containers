#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

#define MAP typename TestFixture::Types::first_type
#define PAIR typename TestFixture::Types::second_type

template<typename T>
struct Map_constructor : public testing::Test
{ using Types = T; };

using ContTypes = testing::Types
<
    std::pair<std::map<char, int>, std::pair<char, int>>,
    std::pair<ft::map<char, int>, ft::pair<char, int>>
>;

TYPED_TEST_CASE(Map_constructor, ContTypes);
TYPED_TEST_SUITE_P(Map_constructor);

/* ************************************************************************** */

// Default constructor
TYPED_TEST(Map_constructor, defaultConstructor) {
    MAP my_map;
    EXPECT_EQ(my_map.size(), 0);
}

// Ranged constructor
TYPED_TEST(Map_constructor, rangeConstructor) {
    MAP my_map;
    my_map.insert(PAIR('a', 100));
    my_map.insert(PAIR('b', 500));
    my_map.insert(PAIR('c', 1800));
    my_map.insert(PAIR('d', 20));

    MAP my_map_2(my_map.begin(), my_map.end());
    EXPECT_EQ(my_map.size(), my_map_2.size());
}
