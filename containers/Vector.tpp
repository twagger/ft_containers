/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/04/17 15:03:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <algorithm>
#include <exception>

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
ft::vector<T,A>::vector(size_type n, const value_type &val, const allocator_type &alloc)
: _allocator(alloc), _size(n), _capacity(n)
{
	this->_array = this->_allocator.allocate(this->_capacity);
	std::fill(this->begin(), this->end(), val);
}

template < class T, class A > 
ft::vector<T,A>::vector(const vector &x)
: _allocator(x.get_allocator()), _size(x.size()), _capacity(x.capacity())
{
	this->_array = this->_allocator.allocate(this->_capacity);
	std::copy(x.begin(), x.end(), this->begin());
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

template < class T, class A > 
ft::vector<T,A>	&ft::vector<T,A>::operator=(const ft::vector<T,A> &x)
{
	for (ft::vector<T,A>::const_iterator it = this->begin(); it < this->end(); ++it)
	{
		this->_allocator.destroy(it);
	}
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_capacity = x.capacity();
	this->_size = x.size();
	this->_array = this->_allocator.allocate(this->_capacity);
	std::copy(x.begin(), x.end(), this->begin());
}

/* ************************************************************************** */
/* 	MEMBER FUNCTIONS                                                          */
/* ************************************************************************** */
// Capacity
/*
template < class T, class A > 
void	ft::vector<T,A>::resize(size_type n, value_type val)
{
	if (n > this->_size)
	{
		//defaut_append(n - this->_size, val)
	}
	else
	{
		std::for_each(this->begin() + n, this->end(), this->_allocator.destroy);
		this->_allocator.deallocate(this->_array + n, this->end() - n);
		this->_size = n;
	}
}
*/
template < class T, class A > 
void	ft::vector<T,A>::reserve(size_type n)
{
	pointer	tmp;

	if (n > this->max_size())
		throw std::length_error("lenght error");
	if (n > this->capacity())
	{
		tmp = this->get_allocator().allocate(n);
		std::copy(this->begin(), this->end(), tmp);
		for (int i = 0; i < this->size(); ++i)
			this->get_allocator().destroy(this->_array + i);
		this->get_allocator().deallocate(this->_array, this->capacity());
		this->_array = tmp;
		this->_capacity = n;
	}
}

// Modifiers
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

