/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/17 15:15:20 by marvin           ###   ########.fr       */
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
                    node->color = BLACK;
                else if (node->parent->color == BLACK)
                    return ;
                else if (node->uncle()->color == RED)
                {
                    // Parent is red, uncle is red, node is red : SWITCH COLORS
                    node->parent->color = BLACK;
                    node->uncle()->color = BLACK;
                    node->grandparent()->color = RED;
                    repair(node->grandparent());
                }
                else
                {
                    // Parent is red but uncle is black : ROTATE
                    if (node->parent->childdir() ^ node->childdir())
                    {
                        node->parent->rotate(node->parent->chiddir());
                        node = node->child[node->parent->childdir()];
                    }
                    node->grandparent()->rotate(1 - node->childdir());
                }
            }

            // Remove
            RBNode<T>   *remove(key_type const &key, \
                                RBNode<T> *node = this->_root)
            {
                RBNode<T>   *to_remove;
                RBNode<T>   *replacement;

                to_remove = this->search(key);
                if (to_remove == NULL)
                    return (NULL);
                // Check the number of childs
                if (to_remove->child[LEFT] && to_remove->child[RIGHT])
                {
                    // 2 childs : switch it with predecessor or successor
                    replacement = to_remove->replacement();
                    to_remove->swapkeys(replacement);
                    to_remove = replacement;
                }
                if (to_remove->color == RED || 
                    (to_remove->child[LEFT] || to_remove->child[RIGHT]))
                    return (this->remove_simple_case(to_remove));
                return (this->remove_complex_case(to_remove));
            }

            RBNode  *remove_simple_case(RBNode<T> *node)
            {
                // All cases but the one where the node is black with no child
                if (node->color == RED)
                {
                    // Node is RED : remove it
                    node->parent->child[node->childdir()] = NULL;
                    return (node);
                }
                else // Node is BLACK
                {
                    // One child, it is necessary RED. It replaces the node
                    if (node->child[LEFT])
                    {
                        node->swapkeys(node->child[LEFT]);
                        node->color = RED;
                        return (node->child[LEFT]);
                    }
                    else if (node->child[RIGHT])
                    {
                        node->swapkeys(node->child[RIGHT]);
                        node->color = RED;
                        return (node->child[RIGHT]);
                    }
                    return (node);
                }
            }

            RBNode  *remove_complex_case(RBNode<T> *node)
            {
                // Specific case : node is BLACK with no child
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

            // Successor

            // Iterators

        private:
            RBNode<T>   *_root;
            Compare     comp;            
    };
}

#endif
