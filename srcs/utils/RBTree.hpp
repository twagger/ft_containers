/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/17 13:38:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include "RBNode.hpp"

namespace   ft
{
    template< class T, class Compare >
    class RBTree
    {
        public:
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBTree(void) : root(NULL), comp(std::less<T>) {}
            RBTree(const RBTree &src);
            ~RBTree(void) {}
            
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef T   key_type;

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            RBTree  &operator=(const RBTree &rhs);

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Insert
            void    insert(RBNode<T> *node)
            {
                // Recursive insertion
                this->recursive_insert(this->_root, node);

                // Repair the tree to respect r&b rules
                this->repair(node);
                
                // Save the root
                this->_root = n;
                while (this->_root->parent != NULL)
                    this->_root = this->_root->parent;
            }

            void    recursive_insert(RBNode<T> *root, RBNode<T> *node)
            {
                int dir;

                if (root != NULL)
                {
                    if (this->comp(node->key, root->key))
                        dir = LEFT;
                    else
                        dir = RIGHT;
                    if (root->child[dir] != LEAF)
                    {
                        this->recursive_insert(root->child[dir], node);
                        return;
                    }
                    else
                        root->child[dir] = node;
                }
                node->parent = root;
            }

            // Repair
            void    repair(RBNode<T> *node)
            {
                int dir;

                if (node->parent == NULL)
                    // Node is root and red : OK
                    node->color = BLACK;
                else if (node->parent->color == BLACK)
                    // Parent is black, node is red : OK
                    return ;
                else if (node->uncle()->color == RED)
                {
                    // Parent is red, uncle is red, node is red : KO
                    // SWITCH COLORS
                    node->parent->color = BLACK;
                    node->uncle()->color = BLACK;
                    node->grandparent()->color = RED;
                    repair(node->grandparent());
                }
                else
                {
                    // Parent is red but uncle is black : KO
                    // ROTATE
                    if (node->parent->childdir() ^ node->childdir())
                    {
                        node->parent->rotate(node->parent->chiddir());
                        node = node->child[node->parent->childdir()];
                    }
                    node->grandparent()->rotate(1 - node->childdir());
                }
            }

            // Delete
            RBNode<T>   *remove(key_type const &key, \
                                RBNode<T> *node = this->_root)
            {
                RBNode<T>   *to_remove;

                to_remove = this->search(key);
                if (to_remove == NULL)
                    return (NULL);
                // Check the number of sons
                if (to_remove->left && to_remove->right)
                {
                    // We swith the value to delete with the closest element
                    // on its left or right tree (predecessor or successor)
                }
                
            }

            // Search
            RBNode<T>   *search(key_type const &key, \
                                RBNode<T> *node = this->_root) const
            {
                if (node == NULL)
                    return (NULL);
                if (node->key == key)
                    return (node);
                else
                    node = this->search(\
                            node->child[this->comp(node->key, key)], key);
                return (node);
            }

            // Iterators

        private:
            RBNode<T>   *_root;
            Compare     comp;            
    };
}

#endif
