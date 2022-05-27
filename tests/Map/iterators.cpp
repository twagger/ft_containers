#include "gtest/gtest.h"
#include "Map.hpp"
#include <map>

/* ************************************************************************** */
/*  MAP CONSTRUCTOR TESTS                                                     */
/* ************************************************************************** */

// Increment iterator
TEST(MapTest_STDIterator, incrementIterator) {
    std::map<char, int> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'a');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'c');
}

TEST(MapTest_Iterator, incrementIterator) {
    ft::map<char, int> my_map;
    ft::map<char, int>::iterator it;

    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'a');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'c');
}

// Increment iterator with greater
TEST(MapTest_STDIterator, incrementIteratorWithGreater) {
    std::map<char, int, std::greater<char>> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'd');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'b');
}


TEST(MapTest_Iterator, incrementIteratorWithGreater) {
    ft::map<char, int, std::greater<char>> my_map;
    ft::map<char, int, std::greater<char>>::iterator it;

    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    it = my_map.begin();
    EXPECT_EQ(it->first, 'd');
    ++it;
    ++it;
    EXPECT_EQ(it->first, 'b');
}

// End iterator
TEST(MapTest_STDIterator, endIterator) {
    std::map<char, int> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    it = my_map.end();
    --it;
    EXPECT_EQ(it->first, 'd');
}

TEST(MapTest_Iterator, endIterator) {
    ft::map<char, int> my_map;
    ft::map<char, int>::iterator it;

    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    it = my_map.end();
    --it;
    EXPECT_EQ(it->first, 'd');
}

// End iterator with greater
TEST(MapTest_STDIterator, endIteratorWithGreater) {
    std::map<char, int, std::greater<char>> my_map;
    std::map<char, int>::iterator it;

    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    it = my_map.end();
    --it;
    EXPECT_EQ(it->first, 'a');
}


TEST(MapTest_Iterator, endIteratorWithGreater) {
    ft::map<char, int, std::greater<char>> my_map;
    ft::map<char, int, std::greater<char>>::iterator it;

    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    it = my_map.end();
    --it;
    EXPECT_EQ(it->first, 'a');
}

// Reverse iterator
TEST(MapTest_STDIterator, reverseIterator) {
    std::map<char, int> my_map;
    std::map<char, int>::reverse_iterator it;

    my_map.insert(std::pair<char, int>('a', 100));
    my_map.insert(std::pair<char, int>('b', 500));
    my_map.insert(std::pair<char, int>('c', 1800));
    my_map.insert(std::pair<char, int>('d', 20));

    it = my_map.rbegin();
    ++it;
    EXPECT_EQ(it->first, 'c');
}

TEST(MapTest_Iterator, reverseIterator) {
    ft::map<char, int> my_map;
    ft::map<char, int>::reverse_iterator it;

    my_map.insert(ft::pair<char, int>('a', 100));
    my_map.insert(ft::pair<char, int>('b', 500));
    my_map.insert(ft::pair<char, int>('c', 1800));
    my_map.insert(ft::pair<char, int>('d', 20));

    it = my_map.rbegin();
    ++it;
    EXPECT_EQ(it->first, 'c');
}