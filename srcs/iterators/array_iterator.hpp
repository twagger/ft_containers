/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/05/27 13:50:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_ITERATOR_HPP
# define ARRAY_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace   ft
{
    template < class T >
    class iterator 
    {
        public:
            // member types
            typedef typename ft::iterator_traits<T*>::difference_type          \
                             difference_type;
            typedef typename ft::iterator_traits<T*>::value_type               \
                             value_type;
            typedef typename ft::iterator_traits<T*>::pointer                  \
                             pointer;
            typedef typename ft::iterator_traits<T*>::reference                \
                             reference;
            typedef typename ft::iterator_traits<T*>::iterator_category        \
                             iterator_category;

            // constructors and destructor
            iterator(void) : _p(NULL) {}
            iterator(pointer x) : _p(x) {}
            iterator(const iterator &it) : _p(it._p) {}
            ~iterator(void) {}

            // operators overload  
            iterator        &operator=(iterator const &rhs)
            { this->_p = rhs._p; return *this;}

            iterator        &operator++(void) {++this->_p;return *this;}
            iterator        operator++(int)
            { iterator tmp(*this); ++this->_p; return tmp; }
            iterator        &operator--(void) {--this->_p;return *this;}
            iterator        operator--(int)
            { iterator tmp(*this); --this->_p; return tmp; }

            bool            operator==(const iterator& rhs) const
            { return this->_p == rhs._p; }
            bool            operator!=(const iterator& rhs) const
            { return this->_p != rhs._p; }
            bool            operator<(const iterator& rhs) const
            { return this->_p < rhs._p; }
            bool            operator<=(const iterator& rhs) const
            { return this->_p <= rhs._p; }
            bool            operator>(const iterator& rhs) const
            { return this->_p > rhs._p; }
            bool            operator>=(const iterator& rhs) const
            { return this->_p >= rhs._p; }

            iterator        operator+(const iterator& rhs) const
            { return (this->_p + rhs._p); }
            iterator        operator+(difference_type n) const
            { return (this->_p + n); }
            iterator        &operator+=(difference_type n)
            { this->_p += n; return (*this); }
            difference_type operator-(const iterator& rhs) const
            { return (this->_p - rhs._p); }
            iterator        operator-(difference_type n) const
            { return (this->_p - n); }
            iterator        &operator-=(difference_type n)
            { this->_p -= n; return (*this); }

            reference       operator*(void) {return *(this->_p);}
            const reference operator*(void) const {return *(this->_p);}
            pointer         operator->(void) const {return (this->_p);}

            reference       operator[](difference_type n) const
            { return *(this->_p + n); }

            // member attributes
            pointer _p;
    };

    template < class T >
    class const_iterator
    {
        public:
            // member types
            typedef typename ft::iterator_traits<const T *>::difference_type   \
                             difference_type;
            typedef typename ft::iterator_traits<const T *>::value_type        \
                             value_type;
            typedef typename ft::iterator_traits<const T *>::pointer           \
                             pointer;
            typedef typename ft::iterator_traits<const T *>::reference         \
                             reference;
            typedef typename ft::iterator_traits<const T *>::iterator_category \
                             iterator_category;

            // constructors and destructor
            const_iterator(void) : _p(NULL) {}
            const_iterator(pointer x) : _p(x) {}
            const_iterator(const const_iterator &it) : _p(it._p) {}
            ~const_iterator(void) {}

            // operators overload  
            const_iterator  &operator++(void) {++this->_p;return *this;}
            const_iterator  operator++(int)
            { const_iterator tmp(*this); ++this->_p; return tmp; }
            const_iterator  &operator--(void) {--this->_p;return *this;}
            const_iterator  operator--(int)
            { const_iterator tmp(*this); --this->_p; return tmp; }

            bool            operator==(const const_iterator& rhs) const
            { return this->_p == rhs._p; }
            bool            operator!=(const const_iterator& rhs) const
            { return this->_p != rhs._p; }
            bool            operator<(const const_iterator& rhs) const
            { return this->_p < rhs._p; }
            bool            operator<=(const const_iterator& rhs) const
            { return this->_p <= rhs._p; }
            bool            operator>(const const_iterator& rhs) const
            { return this->_p > rhs._p; }
            bool            operator>=(const const_iterator& rhs) const
            { return this->_p >= rhs._p; }

            const_iterator  operator+(const const_iterator& rhs) const
            { return *(this->_p + rhs._p); }
            const_iterator  operator+(difference_type n) const
            { return (this->_p + n); }
            const_iterator  &operator+=(difference_type n)
            { this->_p += n; return (*this); }
            difference_type operator-(const const_iterator& rhs) const
            { return (this->_p - rhs._p); }
            const_iterator  operator-(difference_type n) const
            { return (this->_p - n); }
            const_iterator  &operator-=(difference_type n)
            { this->_p -= n; return (*this); }

            const reference operator*(void) const {return *(this->_p);}
            pointer         operator->(void) const {return (this->_p);}

            reference       operator[](difference_type n) const
            { return *(this->_p + n); }

            // member attributes
            pointer _p;
    };
}

#endif
