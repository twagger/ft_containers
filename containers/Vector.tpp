/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/04/22 15:05:59 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <algorithm>
#include <exception>

/* ************************************************************************** */
/*  CONSTRUCTORS & DESTRUCTOR                                                 */
/* ************************************************************************** */
// Default
template < class T, class A > 
ft::vector<T,A>::vector(const allocator_type &alloc)
: _allocator(alloc), _size(0), _capacity(0)
{
	this->_array = this->_allocator.allocate(this->_capacity);
}

// Fill
template < class T, class A > 
ft::vector<T,A>::vector(size_type n, const value_type &val, const allocator_type &alloc)
: _allocator(alloc), _size(n), _capacity(n)
{
	this->_array = this->_allocator.allocate(this->_capacity);
	std::fill(this->begin(), this->end(), val);
}

// Range - Ajouter un enable if pour eviter de confondre avec le fill constructor

// Copy
template < class T, class A > 
ft::vector<T,A>::vector(const vector &x)
: _allocator(x.get_allocator()), _size(x.size()), _capacity(x.capacity())
{
	this->_array = this->_allocator.allocate(this->_capacity);
	std::copy(x.begin(), x.end(), this->begin());
}

// Destructor
template < class T, class A > 
ft::vector<T,A>::~vector(void)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
}

/* ************************************************************************** */
/* 	OPERATOR OVERLOADS                                                        */
/* ************************************************************************** */
// Operator []
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

// Operator =
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
/* ************************************************************************** */
/*  PRIVATE                                                                   */
/* ************************************************************************** */
// Realloc
template< class T, class A >
void	ft::vector<T,A>::_realloc(size_type n)
{
	pointer	p;

	p = this->get_allocator().allocate(n);
	std::copy(this->begin(), this->end(), p);
	for (int i = n; i < this->size(); ++i)
		this->get_allocator().destroy(this->_array + i);
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_capacity = n;
	this->_array = p;
}

/* ************************************************************************** */
/*  CAPACITY                                                                  */
/* ************************************************************************** */
// Resize
template < class T, class A > 
void	ft::vector<T,A>::resize(size_type n, value_type val)
{
	pointer	tmp;

	if (n > this->size())
	{
		if (n > this->capacity())
		{
			tmp = this->get_allocator().allocate(n);
			std::copy(this->begin(), this->end(), tmp);
			this->get_allocator().deallocate(this->_array, this->capacity());
			this->_array = tmp;
			this->_capacity = n;
		}
		std::fill_n(this->end(), n - this->size(), val);
	}
	else if (n < this->size())
	{
		for (int i = n; i < this->size(); ++i)
			this->get_allocator().destroy(this->_array + i);
	}
	this->_size = n;
}

// Reserve
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

/* ************************************************************************** */
/*  MODIFIERS                                                                 */
/* ************************************************************************** */
// Push back
template < class T, class A > 
void	ft::vector<T,A>::push_back(const T &val)
{
	pointer	tmp;
	
	if (this->size() == this->capacity())
	{
		this->_capacity = this->capacity() * 2;
		if (this->capacity() == 0)
			this->_capacity = 1;
		tmp = this->get_allocator().allocate(this->capacity());
		std::copy(this->begin(), this->end(), tmp);
		this->get_allocator().deallocate(this->_array, this->capacity());
		this->_array = tmp;
	}
	this->_array[this->size()] = val;
	++this->_size;
}

// Clear
template < class T, class A > 
void	ft::vector<T,A>::clear(void)
{
	for (int i = 0; i < this->size(); ++i)
		this->get_allocator().destroy(this->_array + i);
	this->_size = 0;
}

// Assign
template < class T, class A >
template < class InputIterator > 
void ft::vector<T,A>::assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
	this->clear();
	if (last - first > this->capacity())
	{
		this->get_allocator().deallocate(this->_array, this->capacity());
		this->_capacity = last - first;
		this->get_allocator().allocate(this->capacity());
	}
	std::copy(first, last, this->begin());
	this->_size = last - first;
} 

