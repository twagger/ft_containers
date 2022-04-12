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
			iterator		begin(void) {return iterator(this->_array);};
			iterator		end(void) {return iterator(this->_array + this->_size);};
			const_iterator	begin(void) const {return const_iterator(this->_array);};
			const_iterator	end(void) const {return const_iterator(this->_array + this->_size);};

		private:
			value_type		*_array;
			allocator_type	_allocator;
			std::size_t		_size;
			std::size_t		_capacity;
			value_type		*_begin;
			value_type		*_end;
	};
}

# include "Vector.tpp"

#endif
