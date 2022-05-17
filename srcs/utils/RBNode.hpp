/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/17 12:59:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# define RED 0
# define BLACK 1
# define LEFT 0
# define RIGHT 1
# define LEAF NULL

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
            : parent(NULL), child[LEFT](LEAF), child[RIGHT](LEAF), color(RED) {}
            RBNode(T key)
            : parent(NULL), child[LEFT](LEAF), child[RIGHT](LEAF), color(RED), \
                key(key) {}
            RBNode(const RBNode &src) { *this = src }
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
                return (RIGHT);
            }
            
            RBNode<T>  *brother(void) const
            {
                RBNode<T>   *p = this->parent;

                if (p == NULL)
                    return (NULL)
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
            void    rotate(int dir)
            {
                RBNode<T>  *p = this->child[1 - dir];
                
                // Right son of root (this) becomes left son of p
                this->child[1 - dir] = p->child[dir];
                if (p->child[dir] != NULL)
                    p->child[dir]->parent = this;          
                p->parent = this->parent;
                // If this is the tree root, p becomes root
                // else, we replace this by p in the tree
                if (this->parent == NULL)
                    this = p;
                this->parent->child[this->childdir()] = p;
                // this is attached as left of p
                p->child[dir] = this;
                this->parent = p;
            }
    };
}

#endif
