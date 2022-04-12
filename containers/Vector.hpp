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
			typedef T			value_type;
			// Memory
			typedef A			allocator_type;
			// Size
			typedef	std::size_t	size_type;
			// Iterators
			class iterator : public std::iterator<std::random_access_iterator_tag, T> 
			{
				public:
					// constructors and destructor
					iterator(void) : p(NULL) {}
					iterator(T *x) : p(x) {}
					iterator(const iterator &it) : p(it.p) {}

					// operators overload  
					iterator	&operator++(void) {++this->p;return *this;}
					iterator 	operator++(int) {iterator tmp(*this); operator++(); return tmp;}
					iterator	&operator--(void) {--this->p;return *this;}
					iterator 	operator--(int) {iterator tmp(*this); operator--(); return tmp;}
					bool 		operator==(const iterator& rhs) const {return this->p == rhs.p;}
					bool 		operator!=(const iterator& rhs) const {return this->p != rhs.p;}
					bool 		operator<(const iterator& rhs) const {return this->p < rhs.p;}
					bool 		operator<=(const iterator& rhs) const {return this->p <= rhs.p;}
					bool 		operator>(const iterator& rhs) const {return this->p > rhs.p;}
					bool 		operator>=(const iterator& rhs) const {return this->p >= rhs.p;}
					T			&operator*(void) {return *(this->p);}
					const T		&operator*(void) const {return *(this->p);}
					ptrdiff_t	operator-(const iterator& rhs) const {return (this->p - rhs.p);}
					
					// attributes
					T	*p;
			};
			class const_iterator : public std::iterator<std::random_access_iterator_tag, T> 
			{
				public:
					// constructors and destructor
					const_iterator(void) : p(NULL) {}
					const_iterator(T *x) : p(x) {}
					const_iterator(const const_iterator &it) : p(it.p) {}

					// operators overload  
					const_iterator	&operator++(void) {++this->p;return *this;}
					const_iterator 	operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
					const_iterator	&operator--(void) {--this->p;return *this;}
					const_iterator 	operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
					bool 			operator==(const const_iterator& rhs) const {return this->p == rhs.p;}
					bool 			operator!=(const const_iterator& rhs) const {return this->p != rhs.p;}
					bool 			operator<(const const_iterator& rhs) const {return this->p < rhs.p;}
					bool 			operator<=(const const_iterator& rhs) const {return this->p <= rhs.p;}
					bool 			operator>(const const_iterator& rhs) const {return this->p > rhs.p;}
					bool 			operator>=(const const_iterator& rhs) const {return this->p >= rhs.p;}
					const T			&operator*(void) const {return *(this->p);}
					ptrdiff_t		operator-(const const_iterator& rhs) const {return (this->p - rhs.p);}
					
					// attributes
					T	*p;
			};

			/* ************************************************************** */
			/*  CONSTRUCTORS & DESTRUCTOR                                     */
			/* ************************************************************** */
			// Constructors
			explicit vector(const allocator_type &alloc = allocator_type());
			vector(const vector	&x);
			// Destructor
			~vector(void);

			/* ************************************************************** */
			/* 	OPERATOR OVERLOADS                                            */
			/* ************************************************************** */
			T	&operator[](std::size_t	n);

			/* ************************************************************** */
			/* 	MEMBER FUNCTIONS                                              */
			/* ************************************************************** */
			// Modifier
			void			push_back(const T &val);
			// Allocator
			allocator_type	get_allocator() const {return (this->_allocator);};
			// Capacity
			size_type		size(void) const {return (this->_size);};
			size_type		capacity(void) const {return (this->_capacity);};
			// Iterators
			iterator		begin(void) {return (this->_array);};
			iterator		end(void) {return (this->_array + this->_size);};
			const_iterator	begin(void) const {return (this->_array);};
			const_iterator	end(void) const {return (this->_array + this->_size);};

		private:
			value_type		*_array;
			allocator_type	_allocator;
			std::size_t		_size;
			std::size_t		_capacity;
	};
}

# include "Vector.tpp"

#endif
