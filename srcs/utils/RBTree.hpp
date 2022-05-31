/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/05/31 10:01:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include <memory>
# include "RBNode.hpp"

namespace   ft
{
    template < class T, class Compare, class A = std::allocator<T> >
    class RBTree
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef T                                   value_type;
            typedef RBTree<T, Compare, A>               tree_type;
            typedef RBNode<T, Compare>                  node_type;
            typedef typename T::first_type              key_type;
            // Compare
            typedef Compare                             key_compare;
            // Memory
            typedef A                                   allocator_type;
            // Pointer & Ref
            typedef node_type                           *node_ptr;
            typedef node_type                           &node_ref;
            typedef tree_type                           *tree_ptr;
            typedef tree_type                           &tree_ref;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            RBTree(void) : _root(NULL), _comp(key_compare()), _min(NULL), \
                           _max(NULL), _end(new node_type(\
                                            value_type(), key_compare())) {}
            RBTree(const tree_ref src);
            ~RBTree(void) {}
            

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            tree_ref operator=(const tree_ref rhs);

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Access
            node_ptr get_root(void) const { return (this->_root); }
            node_ptr get_min(void) const { return (this->_min); }
            node_ptr get_max(void) const { return (this->_max); }
            node_ptr get_end(void) const { return (this->_end); }

            // Insert 
            /**
             *  @brief  Insert a value in the tree.
             *  @param  value  A combination of key + value (pair).
             */
            node_ptr insert(value_type value)
            {
                node_ptr result;
                node_ptr node = new node_type(value);

                // Update min and max
                if (!this->_min || (this->_min 
                    && this->_comp(value.first, this->_min->value.first)))
                    this->_min = node;
                if (!this->_max || (this->_max 
                    && this->_comp(this->_max->value.first, value.first)))
                {
                    this->_max = node;
                    this->_end->child[LEFT] = this->_max;
                    this->_end->child[RIGHT] = this->_max;
                }
                
                // Recursive insertion
                result = this->_recursive_insert(this->_root, node);

                // Repair the tree to respect r&b rules
                this->_repair(node);

                // Save the root
                this->_root = node;
                while (this->_root->parent != NULL)
                    this->_root = this->_root->parent;
                return (node);
            }
            
            // Remove
            node_ptr remove(key_type const &key)
            {
                node_ptr to_remove;
                node_ptr replacement;

                to_remove = this->search(key);
                if (to_remove == NULL)
                    return (NULL);
                // Update min and max
                if (key == this->_min->value.first)
                    this->_min = to_remove->successor();
                if (key == this->_max->value.first)
                {
                    this->_max = to_remove->predecessor();
                    this->_end->child[LEFT] = this->_max;
                    this->_end->child[RIGHT] = this->_max;
                }
                // Check the number of childs
                if (to_remove->child[LEFT] && to_remove->child[RIGHT])
                {
                    // 2 childs : switch it with predecessor or successor
                    replacement = to_remove->replacement();
                    to_remove->swap_nodes(replacement);
                }
                if (to_remove->color == RED || 
                    (to_remove->child[LEFT] || to_remove->child[RIGHT]))
                    return (this->_remove_simple_case(to_remove));
                return (this->_remove_complex_case(to_remove));
            }

            // Search
            node_ptr search(key_type const &key) const
            {
                return (this->_recursive_search(this->_root, key));
            }

            // Print
            void    print(void)
            {
                if (this->_root)
                    this->_recursive_print(this->_root, "", true);
            }

        private:
            node_ptr    _root;
            node_ptr    _min; // begin node
            node_ptr    _max; // pre-end node
            node_ptr    _end; // ghost node for end(). Linked to _max node
            Compare     _comp;

            /**
             *  @brief  Tree traversal to insert the node at the right place.
             *  @param  root  The current node.
             *  @param  node  The new node to insert.
             *  @return  a combination of key + value (pair).
             * 
             *  Insert the node at the right position by comparing its pair key
             *  with the current node.
             * 
             */
            node_ptr _recursive_insert(node_ptr root, node_ptr node)
            {
                int dir;

                if (root != NULL)
                {
                    if (this->_comp(node->value.first, root->value.first))
                        dir = LEFT;
                    else if (root->value.first != node->value.first)
                        dir = RIGHT;
                    else
                        return (node);
                    if (root->child[dir] != NULL)
                    {
                        node = this->_recursive_insert(root->child[dir], node);
                        return (node);
                    }
                    else
                        root->child[dir] = node;
                }
                node->parent = root;
                return (node);
            }
            
