/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:27:08 by twagner           #+#    #+#             */
/*   Updated: 2022/06/17 14:14:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP
# include <memory>
# include "../iterators/tree_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/RBTree.hpp"

namespace   ft
{
    template < class T, class Compare = std::less<T>, \
               class A = std::allocator<T> >
    class set
    {
        
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef T                                           key_type;
            typedef T                                           value_type;
            // Compare
            typedef Compare                                     key_compare;
            typedef Compare                                     value_compare;
            // Tree
            typedef RBTree<value_type, Compare, A>              tree_type;
            typedef RBNode<value_type, Compare>                 node_type;
            // Memory
            typedef A                                           allocator_type;
            // Size
            typedef std::size_t                                 size_type;
            // Difference
            typedef ptrdiff_t                                   difference_type;
            // References and pointers
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            // Iterators
            typedef t_iterator<node_type>                       iterator;
            typedef t_const_iterator<node_type>                 const_iterator;
            typedef ft::reverse_iterator<iterator>             reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Empty
            explicit set(const key_compare &comp = key_compare(), \
                        const allocator_type &alloc = allocator_type())
            : _allocator(alloc), _compare(comp), _size(0) {}
              
            // Range
            template <class InputIterator>
            set(InputIterator first, InputIterator last, \
                const key_compare& comp = key_compare(), \
                const allocator_type& alloc = allocator_type())
            : _allocator(alloc), _compare(comp), _size(0)
            { this->insert(first, last); }
            
            // Copy
            set(const set &x)
            : _allocator(x._allocator), _compare(x._compare), _size(0)
            { *this = x; }

            // Destructor
            ~set(void) {};

            /* ************************************************************** */
            /*  OPERATOR OVERLOADS                                            */
            /* ************************************************************** */
            set                     &operator=(const set &x)
            {
                this->_tree = x._tree;
                this->_size = x.size();
                return (*this);
            }

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Iterators
            iterator                begin(void)
            { return iterator(this->_tree.get_min()); }

            iterator                end(void)
            { return iterator(this->_tree.get_end()); }

            const_iterator          begin(void) const
            { return const_iterator(this->_tree.get_min()); }

            const_iterator          end(void) const
            { return const_iterator(this->_tree.get_end()); }
            
            reverse_iterator        rbegin(void)
            { return reverse_iterator(this->_tree.get_end()); }
            
            const_reverse_iterator  rbegin(void) const
            { return const_reverse_iterator(this->_tree.get_end()); }

            reverse_iterator        rend(void)
            { return reverse_iterator(this->_tree.get_min()); }

            const_reverse_iterator  rend(void) const
            { return const_reverse_iterator(this->_tree.get_min()); }

            // Capacity
            bool                    empty(void) const
            { return (this->_size == 0); }
            
            size_type               size(void) const
            { return (this->_size); }

            size_type               max_size(void) const
            { return (this->_allocator.max_size()); }
            
            // Modifiers
            pair<iterator, bool>    insert(const value_type &val)
            {
                node_type       *ret;
                node_type       *node;
                value_compare   comp = this->value_comp();
                int             dir;

                ret = this->_tree.find_insert_pos(val);
                if (ret == NULL) // Insert first node
                {
                    node = this->_tree.get_allocator().allocate(1);
                    this->_tree.get_allocator().construct(node, val);
                    this->_tree.insert(node, ret, LEFT);
                    ++this->_size;
                }
                else if (ret->value == val) // Key already exists
                    return (pair<iterator, bool>(ret, false));
                else // New node
                {
                    dir = comp(ret->value, val);
                    node = this->_tree.get_allocator().allocate(1);
                    this->_tree.get_allocator().construct(node, val);
                    this->_tree.insert(node, ret, dir);
                    ++this->_size;
                }
                return (pair<iterator, bool>(node, true));
            }
            
            iterator                insert(iterator position, \
                                           const value_type &val)
            {
                node_type       *node;
                value_compare   comp = this->value_comp();
                int             dir;
                
                // Compare the value with hint and prev(hint)
                if (comp(*position, val) && comp(val, *(++position)))
                {
                    dir = comp(*position, val);
                    node = this->_tree.get_allocator().allocate(1);
                    this->_tree.get_allocator().construct(node, val);
                    this->_tree.insert(node, position._p, dir);
                    ++this->_size;
                    return (iterator(node));
                }
                // Insert as usual
                return (this->insert(val).first);
            }

            template<class InputIterator>
            void                    insert(InputIterator first, \
                                           InputIterator last)
            {
                while (first != last)
                {
                    this->insert(*first);
                    ++first;
                }
            }
 
            void                    erase(iterator position)
            {
                if (position._p != NULL)
                {
                    this->_tree.erase(position);
                    --this->_size;
                }
            }

            size_type               erase(const key_type &k)
            {
                if (this->_tree.erase(k) == 1)
                {
                    --this->_size;
                    return (1);
                }
                return (0);
            }

            void                    erase(iterator first, iterator last)
            {
                iterator    next;
                
                while (first != last)
                {
                    next = first._p->successor();
                    this->_tree.erase(first);
                    first = next;
                }
            }

            void                    swap(set &x)
            {
                this->_tree.swap(x._tree);
                std::swap(this->_size, x._size);
            }
            
            void                    clear(void)
            {
                this->_tree.clear();
                this->_size = 0;
            }
            
            // Allocator
            allocator_type              get_allocator(void) const
            { return allocator_type(this->_allocator); }
            
            // Observers
            key_compare                 key_comp(void) const
            { return this->_compare; }

            value_compare               value_comp(void) const
            { return value_compare(key_compare()); }
            
            // Operations
            iterator                    find(const key_type &k)
            { return (iterator(this->_tree.search(k))); }

            const_iterator              find(const key_type &k) const
            { return (const_iterator(this->_tree.search(k))); }
            
            size_type                   count(const key_type &k) const
            { return ((this->_tree.search(k) 
                       == this->_tree.get_end()) ? 0 : 1); }
            
            iterator                    lower_bound(const key_type &k)
            { return (this->_tree.get_lower_bound(k)); }
            
            const_iterator              lower_bound(const key_type &k) const
            { return (const_cast<iterator>(this->_tree.get_lower_bound(k))); }

            iterator                    upper_bound(const key_type &k)
            { return (this->_tree.get_upper_bound(k)); }
            
            const_iterator              upper_bound(const key_type &k) const
            { return (const_cast<iterator>(this->_tree.get_upper_bound(k))); }

            pair<iterator, iterator>    equal_range(const key_type &k)
            {
               return (pair<iterator, iterator>(this->lower_bound(k), \
                                                this->upper_bound(k)));
            }

            pair<const_iterator, const_iterator>    equal_range(\
                                                     const key_type &k) const
            {
               return (pair<const_iterator, const_iterator>(\
                       this->lower_bound(k), this->upper_bound(k)));
            }

        private:
            // Attributes
            tree_type       _tree;
            allocator_type  _allocator;
            key_compare     _compare;
            size_type       _size;
    };
}

#endif
