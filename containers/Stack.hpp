/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:36:12 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 09:50:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "../iterators/iterator.hpp"
# include "Vector.hpp"

namespace	ft
{
	// Stack
	template < class T, class Container = ft::vector<T> > 
	class stack
	{
		public:
            /* ************************************************************** */
			/* 	MEMBER TYPES & ALIASES                                        */
			/* ************************************************************** */
			// Type
			typedef T			value_type;
			// Container
            typedef Container   container_type;
			// Size
			typedef	std::size_t size_type;
			
			/* ************************************************************** */
			/*  CONSTRUCTORS & DESTRUCTOR                                     */
			/* ************************************************************** */
			// Constructors
            explicit stack (const container_type &ctnr = container_type());

            /* ************************************************************** */
			/* 	MEMBER FUNCTIONS                                              */
			/* ************************************************************** */
            bool                empty(void) const;
            size_type           size(void) const;
            value_type          &top(void) const;
            const value_type    &top(void) const;
            void                push(const value_type &val);
            void                pop(void);

        private:
			// Attributes
			value_type		*_array;
			allocator_type	_allocator;
			size_type		_size;
			size_type		_capacity;
    }
    /* ********************************************************************** */
	/* 	NON MEMBER FUNCTIONS OVERLOAD                                         */
	/* ********************************************************************** */
	// Non member function overloads
	template <class T, class A>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	template <class T, class A>
}

#endif
