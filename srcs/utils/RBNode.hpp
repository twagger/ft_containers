/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBNode.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 08:40:15 by marvin            #+#    #+#             */
/*   Updated: 2022/05/17 08:44:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBNODE_HPP
# define RBNODE_HPP
# define RED 0
# define BLACK 1
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
            : parent(NULL), left(LEAF), right(LEAF), color(RED) {}
            RBNode(T key)
            : parent(NULL), left(LEAF), right(LEAF), color(RED), key(key) {}
            RBNode(const RBNode &src) { *this = src }
            ~RBNode(void) {}

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            RBNode  &operator=(const RBNode &rhs)
            {
                this->key = rhs.key;
                this->color = rhs.color;
                this->left = rhs.left;
                this->right = rhs.right;
                this->parent = rhs.parent;    
                return (*this);
            }
            
            /* ************************************************************** */
            /*  MEMBER VARIABLES                                              */
            /* ************************************************************** */
            T           key;
            char        color;
            RBNode<T>  *left;
            RBNode<T>  *right;
            RBNode<T>  *parent;
            
            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Genealogy
            RBNode<T>  *parent(void) const
            { return (this->parent); }
            
            RBNode<T>  *brother(void) const
            {
                RBNode<T>  *p = this->parent();
                
                if (p == NULL)
                    return (NULL)
                if (this == p->left)
                    return (p->right);
                else
                    return (p->left);
            }

            RBNode<T>  *grandparent(void) const
            {
                RBNode<T>  *p = this->parent();

                if (p == NULL)
                    return (NULL);
                return (p->parent());
            }
            
            RBNode<T>  *uncle(void) const
            {
                RBNode<T>  *p = this->parent();
                
                if (p == NULL)
                    return (NULL);
                return (p->brother());
            }

            // Rotations
            // Left
            void    rot_left(void)
            {
                RBNode<T>  *p = this->right;
                
                // Right son of root (this) becomes left son of p
                this->right = p->left;
                if (p->left != NULL)
                    p->left->parent = this;          
                p->parent = this->parent();
                // If this is the tree root, p becomes root
                // else, we replace this by p in the tree
                if (this->parent() == NULL)
                    this = p;
                else if (this == this->parent()->left)
                    this->parent->left = p;
                else
                    this->parent->right = p;
                // this is attached as left of p
                p->left = this;
                this->parent = p;
            }
        
            // Right
            void    rot_right(void)
            {
                RBNode<T>  *p = this->left;
                
                // Right son of root (this) becomes right son of p
                this->left = p->right;
                if (p->right != NULL)
                    p->right->parent = this;          
                p->parent = this->parent();
                // If this is the tree root, p becomes root
                // else, we replace this by p in the tree
                if (this->parent() == NULL)
                    this = p;
                else if (this == this->parent()->right)
                    this->parent->right = p;
                else
                    this->parent->left = p;
                // this is attached as right of p
                p->right = this;
                this->parent = p;
            }
    };
}

#endif
