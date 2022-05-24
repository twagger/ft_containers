/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:27:08 by twagner           #+#    #+#             */
/*   Updated: 2022/05/24 10:49:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../iterators/tree_iterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/RBTree.hpp"

namespace   ft
{
    template < class Key, class T, class Compare = std::less<Key>, \
            class A = std::allocator<pair<const Key, T>> >
    class map
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const key_type, mapped_type>           value_type;
            // Compare
            typedef Compare                                     key_compare;
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
            typedef t_iterator<RBNode<Key, T, Compare>>         iterator;

            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Default
            explicit map(const key_compare &comp = key_compare(), \
                        const allocator_type &alloc = allocator_type())
            : _tree(new RBTree<key_type, mapped_type, key_compare>()), \
              _allocator(alloc), _size(0), _capacity(0), _compare(comp) {}
            // Range
            // template <class InputIterator>
            // map(InputIterator first, InputIterator last, \
            //     const key_compare& comp = key_compare(), \
            //     const allocator_type& alloc = allocator_type());
            // // Copy
            // map(const map &x);
            // Destructor
            ~map(void);

            /* ************************************************************** */
            /*  OPERATOR OVERLOADS                                            */
            /* ************************************************************** */
            // mapped_type &operator[](const key_type &k);
            // map         &operator=(const map &x);

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Iterators
            iterator                begin(void)
            { return iterator(this->_tree->get_root()); }
            // iterator                end(void) {}
            // const_iterator          begin(void) const;
            // const_iterator          end(void) const;
            // reverse_iterator        rbegin(void);
            // const_reverse_iterator  rbegin(void) const;
            // reverse_iterator        rend(void);
            // const_reverse_iterator  rend(void) const;
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
                iterator    it;

                it = this->_tree->search(this->_tree->get_root(), val.first);
                if (it == NULL)
                {
                    it = this->_tree->insert(val);
                    return (pair<iterator, bool>(it, true));
                }
                return (pair<iterator, bool>(it, false));
            }
            // iterator                insert(iterator position, \
            //                             const value_type &val);
            // template<class InputIterator>
            // void                    insert(InputIterator first, \
            //                             InputIterator last); 
            // void                    erase(iterator position);
            // size_type               erase(const key_type &k);
            // void                    erase(iterator first, iterator last);
            // void                    swap(map &x);
            // void                    clear(void);
            // Allocator
            allocator_type              get_allocator(void) const
            { return allocator_type(this->_allocator); }
            // Observers
            // key_compare                 key_comp(void) const;
            //value_compare   value_comp(void) const;
            // Operations
            // iterator                    find(const key_type &k);
            // const_iterator              find(const key_type &k) const;
            // size_type                   count(const key_type &k) const;
            // iterator                    lower_bound(const key_type &k);
            // const_iterator              lower_bound(const key_type &k) const;
            // iterator                    upper_bound(const key_type &k);
            // const_iterator              upper_bound(const key_type &k) const;
            // pair<iterator, iterator>    equal_range(const key_type &k);
            // pair<const_iterator, const_iterator>    equal_range(\
            //                                         const key_type &k) const;

        private:
            // Attributes
            RBTree<key_type, mapped_type, Compare>  *_tree;
            key_compare                             _compare;
            allocator_type                          _allocator;
            size_type                               _size;
            size_type                               _capacity;
    };
}

#endif
