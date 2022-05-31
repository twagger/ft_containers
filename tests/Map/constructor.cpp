#include "gtest/gtest.h"
#include "Map.hpp"

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

TEST(MapTest_Constructor, defaultConstructor) {
    EXPECT_EQ(1, 1);
}

TEST(MapTest_Constructor, STDrangeConstructor) {
    std::map<char, int> my_map;
    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    std::map<char, int> my_map_2(my_map.begin(), my_map.end());
    EXPECT_EQ(my_map.size(), my_map_2.size());
}

TEST(MapTest_Constructor, FTrangeConstructor) {
    ft::map<char, int> my_map;
    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    ft::map<char, int> my_map_2(my_map.begin(), my_map.end());
    EXPECT_EQ(my_map.size(), my_map_2.size());
}
