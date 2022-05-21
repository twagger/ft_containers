/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/21 12:19:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# define RED 0
# define BLACK 1
# define LEFT 0
# define RIGHT 1
# define LEAF NULL
# include <exception>


namespace   ft
{
    template< class T >
    class RBNode
    {
        public:
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBNode(void)
            : parent(NULL), child{LEAF, LEAF}, color(RED) {}
            RBNode(T key)
            : parent(NULL), child{LEAF, LEAF}, color(RED), key(key) {}
            RBNode(const RBNode &src) { *this = src; }
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            RBNode  &operator=(const RBNode &rhs)
            {
                this->key = rhs.key;
                this->color = rhs.color;
                this->child[LEFT] = rhs.child[LEFT];
                this->child[RIGHT] = rhs.child[RIGHT];
                this->parent = rhs.parent;    
                return (*this);
            }
            
            /* ************************************************************** */
            /*  MEMBER VARIABLES                                              */
            /* ************************************************************** */
            T           key;
            char        color;
            RBNode<T>   *child[2];
            RBNode<T>   *parent;
            
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
            
            RBNode<T>  *brother(void) const
            {
                RBNode<T>   *p = this->parent;

                if (p == NULL)
                    return (NULL);
                return p->child[1 - this->childdir()];
            }

            RBNode<T>  *grandparent(void) const
            {
                RBNode<T>  *p = this->parent;

                if (p == NULL)
                    return (NULL);
                return (p->parent);
            }
            
            RBNode<T>  *uncle(void) const
            {
                RBNode<T>  *p = this->parent;
                
                if (p == NULL)
                    return (NULL);
                return (p->brother());
            }

            // Rotations
            void    rotate(int dir) // this is bugged
            {
                RBNode<T>  *x = this;
                RBNode<T>  *y = x->child[1 - dir];
                
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
            RBNode<T>  *replacement(void)
            {
                RBNode<T>   *left;
                RBNode<T>   *right;
                
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
            
            // Swap keys
            void    swapkeys(RBNode<T> *other)
            {
                T   tmp;
                
                tmp = this->key;
                this->key = other->key;
                other->key = tmp;
            }
    };
}

#endif
