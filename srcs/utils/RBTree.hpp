/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/20 14:00:43g by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include "RBNode.hpp"
# include <exception>

namespace   ft
{
    template< class T, class Compare = std::less<T> >
    class RBTree
    {
        public:
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBTree(void) : _root(NULL), _comp(std::less<T>()) {}
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
            // Access
            RBNode<T>   *get_root(void) const { return (this->_root); }
            
            // Insert
            void    insert(key_type key)
            {
                RBNode<T>   *node = new RBNode<T>(key);

                // Recursive insertion
                this->recursive_insert(this->_root, node);

                // Repair the tree to respect r&b rules
                this->repair(node);
                
                // Save the root
                this->_root = node;
                while (this->_root->parent != NULL)
                    this->_root = this->_root->parent;
            }

            void    recursive_insert(RBNode<T> *root, RBNode<T> *node)
            {
                int dir;

                if (root != NULL)
                {
                    if (this->_comp(node->key, root->key))
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
                int         dir;
                RBNode<T>   *p;
                RBNode<T>   *g;
                
                if (node->parent == NULL)
                    node->color = BLACK;
                else if (node->parent->color == BLACK)
                    return ;
                else if (node->uncle() && node->uncle()->color == RED)
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
                        node->parent->rotate(node->parent->childdir());
                        node = node->child[node->parent->childdir()];
                    }
                    p = node->parent;
                    g = node->grandparent();
                    g->rotate(1 - node->childdir());
                    p->color = BLACK;
                    g->color = RED;
                }
            }

            // Remove
            RBNode<T>   *remove(key_type const &key)
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

            RBNode<T>  *remove_simple_case(RBNode<T> *node)
            {
                // All cases but the one where the node is black with no child
                // With the simple cases we don't need to rebalance the tree
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

            RBNode<T>  *remove_complex_case(RBNode<T> *node)
            {
                // Specific case : node is BLACK with no child
                RBNode<T>   *p = node->parent;
                RBNode<T>   *b; // brother
                RBNode<T>   *c; // close nephew
                RBNode<T>   *d; // distant nephew
                int         dir;

                // 1. Replace node by NULL in its parent : 
                //  the tree is now unbalanced !
                dir = node->childdir();
                p->child[dir] = NULL;
                 
                // 2. Rebalancing loop
                while (p != NULL)
                {
                    try { dir = node->childdir(); }
                    catch (const std::runtime_error &e) {} // first loop only
                    b = p->child[1 - dir];
                    d = b->child[1 - dir];
                    c = b->child[dir];
                    if (b->color == RED)
                        this->remove_case_3(&p, &b, &c, &d, dir);
                    else if (d != NULL && d->color == RED)
                        this->remove_case_6(&p, &b, &c, &d, dir);
                    else if (c != NULL && c->color == RED)
                        this->remove_case_5(&p, &b, &c, &d, dir);
                    else if (p->color == RED)
                        return (NULL);
                    else // remove_case_1
                    {
                        b->color = RED;
                        node = p;
                        p = node->parent;
                        continue;
                    }
                    return (NULL);
                }
                return (NULL); // remove_case_2
            }

            void    remove_case_3(RBNode<T> **p, RBNode<T> **b, \
                                  RBNode<T> **c, RBNode<T> **d, int dir)
            {
                // rotate
                (*p)->rotate(dir);
                // r&b rules repair
                (*p)->color = RED;
                (*b)->color = BLACK;
                // update genealogy
                *b = *c;
                *d = (*b)->child[1 - dir];
                if (*d != NULL && (*d)->color == RED)
                {
                    this->remove_case_6(*p, *b, *d, dir);
                    return;
                }
                *c = (*b)->child[dir];
                if (*c != NULL && (*c)->color == RED)
                {
                    this->remove_case_5(p, b, c, d, dir);
                    return;
                }
                this->remove_case_4(*p, *b);
            }

            void    remove_case_4(RBNode<T> *p, RBNode<T> *b)
            {
                p->color = RED;
                b->color = BLACK;
            }

            void    remove_case_5(RBNode<T> **p, RBNode<T> **b, \
                                  RBNode<T> **c, RBNode<T> **d, int dir)
            {
                (*b)->rotate(1 - dir);
                (*b)->color = RED;
                (*c)->color = BLACK;
                *d = *b;
                *b = *c;
                this->remove_case_6(*p, *b, *d, dir);
            }
            
            void    remove_case_6(RBNode<T> *p, RBNode<T> *b, \
                                  RBNode<T> *d, int dir)
            {
                p->rotate(dir);
                b->color = p->color;
                p->color = BLACK;
                d->color = BLACK;
            }

            // Search
            RBNode<T>   *search(key_type const &key) const
            {
                RBNode<T>   *ret = NULL;
                int         comp_res;

                if (this->key == key)
                    return (this);
                else 
                {
                    comp_res = this->_comp(this->key, key);
                    if (this->child[comp_res])
                        ret = this->child[comp_res].search(key);
                }
                return (ret);
            }

            // Iterators

        private:
            RBNode<T>   *_root;
            Compare     _comp;            
    };
}

#endif
