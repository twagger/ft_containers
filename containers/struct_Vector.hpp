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

namespace	ft
{
	template < class T, class A = std::allocator<T> > 
	class vector
	{
		public:
			/* ************************************************************** */
			/*  CONSTRUCTORS & DESTRUCTOR                                     */
			/* ************************************************************** */
			// Constructors
			explicit Vector (const allocator_type &alloc = allocator_type());
			explicit Vector (size_type n, const value_type &val = value_type(), \
				const allocator_type &alloc = allocator_type());
			template <class InputIterator>
			Vector (InputIterator first, InputIterator last, \
				const allocator_type& alloc = allocator_type());
			Vector (const Vector &x);
			// Destructor
			~Vector();

			/* ************************************************************** */
			/* 	MEMBER TYPES                                                  */
			/* ************************************************************** */
			// Data
			typedef typename A::value_type			value_type;
			// Memory
			typedef typename A						allocator_type;
			typedef typename A::reference			reference;
			typedef typename A::const_reference		const_reference;
			typedef typename A::pointer				pointer;
			typedef typename A::const_pointer		const_pointer;
			// Types
			typedef std::size_t						size_type;
			typedef	std::ptrdiff_t					difference_type;
			// Iterators
			class iterator 
			{
				public:
					// constructors
					iterator(T *x) : p(x) {}
					iterator(const iterator &it) : p(it.p) {}

					// operators overload  
					iterator	&operator++(void) {++this->p;return *this;}
					iterator 	operator++(int) {iterator tmp(*this); operator++(); return tmp;}
					iterator	&operator--(void) {--this->p;return *this;}
					iterator 	operator--(int) {iterator tmp(*this); operator--(); return tmp;}
					bool 		operator==(const iterator& rhs) const {return this->p == rhs.p;}
					bool 		operator!=(const iterator& rhs) const {return this->p != rhs.p;}
					T			&operator*(void) {return *(this->p);}
					
					// attributes
					T	*p;
			};
			class const_iterator {};
			class reverse_iterator {};
			class const_reverse_iterator {};


			/* ************************************************************** */
			/* 	OPERATOR OVERLOADS                                            */
			/* ************************************************************** */
			Vector	&operator=(Vector const &rhs);
			Vector	&operator[](Vector const &rhs);
			
			/* ************************************************************** */
			/* 	MEMBER FUNCTIONS                                              */
			/* ************************************************************** */
			// Iterators
			Vector<T>::iterator			end(void) {}
			Vector<T>::iterator			begin(void) {}
			Vector<T>::reverse_iterator	rbegin(void) {}
			Vector<T>::reverse_iterator	rend(void) {}
			// Capacity
			size(void) {}
			max_size(void) {}
			resize(void) {}
			capacity(void) {}
			empty(void) {}
			reserve(void) {}
			// Element access
			at(void) {}
			front(void) {}
			back(void) {}
			// Modifiers
			assign(void) {}
			push_back(void) {}
			pop_back(void) {}
			insert(void) {}
			erase(void) {}
			swap(void) {}
			clear(void) {}
			// Allocator
			get_allocator(void) {}

		private:
			T	*_array;
	};
}

# include "Vector.tpp"

#endif