#include "gtest/gtest.h"
#include "Map.hpp"
#include <map>

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

TEST(MapTest_Iterator, incrementIterator) {
    std::map<char, int> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a',100));
    my_map.insert(std::pair<char, int>('b',500));
    my_map.insert(std::pair<char, int>('c',1800));
    my_map.insert(std::pair<char, int>('d',20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'a');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'c');
}

TEST(MapTest_Iterator, incrementIteratorWithGreater) {
    std::map<char, int, std::greater<char>> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a',100));
    my_map.insert(std::pair<char, int>('b',500));
    my_map.insert(std::pair<char, int>('c',1800));
    my_map.insert(std::pair<char, int>('d',20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'd');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'b');
}
