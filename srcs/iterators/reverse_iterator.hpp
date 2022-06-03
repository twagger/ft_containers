/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:39:13 by marvin            #+#    #+#             */
/*   Updated: 2022/06/03 10:40:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace   ft
{
    template < class Iter >
    class reverse_iterator
    {
        public:
            // member types
            typedef Iter    iterator_type;
            typedef typename ft::iterator_traits<Iter>::difference_type        \
                             difference_type;
            typedef typename ft::iterator_traits<Iter>::value_type             \
                             value_type;
            typedef typename ft::iterator_traits<Iter>::pointer                \
                             pointer;
            typedef typename ft::iterator_traits<Iter>::reference              \
                             reference;
            typedef typename ft::iterator_traits<Iter>::iterator_category      \
                             iterator_category;

            // constructors and destructor
            reverse_iterator(void) : current() {}
            explicit reverse_iterator(iterator_type	it) : current(it) {}
            reverse_iterator(const reverse_iterator<Iter> &rev_it)
            : current(rev_it.current) {}

            // operators overload  
            reverse_iterator    &operator=(reverse_iterator const &rhs)
            { this->current = rhs.current; return (*this);}
            
            reverse_iterator    &operator++(void)
            { --this->current; return *this; }
            reverse_iterator    operator++(int)
            { reverse_iterator tmp(*this); --this->current; return tmp; }
            reverse_iterator    &operator--(void)
            { ++this->current; return *this; }
            reverse_iterator    operator--(int)
            { reverse_iterator tmp(*this); ++this->current; return tmp; }

            reverse_iterator    operator+(difference_type n) const
            { return reverse_iterator(this->current - n); }
            reverse_iterator    &operator+=(difference_type n)
            { this->current -= n; return (*this); }
            reverse_iterator    operator-(difference_type n) const
            { return reverse_iterator(this->current + n); }
            reverse_iterator    &operator-=(difference_type n)
            { this->current += n; return (*this); }

            reference           operator*(void) const
            { iterator_type tmp = this->current; return (*--tmp); }
            pointer             operator->(void) const
            { return (&(this->operator*())); }

            reference           operator[](difference_type n) const
            { return *(*this + n); }

            // member function
            iterator_type       base(void) const {return (this->current);}

        protected:
            iterator_type current;

        private:
            // Non member operator overloads
            friend bool operator==(const reverse_iterator<Iter>	&lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (lhs.base() == rhs.base()); }

            friend bool operator!=(const reverse_iterator<Iter>	&lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (lhs.base() != rhs.base()); }

            friend bool operator<(const reverse_iterator<Iter> &lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (rhs.base() > lhs.base()); }

            friend bool operator<=(const reverse_iterator<Iter> &lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (rhs.base() >= lhs.base()); }

            friend bool operator>(const reverse_iterator<Iter> &lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (rhs.base() < lhs.base()); }

            friend bool operator>=(const reverse_iterator<Iter> &lhs, \
                const reverse_iterator<Iter> &rhs)
            { return (lhs.base() <= rhs.base()); }

            friend reverse_iterator<Iter>   operator+(\
                typename reverse_iterator<Iter>::difference_type n, \
                const reverse_iterator<Iter> &rev_it)
            { return reverse_iterator<Iter>(rev_it.base() - n); }

            friend typename reverse_iterator<Iter>::difference_type operator-(\
                const reverse_iterator<Iter> &lhs, \
                const reverse_iterator<Iter> &rhs)
            { return reverse_iterator<Iter>(rhs.base() - lhs.base()); }
    };
}

#endif
