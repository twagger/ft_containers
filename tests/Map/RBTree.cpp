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
    EXPECT_TRUE(my_tree.get_root()->key == 25);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->key == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->key == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->key == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->key == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->key == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->key == 17);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->key == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->key == 22);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->color == RED);
}

TEST(MapTest_RBTree, treeIsAutoBalanced2) {
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
    EXPECT_TRUE(my_tree.get_root()->key == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->key == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->key == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->key == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->key == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->key == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->key == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->key == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->key == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->key == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}
