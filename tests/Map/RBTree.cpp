#include "gtest/gtest.h"
#include "RBTree.hpp"

/* ************************************************************************** */
/*  RBTREE CONSTRUCTOR TESTS                                                  */
/* ************************************************************************** */

TEST(RBTree, creation) {
    ft::RBTree<int, char>  my_tree;
    EXPECT_TRUE(my_tree.get_root() == NULL);
}

TEST(RBTree, insertSingle) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(28, 'a'));
    EXPECT_TRUE(my_tree.get_root()->comb.first == 28);
}

TEST(RBTree, rootIsBlack) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(28, 'a'));
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
}

TEST(RBTree, treeIsAutoBalanced) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    EXPECT_TRUE(my_tree.get_root()->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->color == RED);
}

TEST(RBTree, treeIsAutoBalanced2) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.get_root()->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->comb.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->comb.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, searchExistingNode) {
    ft::RBNode<int, char, std::less<int>>  *my_node;
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_node = my_tree.search(my_tree.get_root(), 13);
    EXPECT_EQ(my_node->parent->comb.first, 15);
}
 
TEST(RBTree, searchNonExistingNode) {
    ft::RBNode<int, char, std::less<int>>  *my_node;
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_node = my_tree.search(my_tree.get_root(), 42);
    EXPECT_TRUE(my_node == NULL);
}

TEST(RBTree, searchRoot) {
    ft::RBNode<int, char, std::less<int>>  *my_node;
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_node = my_tree.search(my_tree.get_root(), 17);
    EXPECT_EQ(my_node->comb.first, 17);
}

TEST(RBTree, removeRedLeafDontModifyTheRestOfTheTree) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_tree.remove(13);
    EXPECT_TRUE(my_tree.get_root()->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->comb.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 13) == NULL);
} 

TEST(RBTree, removeNonExistingKey) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_tree.remove(42);
    EXPECT_TRUE(my_tree.get_root()->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->comb.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->comb.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, removeBlackLeafWithNoChild_case4) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_tree.remove(27);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->comb.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, removeBlackLeafWithNoChild_case1) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    my_tree.remove(27);
    EXPECT_TRUE(my_tree.search(my_tree.get_root(), 27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->comb.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->comb.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->comb.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->comb.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->comb.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->comb.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->comb.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->comb.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->comb.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, predecessor) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    EXPECT_TRUE(\
    my_tree.search(my_tree.get_root(), 15)->predecessor()->comb.first == 13);
}

TEST(RBTree, predecessorWithGreaterComp) {
    ft::RBTree<int, char, std::greater<int>>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    EXPECT_TRUE(\
    my_tree.search(my_tree.get_root(), 15)->predecessor()->comb.first == 17);
}

TEST(RBTree, successor) {
    ft::RBTree<int, char>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    EXPECT_TRUE(\
    my_tree.search(my_tree.get_root(), 17)->successor()->comb.first == 22);
}

TEST(RBTree, successorWithGreaterComp) {
    ft::RBTree<int, char, std::greater<int>>  my_tree;
    my_tree.insert(ft::make_pair<int, char>(17, 'a'));
    my_tree.insert(ft::make_pair<int, char>(25, 'f'));
    my_tree.insert(ft::make_pair<int, char>(27, 'c'));
    my_tree.insert(ft::make_pair<int, char>(11, 'g'));
    my_tree.insert(ft::make_pair<int, char>(1, 't'));
    my_tree.insert(ft::make_pair<int, char>(6, 'u'));
    my_tree.insert(ft::make_pair<int, char>(15, 'r'));
    my_tree.insert(ft::make_pair<int, char>(8, 'y'));
    my_tree.insert(ft::make_pair<int, char>(22, 'l'));
    my_tree.insert(ft::make_pair<int, char>(13, 'i'));
    EXPECT_TRUE(\
    my_tree.search(my_tree.get_root(), 17)->successor()->comb.first == 15);
}
