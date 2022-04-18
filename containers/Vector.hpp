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

namespace	ft
{
	template < class T, class A = std::allocator<T> > 
	class vector
	{
		public:
			/* ************************************************************** */
			/* 	MEMBER TYPES & ALIASES                                        */
			/* ************************************************************** */
			// Type
			typedef T											value_type;
			// Memory
			typedef A											allocator_type;
			// Size
			typedef	std::size_t									size_type;
			// Difference
			typedef	ptrdiff_t									difference_type;
			// References and pointers
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			// Iterators
			typedef ft::iterator<T>								iterator;
			typedef ft::const_iterator<T>						const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			/* ************************************************************** */
			/*  CONSTRUCTORS & DESTRUCTOR                                     */
			/* ************************************************************** */
			// Constructors
			explicit vector(const allocator_type &alloc = allocator_type());
			explicit vector(size_type n, const value_type &val = value_type(), 
				const allocator_type &alloc = allocator_type());
			vector(const vector	&x);
			// Destructor
			~vector(void);

			/* ************************************************************** */
			/* 	OPERATOR OVERLOADS                                            */
			/* ************************************************************** */
			T		&operator[](std::size_t	n);
			vector	&operator=(const vector& x);

			/* ************************************************************** */
			/* 	MEMBER FUNCTIONS                                              */
			/* ************************************************************** */
			// Iterators - OK
			iterator				begin(void) {return iterator(this->_array);}
			iterator				end(void) {return iterator(this->_array + this->_size);}
			const_iterator			begin(void) const {return const_iterator(this->_array);}
			const_iterator			end(void) const {return const_iterator(this->_array + this->_size);}
			reverse_iterator		rbegin(void) {return reverse_iterator(this->end());}
			const_reverse_iterator	rbegin(void) const {return const_reverse_iterator(this->end());}
			reverse_iterator		rend(void) {return reverse_iterator(this->begin());}
			const_reverse_iterator	rend(void) const {return const_reverse_iterator(this->begin());}
			// Capacity
			size_type		size(void) const {return (this->_size);}
			size_type		max_size(void) const {return (this->_allocator.max_size());}
			void			resize(size_type n, value_type val = value_type()); // TPP
			size_type		capacity(void) const {return (this->_capacity);}
			bool			empty(void) const {return (this->_size > 0);}
			void			reserve(size_type n); // TPP - OK
			// Access - OK
			reference		at(size_type n) {return ((*this)[n]);};
			const_reference at(size_type n) const {return ((*this)[n]);};
			reference 		front(void) {return ((*this)[0]);};
			const_reference front(void) const {return ((*this)[0]);};
			reference 		back(void) {return ((*this)[this->size() - 1]);};
			const_reference back(void) const {return ((*this)[this->size() - 1]);};
			// Modifiers
			template< class InputIterator >
  			void 			assign (InputIterator first, InputIterator last); // TPP
			void 			assign (size_type n, const value_type &val); // TPP
			void			push_back(const T &val); // TPP - OK
			void			pop_back(void) {if (this->_size > 0){this->get_allocator().destroy(&(*this)[this->size() - 1]);--this->_size;}};
			iterator		insert(iterator position, const value_type &val); // TPP
			void 			insert(iterator position, size_type n, const value_type	&val); // TPP
			template< class InputIterator >
		    void			insert(iterator position, InputIterator first, InputIterator last); // TPP
			iterator		erase(iterator position); // TPP
			iterator		erase(iterator first, iterator last); // TPP
			void			swap(vector &x); // TPP
			void			clear(void); // TPP - OK
			// Allocator - OK
			allocator_type	get_allocator() const {return allocator_type(this->_allocator);}

		private:
			// Attributes - OK
			value_type		*_array;
			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
	};
	/* ********************************************************************** */
	/* 	NON MEMBER FUNCTIONS OVERLOAD                                         */
	/* ********************************************************************** */
	// Non member function overloads
	template <class T, class A>
	bool operator==(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	bool operator!=(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	bool operator<(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	bool operator<=(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	bool operator>(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	bool operator>=(const vector<T,A> &lhs, const vector<T,A> &rhs);
	template <class T, class A>
	void swap(vector<T,A> &x, vector<T,A> &y);
}

# include "Vector.tpp"

#endif
