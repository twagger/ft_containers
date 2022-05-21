#include "gtest/gtest.h"
#include "RBTree.hpp"

/* ************************************************************************** */
/*  RBTREE CONSTRUCTOR TESTS                                                  */
/* ************************************************************************** */

TEST(RBTree, creation) {
    ft::RBTree<int>  my_tree;
    EXPECT_TRUE(my_tree.get_root() == NULL);
}

TEST(RBTree, insertSingle) {
    ft::RBTree<int>  my_tree;
    my_tree.insert(28);
    EXPECT_TRUE(my_tree.get_root()->key == 28);
}

TEST(RBTree, rootIsBlack) {
    ft::RBTree<int>  my_tree;
    my_tree.insert(28);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
}

TEST(RBTree, treeIsAutoBalanced) {
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

TEST(RBTree, treeIsAutoBalanced2) {
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

TEST(RBTree, searchExistingNode) {
    ft::RBTree<int>  my_tree;
    ft::RBNode<int>  *my_node;
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
    my_node = my_tree.search(my_tree.get_root(), 13);
    EXPECT_EQ(my_node->parent->key, 15);
}
 
TEST(RBTree, searchNonExistingNode) {
    ft::RBTree<int>  my_tree;
    ft::RBNode<int>  *my_node;
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
    my_node = my_tree.search(my_tree.get_root(), 42);
    EXPECT_TRUE(my_node == NULL);
}

TEST(RBTree, searchRoot) {
    ft::RBTree<int>  my_tree;
    ft::RBNode<int>  *my_node;
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
    my_node = my_tree.search(my_tree.get_root(), 17);
    EXPECT_EQ(my_node->key, 17);
}

TEST(RBTree, removeRedLeafDontModifyTheRestOfTheTree) {
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
    my_tree.remove(13);
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
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->key == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->key == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->key == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 13) == NULL);
} 

TEST(RBTree, removeNonExistingKey) {
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
    my_tree.remove(42);
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

TEST(RBTree, removeBlackLeafWithNoChild_case4) {
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
    my_tree.remove(27);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->key == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->key == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->key == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
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

TEST(RBTree, removeBlackLeafWithNoChild_case1) {
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
    my_tree.remove(27);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->key == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->key == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->key == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
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

TEST(RBTree, predecessor) {
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
    EXPECT_TRUE(\
    my_tree.predecessor(my_tree.search(my_tree.get_root(), 15))->key == 13);
}

TEST(RBTree, predecessorWithGreaterComp) {
    ft::RBTree<int, std::greater<int>>  my_tree;
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
    EXPECT_TRUE(\
    my_tree.predecessor(my_tree.search(my_tree.get_root(), 15))->key == 17);
}

TEST(RBTree, successor) {
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
    EXPECT_TRUE(\
    my_tree.successor(my_tree.search(my_tree.get_root(), 17))->key == 22);
}

TEST(RBTree, successorWithGreaterComp) {
    ft::RBTree<int, std::greater<int>>  my_tree;
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
    EXPECT_TRUE(\
    my_tree.successor(my_tree.search(my_tree.get_root(), 17))->key == 15);
}
