/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/24 10:35:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# define LEAF NULL
# include "pair.hpp"

enum { RED, BLACK };
enum { RIGHT, LEFT };

namespace   ft
{
    template< class Key, class T, class Compare >
    class RBNode
    {
        public:
            
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef Key                         key_type;
            typedef T                           value_type;
            typedef pair<key_type, value_type>  comb_type;
            // Compare
            typedef Compare                     key_compare;
            // Pointer & Ref
            typedef RBNode<Key, T, Compare>     *NodePtr;
            typedef RBNode<Key, T, Compare>     &NodeRef;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBNode(void)
            : parent(NULL), child{LEAF, LEAF}, color(RED), _comp(key_compare())
            {}
            RBNode(key_type key, value_type value, \
                   const key_compare &_comp = key_compare())
            : parent(NULL), child{LEAF, LEAF}, color(RED), \
              comb(ft::pair<key_type, value_type>(key, value)){}
            RBNode(const NodeRef src) { *this = src; }
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            NodeRef operator=(const NodeRef rhs)
            {
                this->comb = rhs.comb;
                this->color = rhs.color;
                this->child[LEFT] = rhs.child[LEFT];
                this->child[RIGHT] = rhs.child[RIGHT];
                this->parent = rhs.parent;    
                return (*this);
            }
            
            /* ************************************************************** */
            /*  MEMBER VARIABLES                                              */
            /* ************************************************************** */
            comb_type       comb;
            char            color;
            NodePtr         child[2];
            NodePtr         parent;
            
            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Genealogy
            int childdir(void) const
            {
                if (this->parent && this == this->parent->child[LEFT])
                    return (LEFT);
                else if (this->parent && this == this->parent->child[RIGHT])
                    return (RIGHT);
                else
                    throw std::runtime_error("the node is orphan");
            }
            
            NodePtr brother(void) const
            {
                NodePtr p = this->parent;

                if (p == NULL)
                    return (NULL);
                return p->child[1 - this->childdir()];
            }

            NodePtr grandparent(void) const
            {
                NodePtr p = this->parent;

                if (p == NULL)
                    return (NULL);
                return (p->parent);
            }
            
            NodePtr uncle(void) const
            {
                NodePtr p = this->parent;
                
                if (p == NULL)
                    return (NULL);
                return (p->brother());
            }

            // Rotations
            void    rotate(int dir) // this is bugged
            {
                NodePtr x = this;
                NodePtr y = x->child[1 - dir];
                
                // Right son of root (this) becomes left son of p
                x->child[1 - dir] = y->child[dir];
                if (y->child[dir] != NULL)
                    y->child[dir]->parent = this;          
                y->parent = x->parent;
                // We replace this by p in the tree
                if (x->parent == NULL)
                    x->parent = y;
                else if (x == x->parent->child[dir])
                    x->parent->child[dir] = y;
                else
                    x->parent->child[1 - dir] = y;
                // this is attached as child of p
                y->child[dir] = x;
                x->parent = y;
            }

            // Replacement node (predecessor or successor from left or right
            //  subtree). RED node is returned if possible
            NodePtr replacement(void)
            {
                NodePtr left;
                NodePtr right;
                
                left = this->child[LEFT];
                right = this->child[RIGHT];
                while (left->child[RIGHT])
                    left = left->child[RIGHT];
                while (right->child[LEFT])
                    right = right->child[LEFT];
                if (left->color == RED)
                    return (left);
                return (right);
            }
            
            // Predecessor
            NodePtr predecessor(void)
            {
                NodePtr found;

                if (this->child[RIGHT])
                {
                    found = this->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (this->_comp(found->comb.first, this->comb.first))
                        return (found);
                }
                if (this->child[LEFT])
                {
                    found = this->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (this->_comp(found->comb.first, this->comb.first))
                        return (found);
                }
                if (this->parent)
                {
                    found = this;
                    while (found = found->parent)
                    {
                        if (this->_comp(found->comb.first, this->comb.first))
                            return (found);
                    }
                }
                return (NULL);
            }

            // Successor
            NodePtr successor(void)
            {
                NodePtr found;

                if (this->child[RIGHT])
                {
                    found = this->child[RIGHT];
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    if (this->_comp(this->comb.first, found->comb.first))
                        return (found);
                }
                if (this->child[LEFT])
                {
                    found = this->child[LEFT];
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    if (this->_comp(this->comb.first, found->comb.first))
                        return (found);
                }
                if (this->parent)
                {
                    found = this;
                    while (found = found->parent)
                    {
                        if (this->_comp(this->comb.first, found->comb.first))
                            return (found);
                    }
                }
                return (NULL);
            }
           
            // Swap pairs
            void    swapkeys(NodePtr other)
            {
                comb_type   tmp(this->comb.first, this->comb.second);
                
                this->comb = other->comb;
                other->comb = tmp;
            }
            
        private:
            key_compare _comp;
    };
}

#endif
