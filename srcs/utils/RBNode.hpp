/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/31 09:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# include "pair.hpp"

enum { RED, BLACK };
enum { LEFT, RIGHT };

namespace   ft
{
    template< class T, class Compare >
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
            typedef T                                   value_type;
            typedef RBNode<T, Compare>                  node_type;
            // Compare
            typedef Compare                             key_compare;
            // Pointer & Ref
            typedef node_type                           *node_ptr;
            typedef node_type                           &node_ref;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBNode(void)
            : parent(NULL), child{NULL, NULL}, color(RED), _comp(key_compare())
            {}
            RBNode(value_type value, const key_compare &comp = key_compare())
            : parent(NULL), child{NULL, NULL}, color(RED), _comp(comp), \
              value(value){}
            RBNode(const node_ref src) { *this = src; }
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            node_ref operator=(const node_ref rhs)
            {
                this->_comp = rhs.get_comp();
                this->value = rhs.value;
                this->color = rhs.color;
                this->child[LEFT] = rhs.child[LEFT];
                this->child[RIGHT] = rhs.child[RIGHT];
                this->parent = rhs.parent;    
                return (*this);
            }
            
            /* ************************************************************** */
            /*  MEMBER VARIABLES                                              */
            /* ************************************************************** */
            value_type  value;
            char        color;
            node_ptr    child[2];
            node_ptr    parent;
            
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
            
            node_ptr brother(void) const
            {
                node_ptr p = this->parent;

                if (p == NULL)
                    return (NULL);
                return p->child[1 - this->childdir()];
            }

            node_ptr grandparent(void) const
            {
                node_ptr p = this->parent;

                if (p == NULL)
                    return (NULL);
                return (p->parent);
            }
            
            node_ptr uncle(void) const
            {
                node_ptr p = this->parent;
                
                if (p == NULL)
                    return (NULL);
                return (p->brother());
            }

            // Rotations
            void    rotate(int dir) // this is bugged
            {
                node_ptr x = this;
                node_ptr y = x->child[1 - dir];
                
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
            node_ptr replacement(void)
            {
                node_ptr left;
                node_ptr right;
                
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
            node_ptr predecessor(void)
            {
                node_ptr found;

                found = this->child[RIGHT];
                // Exception for end node
                if (this->child[RIGHT] 
                    && this->child[RIGHT] == this->child[LEFT])
                    return (this->child[RIGHT]);
                if (found && this->_comp(found->value.first, this->value.first))
                {
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (found && this->_comp(found->value.first, this->value.first))
                {
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    return (found);
                }
                found = this->parent;
                while (found)
                {
                    if (this->_comp(found->value.first, this->value.first))
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
            node_ptr successor(void)
            {
                node_ptr found;

                found = this->child[RIGHT];
                if (found && this->_comp(this->value.first, found->value.first))
                {
                    while (found->child[LEFT])
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (found && this->_comp(this->value.first, found->value.first))
                {
                    while (found->child[RIGHT])
                        found = found->child[RIGHT];
                    return (found);
                }
                found = this->parent;
                while (found)
                {
                    if (this->_comp(this->value.first, found->value.first))
                        return (found);
                    found = found->parent;
                }
                return (NULL);
            }

            // Swap nodes
            void    swap_nodes(node_ptr other)
            {
                node_ptr swp_parent = this->parent;
                node_ptr swp_left = this->child[LEFT];
                node_ptr swp_right = this->child[RIGHT];
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
