/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:18:31 by twagner           #+#    #+#             */
/*   Updated: 2022/06/14 14:49:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP
# include <memory>
# include <algorithm>
# include "../iterators/tree_iterator.hpp"
# include "../containers/Vector.hpp"
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
            typedef T                                           value_type;
            typedef RBTree<T, Compare, A>                       tree_type;
            typedef RBNode<T, Compare>                          node_type;
            typedef typename T::first_type                      key_type;
            typedef A                                           allocator_type;
            // Compare
            typedef Compare                                     key_compare;
            // Pointer & Ref
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef node_type                                   *node_ptr;
            typedef node_type                                   &node_ref;
            typedef tree_type                                   *tree_ptr;
            typedef tree_type                                   &tree_ref;
            // Memory
            typedef typename A::template rebind<node_type>::other
                                                                node_allocator;
            // Iterators
            typedef t_iterator<node_type>                       iterator;
            typedef t_const_iterator<node_type>                 const_iterator;
            // Node pool
            struct  node_pool
            {
                // Constructor & destructor
                node_pool(void)
                {
                    this->nodes = vector<node_ptr>(0);
                    this->nb = 0;
                    this->_allocator = node_allocator();
                }
                ~node_pool(void)
                {
                    for (int i = 0; i < this->nb; ++i)
                    {
                        _allocator.destroy(this->nodes[i]);
                        _allocator.deallocate(this->nodes[i], 1);
                    }
                }
                // Attributes
                vector<node_ptr>    nodes;
                node_allocator      _allocator;
                int                 nb;
            };
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Default
            RBTree(void) : _root(NULL), _min(NULL), _max(NULL), \
                           _comp(key_compare()), _allocator(node_allocator())
            {
                this->_end = this->_allocator.allocate(1);
                this->_allocator.construct(this->_end, value_type());
                this->_end->color = WHITE;
            }

            // Copy
            RBTree(const tree_ref src) : _root(NULL), _comp(src._comp), \
                                         _allocator(node_allocator())
            {
                this->_end = this->_allocator.allocate(1);
                this->_allocator.construct(this->_end, value_type());
                this->_end->color = WHITE;
                *this = src;
            }

            // Destructor
            ~RBTree(void) { this->clear(); this->_clear_node(this->_end); } 

            /* ************************************************************** */
            /*  OPERATORS OVERLOAD                                            */
            /* ************************************************************** */
            tree_ref operator=(const tree_type &rhs)
            { 
                node_pool   pool; // pool of recycled nodes from this
                
                if (this != &rhs)
                {
                    this->_recycle(this->get_root(), &pool);
                    this->_allocator = rhs._allocator;
                    this->_comp = rhs._comp;
                    this->_root = this->_copy(rhs.get_root(), &pool);
                    this->_max = this->_find_min();
                    this->_min = this->_find_max();
                    this->_end->child[RIGHT] = this->_max;
                }
                return (*this);
            }

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Access
            node_ptr        get_root(void) const { return (this->_root); }
            node_ptr        get_min(void) const { return (this->_min); }
            node_ptr        get_max(void) const { return (this->_max); }
            node_ptr        get_end(void) const { return (this->_end); }
            node_allocator  get_allocator(void) const 
            { return (this->_allocator); }

            // Insert 2
            /**
             * @brief Insert a node in the right position in the tree
             * 
             * @param node Node_ptr to be inserted
             * @param parent Parent node. It must be a leaf or null.
             * @param dir Left of right to position the node.
             */
            void    insert(node_ptr node, node_ptr parent, int dir)
            {
                node_ptr    grandpa;
                node_ptr    uncle;
                node_ptr    inserted = node;
                
                node->color = RED;
                node->child[LEFT] = NULL;
                node->child[RIGHT] = NULL;
                node->parent = parent;
                if (parent == NULL)
                {
                    this->_root = node;
                    _update_min_max_end(inserted);
                    return ; // Insertion complete
                }
                parent->child[dir] = node;
                while (parent)
                {
                    if (parent->color == BLACK)
                    {
                        _update_min_max_end(inserted);
                        return ; // Insertion complete
                    }
                    if ((grandpa = node->grandparent()) == NULL)
                    {
                        parent->color = BLACK;
                        _update_min_max_end(inserted);
                        return ; // Insertion complete
                    }
                    dir = parent->childdir();
                    uncle = grandpa->child[1 - dir];
                    if (is_nil(uncle) || uncle->color == BLACK)
                    {
                        if (node == parent->child[1 - dir])
                        {
                            parent->rotate(dir);
                            node = parent;
                            parent = grandpa->child[dir];
                        }
                        grandpa->rotate(1 - dir) ;
                        parent->color = BLACK;
                        grandpa->color = RED;
                        // Save the root
                        this->_root = grandpa;
                        this->_save_root();
                        _update_min_max_end(inserted);
                        return ; // Insertion complete
                    }
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandpa->color = RED;
                    node = grandpa;
                    parent = node->parent;
                }
                _update_min_max_end(inserted);
                return ; // Insertion complete
            }

            // Erase
            size_t  erase(key_type const &key)
            {
                node_ptr to_remove;
                to_remove = this->search(key);
                if (to_remove == this->get_end())
                    return (0);
                this->_remove(to_remove);
                return (1);
            }

            template<class Iter>
            void    erase(Iter position)
            {
                node_ptr    to_remove;
                to_remove = position._p;
                if (!is_nil(to_remove))
                    this->_remove(to_remove);
            }

            // Search
            node_ptr search(key_type const &key) const
            {
                return (this->_recursive_search(this->_root, key));
            }
            
            // Find insert pos
            node_ptr find_insert_pos(key_type const &key) const
            {
                return (this->_recursive_find_pos(this->_root, key));
            }

            // Print
            void    print(void)
            {
                if (this->_root)
                    this->_recursive_print(this->_root, "", true);
            }

            // Clear tree
            void    clear(void) 
            { 
                this->_recursive_clear(this->_root);
                this->_root = NULL;
                this->_min = NULL;
                this->_max = NULL;
            }

            // Swap tree
            void    swap(tree_ref other)
            {
                std::swap(this->_root, other._root);
                std::swap(this->_min, other._min);
                std::swap(this->_max, other._max);
                std::swap(this->_end, other._end);
            }

            // Lower bound
            iterator    get_lower_bound(key_type &k)
            {
                iterator    it = iterator(this->_min);

                while (it._p != this->_end 
                       && key_compare()((*it).first, k) == true) 
                    ++it;
                return (it);
            }
            
            // Upper bound
            iterator    get_upper_bound(key_type &k)
            {
                iterator    it = iterator(this->_min);

                while (it._p != this->_end
                       && key_compare()(k, (*it).first) == false)
                    ++it;
                return (it);
            }

        protected:
            node_ptr        _root;
            node_ptr        _min; // begin node
            node_ptr        _max; // pre-end node
            node_ptr        _end; // ghost node for end(). Linked to _max node
            key_compare     _comp;
            node_allocator  _allocator;

            // save the root
            void    _save_root(void)
            {
                while (this->_root->parent != NULL)
                    this->_root = this->_root->parent;
            }

            // Update min and max
            void    _update_min_max_end(node_ptr node)
            {
                if (node == NULL)
                    return ;
                if (!this->_min || (this->_min 
                    && this->_comp(node->value.first, this->_min->value.first)))
                    this->_min = node;
                if (!this->_max || (this->_max 
                    && this->_comp(this->_max->value.first, node->value.first)))
                {
                    this->_max = node;
                    node->child[RIGHT] = this->_end;
                    this->_end->child[RIGHT] = this->_max;
                }
            }
            
            // find min
            node_ptr    _find_min(void)
            {
                node_ptr    result = this->_root;
                
                if (is_nil(this->_root))
                    return (NULL);
                if (!is_nil(result->child[LEFT])
                    && this->_comp(result->child[LEFT]->value.first, \
                                   result->value.first))
                {
                    while (!is_nil(result->child[LEFT]))
                    { result = result->child[LEFT]; }
                }
                else if (!is_nil(result->child[RIGHT])
                         && this->_comp(result->child[RIGHT]->value.first, \
                                   result->value.first))
                {
                    while (!is_nil(result->child[RIGHT]))
                    { result = result->child[RIGHT]; }
                }
                return (result);
            }
            
            // find max
            node_ptr    _find_max(void)
            {
                node_ptr    result = this->_root;
                
                if (is_nil(this->_root))
                    return (NULL);
                if (!is_nil(result->child[LEFT])
                    && this->_comp(result->value.first, \
                                   result->child[LEFT]->value.first))
                {
                    while (!is_nil(result->child[LEFT]))
                    { result = result->child[LEFT]; }
                }
                else if (!is_nil(result->child[RIGHT])
                         && this->_comp(result->value.first, \
                                   result->child[RIGHT]->value.first))
                {
                    while (!is_nil(result->child[RIGHT]))
                    { result = result->child[RIGHT]; }
                }
                return (result);    
            }
            
            // Recycle nodes using pool
            void    _recycle(node_ptr node, node_pool *pool)
            {
                // recursive recycling
                if (is_nil(node))
                {
                    if (this->_root == NULL && this->_end)
                    {
                        this->_allocator.destroy(this->_end);
                        pool->nodes.push_back(this->_end);
                        ++pool->nb;
                        return ; 
                    }
                    if (node) // Reuse ghost '_end' node too
                    {
                        this->_allocator.destroy(node);
                        pool->nodes.push_back(node);
                        ++pool->nb;
                    }
                    return ;
                }
                this->_recycle(node->child[LEFT], pool);
                this->_recycle(node->child[RIGHT], pool);
                // Destroy node
                this->_allocator.destroy(node);
                // Add node to the pool
                pool->nodes.push_back(node);
                ++pool->nb;
            }
            
            // Copy
            node_ptr    _copy(node_ptr node, node_pool *pool)
            {
                node_ptr    dest;
                
                if (!node)
                    return (NULL);
                if (pool->nb) // If pool is still available, use it
                {
                    dest = pool->nodes[pool->nb - 1];
                    --pool->nb;
                }
                else // allocate it
                    dest = this->_allocator.allocate(1);
                // Construct by value
                this->_allocator.construct(dest, node->value);
                // Copy simple attributes
                dest->color = node->color;
                if (dest->color == WHITE) // Ghost node
                {
                    this->_end = dest;
                    return (NULL); // to avoid looping on RIGHT with _max node
                }
                // Childrens
                dest->child[LEFT] = this->_copy(node->child[LEFT], pool);
                dest->child[RIGHT] = this->_copy(node->child[RIGHT], pool);
                // Parent link
                if (dest->child[LEFT])
                    dest->child[LEFT]->parent = dest;
                if (dest->child[RIGHT])
                    dest->child[RIGHT]->parent = dest;
                return (dest);
            }

            // Remove
            void    _remove(node_ptr to_remove)
            {
                node_ptr    replacement;
                key_type    key = to_remove->value.first;

                // Update min and max
                if (key == this->_min->value.first)
                    this->_min = to_remove->successor();
                if (key == this->_max->value.first)
                {
                    this->_max = to_remove->predecessor();
                    this->_end->child[RIGHT] = this->_max;
                }
                // Check the number of childs
                if (!is_nil(to_remove->child[LEFT])
                    && !is_nil(to_remove->child[RIGHT]))
                {
                    // 2 childs : switch it with predecessor or successor
                    replacement = to_remove->replacement();
                    to_remove->swap(replacement);
                    if (this->_root == to_remove)
                        this->_root = replacement;
                }
                if (to_remove->color == RED || 
                    (!is_nil(to_remove->child[LEFT]) 
                     || !is_nil(to_remove->child[RIGHT])))
                    this->_remove_simple_case(to_remove);
                else
                    this->_remove_complex_case(to_remove);
                // Re-attach ghost node to the max as right child
                if (this->_end->child[RIGHT])
                    this->_end->child[RIGHT]->child[RIGHT] = this->_end;
            }

            // Remove
            void    _remove_simple_case(node_ptr node)
            {
                // All cases but the one where the node is black with no child
                // With the simple cases we don't need to rebalance the tree
                if (node->color == RED)
                {
                    // Node is RED : remove it
                    // If root, remove it
                    if (this->_root == node)
                        this->_root = NULL;
                    else
                    {
                        this->_save_root();
                        node->parent->child[node->childdir()] = NULL;
                    }
                }
                else // Node is BLACK
                {
                    // One child, it is necessary RED. It replaces the node.
                    if (!is_nil(node->child[LEFT]))
                    {
                        node->swap(node->child[LEFT]);
                        this->_save_root();
                        node->parent->color = BLACK;
                        node->parent->child[LEFT] = NULL;
                    }
                    else if (!is_nil(node->child[RIGHT]))
                    {
                        node->swap(node->child[RIGHT]);
                        this->_save_root();
                        node->parent->color = BLACK;
                        node->parent->child[RIGHT] = NULL;
                    }
                }
                this->_clear_node(node);
            }

            void    _remove_complex_case(node_ptr node)
            {
                // Specific case : node is BLACK with no child
                node_ptr    p = node->parent;
                node_ptr    saved = node;
                node_ptr    b; // brother
                node_ptr    c; // close nephew
                node_ptr    d; // distant nephew
                int         dir;

                // 1. Replace node by NULL in its parent :
                //  the tree is now unbalanced !
                try
                { dir = node->childdir(); }
                catch (std::runtime_error &e) // tree with only root
                {
                    this->_clear_node(node);
                    this->_root = NULL;
                    this->_end->child[RIGHT] = NULL;
                    return ;
                }
                this->_save_root();
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
                    else if (!is_nil(d) && d->color == RED)
                        this->_remove_case_6(p, b, d, dir);
                    else if (!is_nil(c) && c->color == RED)
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
                    this->_clear_node(saved);
                    return ;
                }
                this->_clear_node(saved);
                return ; // remove_case_2
            }

            void    _remove_case_3(node_ptr *p, node_ptr *b, \
                                   node_ptr *c, node_ptr *d, int dir)
            {
                // rotate
                (*p)->rotate(dir);
                this->_save_root();
                // r&b rules repair
                (*p)->color = RED;
                (*b)->color = BLACK;
                // update genealogy
                *b = *c;
                *d = (*b)->child[1 - dir];
                if (!is_nil(*d) && (*d)->color == RED)
                {
                    this->_remove_case_6(*p, *b, *d, dir);
                    return;
                }
                *c = (*b)->child[dir];
                if (!is_nil(*c) && (*c)->color == RED)
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
                this->_save_root();
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
                this->_save_root();
                b->color = p->color;
                p->color = BLACK;
                d->color = BLACK;
            }
            
            // Recursive search
            node_ptr _recursive_search(node_ptr node, key_type const &key) const
            {
                node_ptr    ret;
                int         dir;

                if (is_nil(node))
                    return (this->_end);
                if (node->value.first == key)
                    return (node);
                else 
                {
                    dir = this->_comp(node->value.first, key);
                    ret = this->_recursive_search(node->child[dir], key);
                }
                return (ret);
            }

            // Recursive search
            node_ptr _recursive_find_pos(node_ptr node, key_type const &key) const
            {
                int dir;
                if (node == NULL)
                    return (NULL);
                if (node->value.first == key)
                    return (node);
                else 
                {
                    dir = this->_comp(node->value.first, key);
                    if (is_nil(node->child[dir]))
                        return (node);
                    else
                        node = this->_recursive_find_pos(node->child[dir], key);
                }
                return (node);
            }
            
            // Print tree
	        void    _recursive_print(\
                        node_ptr node, std::string indent, bool last) const
            {
                if (!is_nil(node))
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

            void    _clear_node(node_ptr node)
            {
                this->_allocator.destroy(node);
                this->_allocator.deallocate(node, 1);
            }

            // Recursive clear
            void    _recursive_clear(node_ptr node)
            {
                if (is_nil(node))
                    return ;
                _recursive_clear(node->child[LEFT]);
                _recursive_clear(node->child[RIGHT]);
                this->_allocator.destroy(node);
                this->_allocator.deallocate(node, 1);
                return ;
            }
    };
}

#endif
