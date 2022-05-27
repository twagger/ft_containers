/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/27 08:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# include "pair.hpp"

enum { RED, BLACK };
enum { LEFT, RIGHT };

namespace   ft
{
    template< class Key, class T, class Compare >
    class RBNode
    {
        private:
            /* ************************************************************** */
            /*  PRIVATE MEMBER VARIABLES                                      */
            /* ************************************************************** */
            Compare _comp;

        public:
            
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef Key                                 key_type;
            typedef T                                   value_type;
            typedef pair<const key_type, value_type>    comb_type;
            // Compare
            typedef Compare                             key_compare;
            // Pointer & Ref
            typedef RBNode<Key, T, Compare>             *NodePtr;
            typedef RBNode<Key, T, Compare>             &NodeRef;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBNode(void)
            : parent(NULL), child{NULL, NULL}, color(RED), _comp(key_compare())
            {}
            RBNode(key_type key, value_type value, \
                   const key_compare &comp = key_compare())
            : parent(NULL), child{NULL, NULL}, color(RED), _comp(comp), \
              comb(ft::pair<key_type, value_type>(key, value)){}
            RBNode(const NodeRef src) { *this = src; }
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            NodeRef operator=(const NodeRef rhs)
            {
                this->_comp = rhs.get_comp();
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
            // Getter
            key_compare &get_comp(void) const { return (this->_comp); }

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
            /**
             * @return  In-order predecessor node whose key compares less than 
             *  the current node according to the key compare function.
             */
            NodePtr predecessor(void)
            {
                NodePtr found;

                found = this->child[RIGHT];
                // Exception for end node
                if (this->child[RIGHT] 
                    && this->child[RIGHT] == this->child[LEFT])
                    return (this->child[RIGHT]);
                if (found && this->_comp(found->comb.first, this->comb.first))
                {
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (found && this->_comp(found->comb.first, this->comb.first))
                {
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    return (found);
                }
                found = this->parent;
                while (found)
                {
                    if (this->_comp(found->comb.first, this->comb.first))
                        return (found);
                    found = found->parent;
                }
                return (NULL);
            }

            // Successor
            /**
             * @return  In-order successor node whose key compares more than 
             *  the current node according to the key compare function.
             */
            NodePtr successor(void)
            {
                NodePtr found;

                found = this->child[RIGHT];
                if (found && this->_comp(this->comb.first, found->comb.first))
                {
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (found && this->_comp(this->comb.first, found->comb.first))
                {
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    return (found);
                }
                found = this->parent;
                while (found)
                {
                    if (this->_comp(this->comb.first, found->comb.first))
                        return (found);
                    found = found->parent;
                }
                return (NULL);
            }

            // Swap nodes
            void    swap_nodes(NodePtr other)
            {
                NodePtr swp_parent = this->parent;
                NodePtr swp_left = this->child[LEFT];
                NodePtr swp_right = this->child[RIGHT];
                int     swp_color = this->color;

                // put this in the place of other 
                this->parent = other->parent;
                this->child[LEFT] = other->child[LEFT];
                this->child[RIGHT] = other->child[RIGHT];
                if (this->parent)
                    this->parent->child[this->childdir()] = this;
                if (this->child[LEFT])
                    this->child[LEFT]->parent = this;
                if (this->child[RIGHT])
                    this->child[RIGHT]->parent = this;
                this->color = other->color;

                // put other in the place of this 
                other->parent = swp_parent;
                other->child[LEFT] = swp_left;
                other->child[RIGHT] = swp_right;
                if (other->parent)
                    other->parent->child[other->childdir()] = other;
                if (swp_left)
                    swp_left->parent = other;
                if (swp_right)
                    swp_right->parent = other;
                other->color = swp_color;
            }
    };
}

#endif
