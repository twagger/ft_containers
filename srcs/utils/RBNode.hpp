/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/06/06 10:01:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# include "pair.hpp"

enum { RED, BLACK, WHITE };
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
            
            // Default constructor
            RBNode(void){}

            // Non member functions
            friend bool is_nil(RBNode<T, Compare> *node)
            { return (node == NULL || (node && node->color == WHITE) );}

        public:
            
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef T                       value_type;
            typedef RBNode<T, Compare>      node_type;
            // Compare
            typedef Compare                 key_compare;
            // Pointer & Ref
            typedef T                       &reference;
            typedef const T                 &const_reference;
            typedef T                       *pointer;
            typedef const T                 *const_pointer;
            typedef node_type               *node_ptr;
            typedef node_type               &node_ref;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Param
            RBNode(value_type value, const key_compare &comp = key_compare())
            : parent(NULL), child{NULL, NULL}, color(RED), _comp(comp), \
              value(value) {}

            // Copy
            RBNode(const node_ref src)
            : parent(NULL), child{NULL, NULL}, color(src.color), \
              _comp(src._comp), value(src.value)
            { *this = src; }
 
            // Destructor
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            node_ref operator=(const node_ref other) // not used for now
            {
                node_ptr new_left = nullptr;
                node_ptr new_right = nullptr;

                if (other.child[LEFT])
                    new_left = new node_type(*other.child[LEFT]);
                if (other.child[RIGHT])
                    new_right = new node_type(*other.child[RIGHT]);
                this->value = other.value;
                std::swap(this->child[LEFT],  new_left);
                std::swap(this->child[RIGHT], new_right);
                delete new_left;
                delete new_right;
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
                while (!is_nil(left->child[RIGHT]))
                    left = left->child[RIGHT];
                while (!is_nil(right->child[LEFT]))
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
                if (this->color == WHITE)
                    return (found);
                if (!is_nil(found) 
                    && this->_comp(found->value.first, this->value.first))
                {
                    while (!is_nil(found->child[LEFT]))
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (!is_nil(found)
                    && this->_comp(found->value.first, this->value.first))
                {
                    while (!is_nil(found->child[RIGHT]))
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
                // exception for end node
                if (found && found->color == WHITE) 
                    return (found);
                if (!is_nil(found)
                    && this->_comp(this->value.first, found->value.first))
                {
                    while (!is_nil(found->child[LEFT]))
                        found = found->child[LEFT];
                    return (found);
                }
                found = this->child[LEFT];
                if (!is_nil(found)
                    && this->_comp(this->value.first, found->value.first))
                {
                    while (!is_nil(found->child[RIGHT]))
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
            void    swap(node_ptr other)
            {
                int t_dir;
                int o_dir;
                
                // Save original node direction from its parent
                try {   
                    t_dir = this->childdir();
                    o_dir = other->childdir();
                }
                catch (std::runtime_error &e)
                {
                    if (!this->parent)
                        t_dir = -1;
                    if (!other->parent)
                        o_dir = -1;
                }
                // Swap pointers on the node
                std::swap(this->parent, other->parent);
                std::swap(this->child[LEFT], other->child[LEFT]);
                std::swap(this->child[RIGHT], other->child[RIGHT]);
                // Swap colors > to not impact the RBTree rules
                std::swap(this->color, other->color);
                // Change child pointer on parent node
                if (t_dir != -1)
                    other->parent->child[t_dir] = other;
                if (o_dir != -1)
                    this->parent->child[o_dir] = this;
                // Change parent pointer on childs
                if (this->child[LEFT])
                    this->child[LEFT]->parent = this;
                if (this->child[RIGHT])
                    this->child[RIGHT]->parent = this;
                if (other->child[LEFT])
                    other->child[LEFT]->parent = other;
                if (other->child[RIGHT])
                    other->child[RIGHT]->parent = other;
            }
    };
}

#endif