            // Repair
            void    _repair(node_ptr node)
            {
                int     dir;
                node_ptr p;
                node_ptr g;
                
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
                    _repair(node->grandparent());
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
            node_ptr _remove_simple_case(node_ptr node)
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
                    // One child, it is necessary RED. It replaces the node.
                    if (node->child[LEFT])
                    {
                        node->swap_nodes(node->child[LEFT]);
                        node->parent->color = BLACK;
                        node->parent->child[LEFT] = NULL;
                        return (node);
                    }
                    else if (node->child[RIGHT])
                    {
                        node->swap_nodes(node->child[RIGHT]);
                        node->parent->color = BLACK;
                        node->parent->child[RIGHT] = NULL;
                        return (node->child[RIGHT]);
                    }
                    return (node);
                }
            }

            node_ptr _remove_complex_case(node_ptr node)
            {
                // Specific case : node is BLACK with no child
                node_ptr p = node->parent;
                node_ptr b; // brother
                node_ptr c; // close nephew
                node_ptr d; // distant nephew
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
                        this->_remove_case_3(&p, &b, &c, &d, dir);
                    else if (d != NULL && d->color == RED)
                        this->_remove_case_6(p, b, d, dir);
                    else if (c != NULL && c->color == RED)
                        this->_remove_case_5(&p, &b, &c, &d, dir);
                    else if (p->color == RED)
                        this->_remove_case_4(p, b);
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

            void    _remove_case_3(node_ptr *p, node_ptr *b, \
                                   node_ptr *c, node_ptr *d, int dir)
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
                    this->_remove_case_6(*p, *b, *d, dir);
                    return;
                }
                *c = (*b)->child[dir];
                if (*c != NULL && (*c)->color == RED)
                {
                    this->_remove_case_5(p, b, c, d, dir);
                    return;
                }
                this->_remove_case_4(*p, *b);
            }

            void    _remove_case_4(node_ptr p, node_ptr b)
            {
                p->color = BLACK;
                b->color = RED;
            }

            void    _remove_case_5(node_ptr *p, node_ptr *b, \
                                   node_ptr *c, node_ptr *d, int dir)
            {
                (*b)->rotate(1 - dir);
                (*b)->color = RED;
                (*c)->color = BLACK;
                *d = *b;
                *b = *c;
                this->_remove_case_6(*p, *b, *d, dir);
            }
            
            void    _remove_case_6(node_ptr p, node_ptr b, \
                                   node_ptr d, int dir)
            {
                p->rotate(dir);
                b->color = p->color;
                p->color = BLACK;
                d->color = BLACK;
            }
            
            // Recursive search
            node_ptr _recursive_search(node_ptr node, key_type const &key) const
            {
                node_ptr ret = NULL;
                int     comp_res;

                if (!node)
                    return (NULL);
                if (node->value.first == key)
                    return (node);
                else 
                {
                    comp_res = this->_comp(node->value.first, key);
                    if (node->child[comp_res])
                        ret = this->_recursive_search(\
                                        node->child[comp_res], key);
                }
                return (ret);
            }

            // Print tree
	        void    _recursive_print(\
                        node_ptr node, std::string indent, bool last) const
            {
                if (node != NULL)
                {
                    std::cout << indent;
                    if (last)
                    {
                        std::cout << "R----";
                        indent += "     ";
                    }
                    else
                    {
                        std::cout << "L----";
                        indent += "|    ";
                    }
                    std::string sColor = node->color ? "BLACK" : "RED";
                    std::cout << node->value.first << "(" << sColor << ")" 
                              << std::endl;
                    this->_recursive_print(node->child[LEFT], indent, false);
                    this->_recursive_print(node->child[RIGHT], indent, true);
                }
            }
    };
}

#endif
