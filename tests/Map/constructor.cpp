#include "gtest/gtest.h"
#include <map>
#include "Map.hpp"
#include "parameters.hpp"

TYPED_TEST_SUITE_P(Map_constructor);

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
