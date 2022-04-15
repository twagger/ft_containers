/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:50:15 by twagner           #+#    #+#             */
/*   Updated: 2022/04/15 17:31:56 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "iterator_traits.hpp"

namespace	ft
{
	template < class T >
	class iterator : public std::iterator<std::random_access_iterator_tag, T> 
	{
		public:
			// member types
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T*>::value_type		value_type;
			typedef typename ft::iterator_traits<T*>::pointer			pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;

			// constructors and destructor
			iterator(void) : _p(NULL) {}
			iterator(pointer x) : _p(x) {}
			iterator(const iterator &it) : _p(it._p) {}
			~iterator(void) {}

			// operators overload  
			iterator		&operator++(void) {++this->_p;return *this;}
			iterator 		operator++(int) {iterator tmp(*this); ++this->_p; return tmp;}
			iterator		&operator--(void) {--this->_p;return *this;}
			iterator 		operator--(int) {iterator tmp(*this); --this->_p; return tmp;}

			bool 			operator==(const iterator& rhs) const {return this->_p == rhs._p;}
			bool 			operator!=(const iterator& rhs) const {return this->_p != rhs._p;}
			bool 			operator<(const iterator& rhs) const {return this->_p < rhs._p;}
			bool 			operator<=(const iterator& rhs) const {return this->_p <= rhs._p;}
			bool 			operator>(const iterator& rhs) const {return this->_p > rhs._p;}
			bool 			operator>=(const iterator& rhs) const {return this->_p >= rhs._p;}

			iterator		operator+(const iterator& rhs) const {return (this->_p + rhs._p);}
			iterator		operator+(difference_type n) const {return (this->_p + n);}
			iterator		&operator+=(difference_type n) {this->_p += n; return (*this);}
			difference_type	operator-(const iterator& rhs) const {return (this->_p - rhs._p);}
			iterator		operator-(difference_type n) const {return (this->_p - n);}
			iterator		&operator-=(difference_type n) {this->_p -= n; return (*this);}

			reference		operator*(void) {return *(this->_p);}
			const reference	operator*(void) const {return *(this->_p);}
			pointer			operator->(void) const {return (this->_p);}

			reference		operator[](difference_type n) const {return *(this->_p + n);}

			// member attributes
			pointer	_p;
	};

	template < class T >
	class const_iterator : public std::iterator<std::random_access_iterator_tag, T> 
	{
		public:
			// member types
			typedef typename ft::iterator_traits<const T *>::difference_type	difference_type;
			typedef typename ft::iterator_traits<const T *>::value_type			value_type;
			typedef typename ft::iterator_traits<const T *>::pointer			pointer;
			typedef typename ft::iterator_traits<const T *>::reference			reference;
			typedef typename ft::iterator_traits<const T *>::iterator_category	iterator_category;

			// constructors and destructor
			const_iterator(void) : _p(NULL) {}
			const_iterator(pointer x) : _p(x) {}
			const_iterator(const const_iterator &it) : _p(it._p) {}
			~const_iterator(void) {}

			// operators overload  
			const_iterator	&operator++(void) {++this->_p;return *this;}
			const_iterator 	operator++(int) {const_iterator tmp(*this); ++this->_p; return tmp;}
			const_iterator	&operator--(void) {--this->_p;return *this;}
			const_iterator 	operator--(int) {const_iterator tmp(*this); --this->_p; return tmp;}

			bool 			operator==(const const_iterator& rhs) const {return this->_p == rhs._p;}
			bool 			operator!=(const const_iterator& rhs) const {return this->_p != rhs._p;}
			bool 			operator<(const const_iterator& rhs) const {return this->_p < rhs._p;}
			bool 			operator<=(const const_iterator& rhs) const {return this->_p <= rhs._p;}
			bool 			operator>(const const_iterator& rhs) const {return this->_p > rhs._p;}
			bool 			operator>=(const const_iterator& rhs) const {return this->_p >= rhs._p;}

			const_iterator	operator+(const const_iterator& rhs) const {return *(this->_p + rhs._p);}
			const_iterator	operator+(difference_type n) const {return *(this->_p + n);}
			const_iterator	&operator+=(difference_type n) {this->_p += n; return (*this);}
			difference_type	operator-(const const_iterator& rhs) const {return (this->_p - rhs._p);}
			const_iterator	operator-(difference_type n) const {return (this->_p - n);}
			const_iterator	&operator-=(difference_type n) {this->_p -= n; return (*this);}

			reference		operator*(void) const {return *(this->_p);}
			pointer			operator->(void) const {return (this->_p);}

			reference		operator[](difference_type n) const {return *(this->_p + n);}

			// member attributes
			pointer	_p;
	};

	template < class Iter >
	class reverse_iterator
	{
		public:
			// member types
			typedef	Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

			// constructors and destructor
			reverse_iterator(void) : current() {}
			explicit reverse_iterator(iterator_type	it) : current(it) {}
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : current(rev_it.current) {}

			// operators overload  
			reverse_iterator	&operator++(void) {--this->current;return *this;}
			reverse_iterator 	operator++(int) {reverse_iterator tmp(*this); --this->current; return tmp;}
			reverse_iterator	&operator--(void) {++this->current;return *this;}
			reverse_iterator 	operator--(int) {reverse_iterator tmp(*this); ++this->current; return tmp;}

			reverse_iterator	operator+(difference_type n) const {return reverse_iterator(this->current - n);}
			reverse_iterator	&operator+=(difference_type n) {this->current -= n; return (*this);}
			reverse_iterator	operator-(difference_type n) const {return reverse_iterator(this->current + n);}
			reverse_iterator	&operator-=(difference_type n) {this->current += n; return (*this);}

			reference			operator*(void) const {iterator_type tmp = this->current; return (*--tmp);}
			pointer				operator->(void) const {iterator_type tmp = this->current; return (--tmp);}

			reference			operator[](difference_type n) const {return *(*this + n);}

			// member function
			iterator_type	base(void) const {return (this->current);}

		protected:
			iterator_type current;
	};
	// Non member operator overloads
	template< class Iter >
	bool	operator==(const reverse_iterator<Iter>	&lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() == rhs.base());}

	template< class Iter >
	bool	operator!=(const reverse_iterator<Iter>	&lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() != rhs.base());}

	template< class Iter >
  	bool	operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (rhs.base() > lhs.base());}

	template< class Iter >
	bool	operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (rhs.base() >= lhs.base());}
	
	template< class Iter >
	bool	operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (rhs.base() < lhs.base());}

	template< class Iter >
	bool	operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
	{return (lhs.base() <= rhs.base());}

	template< class Iter >
  	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
		const reverse_iterator<Iter> &rev_it)
	{return reverse_iterator<Iter>(rev_it.base() - n);}

	template< class Iter >
 	typename reverse_iterator<Iter>::difference_type	operator-(const reverse_iterator<Iter> &lhs,
		const reverse_iterator<Iter> &rhs)
	{return reverse_iterator<Iter>(rhs.base() - lhs.base());}
}

#endif
