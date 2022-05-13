/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:00:14 by twagner           #+#    #+#             */
/*   Updated: 2022/03/27 23:21:19 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstddef>
# include "../iterators/iterator.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace   ft
{
    template < class T, class A = std::allocator<T> > 
    class vector
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            // Type
            typedef T                                           value_type;
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
            typedef ft::iterator<T>                             iterator;
            typedef ft::const_iterator<T>                       const_iterator;
            typedef ft::reverse_iterator<iterator>             reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            // Constructors
            explicit vector(const allocator_type &alloc = allocator_type());
            explicit vector(size_type n, const value_type &val = value_type(), 
                            const allocator_type &alloc = allocator_type());
            
            template <class InputIterator>
            vector(\
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, \
                InputIterator>::type first, InputIterator last, \
                const allocator_type& alloc = allocator_type());

            vector(const vector &x);
            // Destructor
            ~vector(void);

            /* ************************************************************** */
            /*  OPERATOR OVERLOADS                                            */
            /* ************************************************************** */
            value_type  &operator[](size_type n);
            vector      &operator=(const vector& x);

            /* ************************************************************** */
            /*  MEMBER FUNCTIONS                                              */
            /* ************************************************************** */
            // Iterators
            iterator                begin(void)
            { return iterator(this->_array); }

            iterator                end(void)
            { return iterator(this->_array + this->_size); }

            const_iterator          begin(void) const
            { return const_iterator(this->_array); }

            const_iterator          end(void) const
            { return const_iterator(this->_array + this->_size); }

            reverse_iterator        rbegin(void)
            { return reverse_iterator(this->end()); }

            const_reverse_iterator  rbegin(void) const
            { return const_reverse_iterator(this->end()); }

            reverse_iterator        rend(void)
            { return reverse_iterator(this->begin()); }

            const_reverse_iterator  rend(void) const
            { return const_reverse_iterator(this->begin()); }

            // Capacity
            size_type   size(void) const {return (this->_size);}
            size_type   max_size(void) const
            { return (this->_allocator.max_size()); }

            void        resize(size_type n, value_type val = value_type());
            size_type   capacity(void) const {return (this->_capacity);}
            bool        empty(void) const {return (this->_size > 0);}
            void        reserve(size_type n);

            // Access
            reference       at(size_type n) {return ((*this)[n]);}
            const_reference at(size_type n) const {return ((*this)[n]);}
            reference       front(void) {return ((*this)[0]);}
            const_reference front(void) const {return ((*this)[0]);}
            reference       back(void) {return ((*this)[this->size() - 1]);}
            const_reference back(void) const
            { return ((*this)[this->size() - 1]); }

            // Modifiers
            void        assign(size_type n, const value_type &val);
            template< class InputIterator >
            void        assign(\
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, \
                InputIterator>::type first, InputIterator last);

            iterator    insert(iterator position, const value_type &val);
            void        insert(iterator position, size_type n, \
                               const value_type &val);
            template< class InputIterator >
            void        insert(iterator position, \
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, \
                InputIterator>::type first, InputIterator last);

            void        push_back(const T &val);
            void        pop_back(void);
            iterator    erase(iterator position);
            iterator    erase(iterator first, iterator last);
            void        swap(vector &x);
            void        clear(void);

            // Allocator
            allocator_type  get_allocator(void) const
            { return allocator_type(this->_allocator); }

        private:
            // Attributes
            pointer         _array;
            allocator_type  _allocator;
            size_type       _size;
            size_type       _capacity;

            // Functions
            pointer _realloc(size_type n);

            // Non member function overloads
            friend bool operator==(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
                }
                return (false);
            }

            friend bool operator!=(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            { return (!(lhs == rhs)); }

            friend bool operator<(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), \
                                                rhs.begin(), rhs.end())); } 

            friend bool operator<=(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            { return (!(rhs < lhs)); }

            friend bool operator>(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            { return (rhs < lhs); }

            friend bool operator>=(\
            const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
            { return (!(lhs < rhs)); }

            friend void swap(ft::vector<T,A> &x, ft::vector<T,A> &y)
            {
                typename ft::vector<T,A>::pointer         tmp_arr;
                typename ft::vector<T,A>::allocator_type  tmp_alloc;
                typename ft::vector<T,A>::size_type       tmp_size;
                typename ft::vector<T,A>::size_type       tmp_capacity;

                tmp_arr = x._array;
                tmp_size = x.size();
                tmp_capacity = x.capacity();
                tmp_alloc = x.get_allocator();
                x._array = y._array;
                x._size = y.size();
                x._capacity = y.capacity();
                x._allocator = y.get_allocator();
                y._array = tmp_arr;
                y._size = tmp_size;
                y._capacity = tmp_capacity;
                y._allocator = tmp_alloc;
            }
    };
}

# include "Vector.tpp"

#endif
