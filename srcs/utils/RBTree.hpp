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
    template < class Key, class T, class Compare = std::less<Key> >
    class RBTree
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef Key                                 key_type;
            typedef T                                   value_type;
            typedef pair<const key_type, value_type>    pair_type;
            // Compare
            typedef Compare                             key_compare;
            // Pointer & Ref
            typedef RBNode<Key, T>                      *NodePtr;
            typedef RBNode<Key, T>                      &NodeRef;
            typedef RBTree<Key, T, Compare>             *TreePtr;
            typedef RBTree<Key, T, Compare>             &TreeRef;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBTree(void) : _root(NULL), _comp(key_compare()) {}
            RBTree(const TreeRef src);
            ~RBTree(void) {}
            

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            TreeRef operator=(const TreeRef rhs);

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Access
            NodePtr get_root(void) const { return (this->_root); }

            // Predecessor
            NodePtr predecessor(NodePtr node)
            {
                NodePtr found;

                if (node->child[RIGHT])
                {
                    found = node->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (this->_comp(found->key, node->key))
                        return (found);
                }
                if (node->child[LEFT])
                {
                    found = node->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (this->_comp(found->key, node->key))
                        return (found);
                }
                if (node->parent)
                {
                    found = node;
                    while (found = found->parent)
                    {
                        if (this->_comp(found->key, node->key))
                            return (found);
                    }
                }
                return (NULL);
            }

            // Successor
            NodePtr successor(NodePtr node)
            {
                NodePtr found;

                if (node->child[RIGHT])
                {
                    found = node->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (this->_comp(node->key, found->key))
                        return (found);
                }
                if (node->child[LEFT])
                {
                    found = node->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (this->_comp(node->key, found->key))
                        return (found);
                }
                if (node->parent)
                {
                    found = node;
                    while (found = found->parent)
                    {
                        if (this->_comp(node->key, found->key))
                            return (found);
                    }
                }
                return (NULL);
            }
            
            // Insert
            void    insert(pair_type pair)
            {
                NodePtr node = new RBNode<Key, T>(pair->first, pair->second);

                // Recursive insertion
                this->recursive_insert(this->_root, node);

                // Repair the tree to respect r&b rules
                this->repair(node);

                // Save the root
                this->_root = node;
                while (this->_root->parent != NULL)
                    this->_root = this->_root->parent;
            }

            void    recursive_insert(NodePtr root, NodePtr node)
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
            void    repair(NodePtr node)
            {
                int     dir;
                NodePtr p;
                NodePtr g;
                
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
                    dir = node->parent->childdir();
                    if (dir ^ node->childdir())
                    {
                        node->parent->rotate(dir);
                        node = node->child[dir];
                    }
                    p = node->parent;
                    g = node->grandparent();
                    g->rotate(1 - node->childdir());
                    p->color = BLACK;
                    g->color = RED;
                }
            }

            // Remove
            NodePtr remove(key_type const &key)
            {
                NodePtr to_remove;
                NodePtr replacement;

                to_remove = this->search(this->_root, key);
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

            NodePtr remove_simple_case(NodePtr node)
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

            NodePtr remove_complex_case(NodePtr node)
            {
                // Specific case : node is BLACK with no child
                NodePtr p = node->parent;
                NodePtr b; // brother
                NodePtr c; // close nephew
                NodePtr d; // distant nephew
                int     dir;

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
                        this->remove_case_6(p, b, d, dir);
                    else if (c != NULL && c->color == RED)
                        this->remove_case_5(&p, &b, &c, &d, dir);
                    else if (p->color == RED)
                        this->remove_case_4(p, b);
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

            void    remove_case_3(NodePtr *p, NodePtr *b, \
                                  NodePtr *c, NodePtr *d, int dir)
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

            void    remove_case_4(NodePtr p, NodePtr b)
            {
                p->color = BLACK;
                b->color = RED;
            }

            void    remove_case_5(NodePtr *p, NodePtr *b, \
                                  NodePtr *c, NodePtr *d, int dir)
            {
                (*b)->rotate(1 - dir);
                (*b)->color = RED;
                (*c)->color = BLACK;
                *d = *b;
                *b = *c;
                this->remove_case_6(*p, *b, *d, dir);
            }
            
            void    remove_case_6(NodePtr p, NodePtr b, \
                                  NodePtr d, int dir)
            {
                p->rotate(dir);
                b->color = p->color;
                p->color = BLACK;
                d->color = BLACK;
            }

            // Search
            NodePtr search(NodePtr node, key_type const &key) const
            {
                NodePtr ret = NULL;
                int     comp_res;

                if (node->key == key)
                    return (node);
                else 
                {
                    comp_res = this->_comp(node->key, key);
                    if (node->child[comp_res])
                        ret = this->search(node->child[comp_res], key);
                }
                return (ret);
            }

            // Iterators
            

        private:
            NodePtr _root;
            Compare _comp;            
    };
}

#endif
