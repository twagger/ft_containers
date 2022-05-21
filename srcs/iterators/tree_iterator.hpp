/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/05/21 13:30:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace   ft
{
    template < class T >
    class t_iterator 
    {
        public:
            /* ************************************************************** */
            /*  MEMBER TYPES & ALIASES                                        */
            /* ************************************************************** */
            typedef typename ft::iterator_traits<T*>::difference_type \
                difference_type;
            typedef typename ft::iterator_traits<T*>::value_type      \
                value_type;
            typedef typename ft::iterator_traits<T*>::pointer         \
                pointer;
            typedef typename ft::iterator_traits<T*>::reference       \
                reference;
            typedef std::bidirectional_iterator_tag         iterator_category;
            
            /* ************************************************************** */
            /*  CONSTRUCTORS & DESTRUCTOR                                     */
            /* ************************************************************** */
            t_iterator(void) : _p(NULL) {}
            t_iterator(pointer x) : _p(x) {}
            t_iterator(const t_iterator &it) : _p(it._p) {}
            ~t_iterator(void) {}
            
            // /* ************************************************************** */
            // /*  OPERATORS OVERLOAD                                            */
            // /* ************************************************************** */
            t_iterator        &operator=(t_iterator const &rhs)
            { this->_p = rhs._p; return (*this);}

            // t_iterator        &operator++(void) {++this->_p;return *this;}
            // iterator        operator++(int)
            // { iterator tmp(*this); ++this->_p; return tmp; }
            // iterator        &operator--(void) {--this->_p;return *this;}
            // iterator        operator--(int)
            // { iterator tmp(*this); --this->_p; return tmp; }

            // bool            operator==(const iterator& rhs) const
            // { return this->_p == rhs._p; }
            // bool            operator!=(const iterator& rhs) const
            // { return this->_p != rhs._p; }

            // reference       operator*(void) {return *(this->_p);}
            // const reference operator*(void) const {return *(this->_p);}
            // pointer         operator->(void) const {return (this->_p);}

            private:
                // member attributes
                pointer _p;
                // Ajouter first et second

            //     // member function
            //     void    increment(void)
            //     {
                                        
            //     }

            //     void    decrement(void)
            //     {
                    
            //     }
    };

    template < class T >
    class t_const_iterator 
    {
        public:
            // member types
            typedef typename ft::iterator_traits<const T *>::difference_type \
                difference_type;
            typedef typename ft::iterator_traits<const T *>::value_type      \
                value_type;
            typedef typename ft::iterator_traits<const T *>::pointer         \
                pointer;
            typedef typename ft::iterator_traits<const T *>::reference      \
                reference;
            typedef typename ft::iterator_traits<const T *>::iterator_category \
                iterator_category;

            // constructors and destructor
            t_const_iterator(void) : _p(NULL) {}
            t_const_iterator(pointer x) : _p(x) {}
            t_const_iterator(const t_const_iterator &it) : _p(it._p) {}
            ~t_const_iterator(void) {}

            // // operators overload  
            // const_iterator  &operator++(void) {++this->_p;return *this;}
            // const_iterator  operator++(int)
            // { const_iterator tmp(*this); ++this->_p; return tmp; }
            // const_iterator  &operator--(void) {--this->_p;return *this;}
            // const_iterator  operator--(int)
            // { const_iterator tmp(*this); --this->_p; return tmp; }

            // bool            operator==(const const_iterator& rhs) const
            // { return this->_p == rhs._p; }
            // bool            operator!=(const const_iterator& rhs) const
            // { return this->_p != rhs._p; }
            // bool            operator<(const const_iterator& rhs) const
            // { return this->_p < rhs._p; }
            // bool            operator<=(const const_iterator& rhs) const
            // { return this->_p <= rhs._p; }
            // bool            operator>(const const_iterator& rhs) const
            // { return this->_p > rhs._p; }
            // bool            operator>=(const const_iterator& rhs) const
            // { return this->_p >= rhs._p; }

            // const_iterator  operator+(const const_iterator& rhs) const
            // { return *(this->_p + rhs._p); }
            // const_iterator  operator+(difference_type n) const
            // { return (this->_p + n); }
            // const_iterator  &operator+=(difference_type n)
            // { this->_p += n; return (*this); }
            // difference_type operator-(const const_iterator& rhs) const
            // { return (this->_p - rhs._p); }
            // const_iterator  operator-(difference_type n) const
            // { return (this->_p - n); }
            // const_iterator  &operator-=(difference_type n)
            // { this->_p -= n; return (*this); }

            // reference       operator*(void) const {return *(this->_p);}
            // pointer         operator->(void) const {return (this->_p);}

            // reference       operator[](difference_type n) const
            // { return *(this->_p + n); }

            // member attributes
            pointer _p;
    };

    template < class Iter >
    class t_reverse_iterator
    {
        public:
            // member types
            typedef Iter    iterator_type;
            typedef typename ft::iterator_traits<Iter>::difference_type \
                difference_type;
            typedef typename ft::iterator_traits<Iter>::value_type      \
                value_type;
            typedef typename ft::iterator_traits<Iter>::pointer         \
                pointer;
            typedef typename ft::iterator_traits<Iter>::reference       \
                reference;
            typedef typename ft::iterator_traits<Iter>::iterator_category   \
                iterator_category;

            // constructors and destructor
            t_reverse_iterator(void) : current() {}
            explicit t_reverse_iterator(iterator_type	it) : current(it) {}
            t_reverse_iterator(const t_reverse_iterator<Iter> &rev_it)
            : current(rev_it.current) {}

            // // operators overload  
            // reverse_iterator    &operator++(void)
            // { --this->current;return *this; }
            // reverse_iterator    operator++(int)
            // { reverse_iterator tmp(*this); --this->current; return tmp; }
            // reverse_iterator    &operator--(void)
            // { ++this->current;return *this; }
            // reverse_iterator    operator--(int)
            // { reverse_iterator tmp(*this); ++this->current; return tmp; }

            // reverse_iterator    operator+(difference_type n) const
            // { return reverse_iterator(this->current - n); }
            // reverse_iterator    &operator+=(difference_type n)
            // { this->current -= n; return (*this); }
            // reverse_iterator    operator-(difference_type n) const
            // { return reverse_iterator(this->current + n); }
            // reverse_iterator    &operator-=(difference_type n)
            // { this->current += n; return (*this); }

            // reference           operator*(void) const
            // { iterator_type tmp = this->current; return (*--tmp); }
            // pointer             operator->(void) const
            // { iterator_type tmp = this->current; return (--tmp); }

            // reference           operator[](difference_type n) const
            // { return *(*this + n); }

            // // member function
            // iterator_type       base(void) const {return (this->current);}

        protected:
            iterator_type current;

        private:
            // Non member operator overloads
            friend bool operator==(const t_reverse_iterator<Iter>	&lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (lhs.base() == rhs.base()); }

            friend bool operator!=(const t_reverse_iterator<Iter>	&lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (lhs.base() != rhs.base()); }

            friend bool operator<(const t_reverse_iterator<Iter> &lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (rhs.base() > lhs.base()); }

            friend bool operator<=(const t_reverse_iterator<Iter> &lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (rhs.base() >= lhs.base()); }

            friend bool operator>(const t_reverse_iterator<Iter> &lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (rhs.base() < lhs.base()); }

            friend bool operator>=(const t_reverse_iterator<Iter> &lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return (lhs.base() <= rhs.base()); }

            friend t_reverse_iterator<Iter>   operator+(\
                typename t_reverse_iterator<Iter>::difference_type n, \
                const t_reverse_iterator<Iter> &rev_it)
            { return t_reverse_iterator<Iter>(rev_it.base() - n); }

            friend typename t_reverse_iterator<Iter>::difference_type operator-(\
                const t_reverse_iterator<Iter> &lhs, \
                const t_reverse_iterator<Iter> &rhs)
            { return t_reverse_iterator<Iter>(rhs.base() - lhs.base()); }
    };
}

#endif
