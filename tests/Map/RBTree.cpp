#include "gtest/gtest.h"
#include "RBTree.hpp"

/* ************************************************************************** */
/*  RBTREE CONSTRUCTOR TESTS                                                  */
/* ************************************************************************** */

TEST(MapTest_RBTree, creation) {
    ft::RBTree<int>  my_tree;
    EXPECT_TRUE(my_tree.get_root() == NULL);
}

TEST(MapTest_RBTree, insertSingle) {
    ft::RBTree<int>  my_tree;
    my_tree.insert(28);
    EXPECT_TRUE(my_tree.get_root()->key == 28);
}

TEST(MapTest_RBTree, rootIsBlack) {
    ft::RBTree<int>  my_tree;
    my_tree.insert(28);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
}

TEST(MapTest_RBTree, treeIsAutoBalanced) {
    ft::RBTree<int>  my_tree;
    my_tree.insert(17);
    my_tree.insert(25);
    my_tree.insert(27);
    my_tree.insert(11);
    my_tree.insert(1);
    my_tree.insert(6);
    my_tree.insert(15);
    my_tree.insert(8);
    my_tree.insert(22);
    my_tree.insert(13);
    EXPECT_TRUE(my_tree.get_root()->key == 13);
}
