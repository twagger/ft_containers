/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/17 10:13:04 by marvin           ###   ########.fr       */
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
                while (this->_root->parent() != NULL)
                    this->_root = this->_root->parent();
            }

            void    recursive_insert(RBNode<T> *root, RBNode<T> *node)
            {
                if (root != NULL && this->comp(node->key, root->key))
                {
                    if (root->left != LEAF)
                    {
                        this->recursive_insert(root->left, node);
                        return;
                    }
                    else
                        root->left = node;
                }
                else if (root != NULL)
                {
                    if (root->right != LEAF)
                    {
                        this->recursive_insert(root->right, node);
                        return;
                    }
                    else
                        root->right = node;
                }
                node->parent = root;
            }

            // Repair
            void    repair(RBNode<T> *node)
            {
                if (node->parent() == NULL)
                    // Node is root and red : OK
                    node->color = BLACK;
                else if (node->parent()->color == BLACK)
                    // Parent is black, node is red : OK
                    return ;
                else if (node->uncle()->color == RED)
                {
                    // Parent is red, uncle is red, node is red : KO
                    // SWITCH COLORS
                    node->parent()->color = BLACK;
                    node->uncle()->color = BLACK;
                    node->grandparent()->color = RED;
                    repair(node->grandparent());
                }
                else
                {
                    // Parent is red but uncle is black : KO
                    // ROTATE
                    if (node == node->grandparent()->left->right)
                    {
                        node->parent()->rot_left();
                        node = node->left;
                    }
                    else if (node == node->grandparent()->right->left)
                    {
                        node->parent()->rot_right();
                        node = node->right;
                    }
                    if (node == node->parent()->left)
                        node->grandparent()->rot_right();
                    else
                        node->grandparent()->rot_left;
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
                    // on its left or right tree with at most one non null child
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
                {
                    if (this->comp(node->key, key))
                        node = this->search(node->right, key);
                    else
                        node = this->search(node->left, key);
                }
                return (node);
            }

            // Iterators

        private:
            RBNode<T>   *_root;
            Compare     comp;            
    };
}

#endif