template < class T, class A > 
void ft::vector<T,A>::assign (size_type n, const value_type &val)
{
	this->clear();
	if (n > this->capacity())
	{
		this->get_allocator().deallocate(this->_array, this->capacity());
		this->_capacity = n;
		this->get_allocator().allocate(this->capacity());
	}
	std::fill(this->begin(), this->begin() + n, val);
	this->_size = n;
}

// insert
template < class T, class A >
typename ft::vector<T,A>::iterator	ft::vector<T,A>::insert(iterator position, const value_type &val)
{
    int index;

    this->_size += 1;
    if (this->size() > this->capacity())
    {
        index = this->size() - (this->end() - position);
        this->_realloc(this->size());
        position = this->begin() + index;
    }
    if (position == this->end())
        (*this)[this->size() - 1] = val;
    else
    {
        std::copy_backward(position, this->end(), this->end() + 1);
        (*this)[this->size() - (this->end() - position)] = val;
    }
    return (position);
}

template < class T, class A >
void	ft::vector<T,A>::insert(iterator position, size_type n, const value_type &val)
{
    unsigned int    index;

    this->_size += n;
    if (this->size() > this->capacity())
    {
        index = this->size() - (this->end() - position);
        this->_realloc(this->size());
        position = this->begin() + index;
    }
    if (position == this->end())
        std::fill_n(this->end(), n, val);
    else
    {
        std::copy_backward(position, this->end(), this->end() + n);
        std::fill_n(position, n, val);
    }
}

template < class T, class A >
template< class InputIterator >
void	ft::vector<T,A>::insert(iterator position, typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator>::type first, InputIterator last)
{
    unsigned int    index;
    unsigned int    size;

    size = last - first;
    this->_size += size;
    if (this->size() > this->capacity())
    {
        index = this->size() - (this->end() - position);
        this->_realloc(this->size());
        position = this->begin() + index;
    }
    if (position == this->end())
        std::copy(first, last, position);
    else
    {
        std::copy_backward(position, this->end(), this->end() + size);
        std::copy(first, last, position);
    }
}

// Erase
template < class T, class A >
typename ft::vector<T,A>::iterator  ft::vector<T,A>::erase(iterator position)
{
    iterator    result(&*position);

    this->get_allocator().destroy(&*position);
    std::copy(position + 1, this->end(), position);   
    this->get_allocator().destroy(&*(this->end() - 1));
    --this->_size;
    return (result);
}

template < class T, class A >
typename ft::vector<T,A>::iterator  ft::vector<T,A>::erase(iterator first, iterator last)
{
    iterator    result(first);

    for (ft::vector<T,A>::iterator it = first; it < last; ++it)
        this->get_allocator().destroy(&*it);
    std::copy(last, this->end(), first);   
    this->_size -= (last - first);
    return (result);
}

// Swap
template < class T, class A >
void    ft::vector<T,A>::swap(vector &x)
{
    value_type      *tmp_arr;
    allocator_type  tmp_alloc;
	size_type       tmp_size;
	size_type       tmp_capacity;

    tmp_arr = this->_array;
    tmp_size = this->size();
    tmp_capacity = this->capacity();
    tmp_alloc = this->get_allocator();
    this->_array = x._array;
    this->_size = x.size();
    this->_capacity = x.capacity();
    this->_allocator = x.get_allocator();
    x._array = tmp_arr;
    x._size = tmp_size;
    x._capacity = tmp_capacity;
    x._allocator = tmp_alloc;
}

// Non member operator overloads
template <class T, class A>
bool ft::operator==(const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
{
    if (lhs.size() == rhs.size())
    {
        return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    return (false);
}

template <class T, class A>
bool ft::operator!=(const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
{
    if (lhs.size() == rhs.size())
    {
        return (!std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    return (true);
}

template <class T, class A>
bool ft::operator<(const ft::vector<T,A> &lhs, const ft::vector<T,A> &rhs)
{
    if (lhs.size() == rhs.size())
    {
        return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    return (false);
}
