/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/04/08 11:48:07 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

/* ************************************************************************** */
/*  CONSTRUCTORS & DESTRUCTOR                                                 */
/* ************************************************************************** */
template < class T, class A > 
ft::vector<T,A>::vector(const allocator_type &alloc)
: _allocator(alloc), _size(0), _capacity(0)
{
	this->_array = this->_allocator.allocate(this->_capacity);
}

template < class T, class A > 
ft::vector<T,A>::~vector(void)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
}

/* ************************************************************************** */
/* 	OPERATOR OVERLOADS                                                        */
/* ************************************************************************** */
template < class T, class A > 
T	&ft::vector<T,A>::operator[](std::size_t n)
{
	if (n >= this->_size)
	{
		throw std::out_of_range("Out of range");
	}
	else
	{
		return (this->_array[n]);
	}
}

/* ************************************************************************** */
/* 	MEMBER FUNCTIONS                                                          */
/* ************************************************************************** */
template < class T, class A > 
void	ft::vector<T,A>::push_back(const T &val)
{
	T			*tmp;
	std::size_t	new_capacity;
	
	if (this->_size == this->_capacity)
	{
		new_capacity = this->_capacity * 2;
		if (this->_capacity == 0)
			new_capacity = 1;
		tmp = this->_allocator.allocate(new_capacity);
		for (std::size_t i = 0; i < this->_size; ++i)
		{
			tmp[i] = this->_array[i];
		}
		this->_allocator.deallocate(this->_array, this->_capacity);
		this->_array = tmp;
		this->_capacity = this->_capacity * 2;
	}
	this->_array[this->_size] = val;
	++this->_size;
}
