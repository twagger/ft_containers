/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/14 13:35:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# define RED 0
# define BLACK 1
# define LEAF NULL

namespace   ft
{
    template< class T >
    class RBNode
    {
        public:
            // Constructor and destructor
            RBNode(void)
            : parent(NULL), left(LEAF), right(LEAF), color(RED) {}
            RBNode(T key)
            : parent(NULL), left(LEAF), right(LEAF), color(RED), key(key) {}
            RBNode(const RBNode &src) { *this = src }
            ~RBNode(void) {}

            // Operator overload
            RBNode  &operator=(const RBNode &rhs)
            {
                this->key = rhs.key;
                this->color = rhs.color;
                this->left = rhs.left;
                this->right = rhs.right;
                this->parent = rhs.parent;    
                return (*this);
            }
            
            // Member variables
            T           key;
            char        color;
            RBNode<T>  *left;
            RBNode<T>  *right;
            RBNode<T>  *parent;

            // Member functions
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

    template< class T, class Compare >
    class RBTree
    {
        public:
            // Constructor & destructir
            RBTree(void) {}
            RBTree(const RBTree &src);
            ~RBTree(void) {}

            // Operator overload
            RBTree  &operator=(const RBTree &rhs);

            // Member functions
            // Insert
            void    insert(RBNode *node)
            {
                // Recursive insertion
                this->recursive_insert(this->_root, node);

                // Repair the tree to respect r&b rules
                this->repair(node);
                
                // Save the root
                this->_root = n;
                while (this->_root->parent() != NULL)
                    this->_root = this->_root->parent();
            }

            void    recursive_insert(RBNode *root, RBNode *node)
            {
                if (root != NULL && this->comp(node->key, root->key))
                {
                    if (root->left != LEAF)
                    {
                        this->recursive_insert(root->left, node);
                        return;
                    }
                    else
                        root->left = node;
                }
                else if (root != NULL)
                {
                    if (root->right != LEAF)
                    {
                        this->recursive_insert(root->right, node);
                        return;
                    }
                    else
                        root->right = node;
                }
                node->parent = root;
            }

            // Delete

            // Search

            // Repair

            // Iterators

        private:
            RBNode<T>   *_root;
            Compare     comp;            
    };
}

#endif
