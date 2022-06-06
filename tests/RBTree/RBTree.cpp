#include "gtest/gtest.h"
#include "RBTree.hpp"

/* ************************************************************************** */
/*  RBTREE CONSTRUCTOR TESTS                                                  */
/* ************************************************************************** */

TEST(RBTree, creation) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    EXPECT_TRUE(my_tree.get_root() == NULL);
}

TEST(RBTree, insertSingle) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(28, 'a'));
    EXPECT_TRUE(my_tree.get_root()->value.first == 28);
}

TEST(RBTree, rootIsBlack) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(28, 'a'));
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
}

TEST(RBTree, treeIsAutoBalanced) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    EXPECT_TRUE(my_tree.get_root()->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[RIGHT]->color == RED);
}

TEST(RBTree, treeIsAutoBalanced2) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.get_root()->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->value.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->value.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, searchExistingNode) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    ft::RBNode<ft::pair<int, char>, std::less<int>>  *my_node;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_node = my_tree.search(13);
    EXPECT_EQ(my_node->parent->value.first, 15);
}
 
TEST(RBTree, searchNonExistingNode) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    ft::RBNode<ft::pair<int, char>, std::less<int>>  *my_node;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_node = my_tree.search(42);
    EXPECT_TRUE(my_node == NULL);
}

TEST(RBTree, searchRoot) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    ft::RBNode<ft::pair<int, char>, std::less<int>>  *my_node;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_node = my_tree.search(17);
    EXPECT_EQ(my_node->value.first, 17);
}

TEST(RBTree, removeRedLeafDontModifyTheRestOfTheTree) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_tree.erase(13);
    EXPECT_TRUE(my_tree.get_root()->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->value.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.search(13) == NULL);
} 

TEST(RBTree, removeNonExistingKey) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_tree.erase(42);
    EXPECT_TRUE(my_tree.get_root()->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->value.first == 27);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->value.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, removeBlackLeafWithNoChild_case4) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_tree.erase(27);
    EXPECT_TRUE(my_tree.search(27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->value.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, removeBlackLeafWithNoChild_case1) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_tree.erase(27);
    EXPECT_TRUE(my_tree.search(27) == NULL);
    EXPECT_TRUE(my_tree.get_root()->value.first == 17);
    EXPECT_TRUE(my_tree.get_root()->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->value.first == 22);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->value.first == 15);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->value.first == 13);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[RIGHT]->child[LEFT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->value.first == 6);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->color == BLACK);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->value.first == 8);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[RIGHT]->color == RED);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->value.first == 1);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->child[LEFT]->child[LEFT]->color == RED);
}

TEST(RBTree, predecessor) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.search(15)->predecessor()->value.first == 13);
}

TEST(RBTree, predecessorWithGreaterComp) {
    ft::RBTree<ft::pair<int, char>, std::greater<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.search(15)->predecessor()->value.first == 17);
}

TEST(RBTree, successor) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.search(17)->successor()->value.first == 22);
}

TEST(RBTree, successorWithGreaterComp) {
    ft::RBTree<ft::pair<int, char>, std::greater<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    EXPECT_TRUE(my_tree.search(17)->successor()->value.first == 15);
}

TEST(RBTree, swapNodes) {
    ft::RBTree<ft::pair<int, char>, std::less<int>>  my_tree;
    my_tree.insert(ft::pair<int, char>(17, 'a'));
    my_tree.insert(ft::pair<int, char>(25, 'f'));
    my_tree.insert(ft::pair<int, char>(27, 'c'));
    my_tree.insert(ft::pair<int, char>(11, 'g'));
    my_tree.insert(ft::pair<int, char>(1, 't'));
    my_tree.insert(ft::pair<int, char>(6, 'u'));
    my_tree.insert(ft::pair<int, char>(15, 'r'));
    my_tree.insert(ft::pair<int, char>(8, 'y'));
    my_tree.insert(ft::pair<int, char>(22, 'l'));
    my_tree.insert(ft::pair<int, char>(13, 'i'));
    my_tree.get_root()->child[LEFT]->swap(my_tree.get_root()->child[RIGHT]);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.first == 25);
    EXPECT_TRUE(my_tree.get_root()->child[LEFT]->value.second == 'f');
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.first == 11);
    EXPECT_TRUE(my_tree.get_root()->child[RIGHT]->value.second == 'g');
}
