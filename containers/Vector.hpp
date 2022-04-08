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
			/* 	MEMBER TYPES                                                  */
			/* ************************************************************** */
			// Memory
			typedef A							allocator_type;
			
			/* ************************************************************** */
			/*  CONSTRUCTORS & DESTRUCTOR                                     */
			/* ************************************************************** */
			// Constructors
			explicit vector(const allocator_type &alloc = allocator_type());
			// Destructor
			~vector(void);

			/* ************************************************************** */
			/* 	OPERATOR OVERLOADS                                            */
			/* ************************************************************** */
			T	&operator[](std::size_t	n);

			/* ************************************************************** */
			/* 	MEMBER FUNCTIONS                                              */
			/* ************************************************************** */
			void	push_back(const T &val);

		private:
			T				*_array;
			allocator_type	_allocator;
			std::size_t		_size;
			std::size_t		_capacity;
	};
}

# include "Vector.tpp"

#endif
