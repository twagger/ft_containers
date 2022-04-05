/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/04/05 16:42:26 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

/* ************************************************************************** */
/*  CONSTRUCTORS & DESTRUCTOR                                                 */
/* ************************************************************************** */
template < class T > 
ft::vector<T>::vector(void) : _size(0), _capacity(1)
{
	this->_array = new T(1);
}

template < class T > 
ft::vector<T>::~vector(void)
{
	delete [] this->_array;
}

/* ************************************************************************** */
/* 	OPERATOR OVERLOADS                                                        */
/* ************************************************************************** */
template < class T > 
T	&ft::vector<T>::operator[](std::size_t n)
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
template < class T > 
void	ft::vector<T>::push_back(const T &val)
{
	T	*tmp;
	
	if (this->_size == this->_capacity)
	{
		tmp = new T(this->_capacity * 2);
		for (std::size_t i = 0; i < this->_size; ++i)
		{
			tmp[i] = this->_array[i];
		}
		delete [] this->_array;
		this->_array = tmp;
		this->_capacity = this->_capacity * 2;
	}
	this->_array[this->_size] = val;
	++this->_size;
}
