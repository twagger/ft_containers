/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:27:48 by twagner           #+#    #+#             */
/*   Updated: 2022/05/13 12:16:19 by twagner          ###   ########.fr       */
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
template < class T, class A > 
template <class InputIterator>
ft::vector<T,A>::vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,\
InputIterator last, const allocator_type &alloc)
: _allocator(alloc), _size(last - first), _capacity(last - first)
{
	this->_array = this->_allocator.allocate(this->_capacity);
    std::copy(first, last, this->begin());
}

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
    return (*this);
}

/* ************************************************************************** */
/* 	MEMBER FUNCTIONS                                                          */
/* ************************************************************************** */
/* ************************************************************************** */
/*  PRIVATE                                                                   */
/* ************************************************************************** */
// Realloc
template< class T, class A >
typename ft::vector<T,A>::pointer    ft::vector<T,A>::_realloc(size_type n)
{
    pointer newarr;

    if (n > this->capacity())
    {
        if (n > this->max_size())
            throw std::length_error("length error");
        newarr = this->get_allocator().allocate(n);
        std::copy(this->begin(), this->end(), newarr);
        for (int i = 0; i < this->size(); ++i)
		    this->get_allocator().destroy(this->_array + i);
        this->get_allocator().deallocate(this->_array, this->capacity());
        this->_array = newarr;
        this->_capacity = n;
        return (newarr);
    }
    else
        return (this->_array);
}

/* ************************************************************************** */
/*  CAPACITY                                                                  */
/* ************************************************************************** */
// Resize
template < class T, class A > 
void	ft::vector<T,A>::resize(size_type n, value_type val)
{
	if (n > this->size())
	{
        this->_array = this->_realloc(n);
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
    this->_array = this->_realloc(n);
}

/* ************************************************************************** */
/*  MODIFIERS                                                                 */
/* ************************************************************************** */
// Push back
template < class T, class A > 
void	ft::vector<T,A>::push_back(const T &val)
{
    size_type   n;

	if (this->size() == this->capacity())
	{
		if (this->capacity() == 0)
			n = 1;
        else
            n = this->capacity() * 2;
        this->_array = this->_realloc(n);
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
void ft::vector<T,A>::assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
{
    const size_type len = last - first;
    value_type      *newarr;
    InputIterator   mid;

	if (len > this->capacity())
	{
        if (len > this->max_size())
            throw std::length_error("length error");
        newarr = this->get_allocator().allocate(len);
        std::copy(first, last, newarr);
        for (int i = 0; i < this->size(); ++i)
		    this->get_allocator().destroy(this->_array + i);
        this->get_allocator().deallocate(this->_array, this->capacity());
        this->_array = newarr;
        this->_capacity = len;
        this->_size = len;
	}
	else if (this->size() >= len)
    {
        std::copy(first, last, this->begin());
        for (int i = len; i < this->size(); ++i)
	        this->get_allocator().destroy(this->_array + i);
        this->_size = len;
    }
    else
    {   
        mid = first + this->size();
        std::copy(first, mid, this->begin());
        std::uninitialized_copy(mid, last, this->begin() + this->size());
        this->_size = len;
    }
} 

template < class T, class A > 
void ft::vector<T,A>::assign(size_type n, const value_type &val)
{
    value_type  *newarr;

	if (n > this->capacity())
	{
        if (n > this->max_size())
            throw std::length_error("length error");
        newarr = this->get_allocator().allocate(n);
    	std::fill_n(newarr, n, val);
        for (int i = 0; i < this->size(); ++i)
		    this->get_allocator().destroy(this->_array + i);
        this->get_allocator().deallocate(this->_array, this->capacity());
        this->_array = newarr;
        this->_capacity = n;
        this->_size = n;
	}
	else if (this->size() >= n)
    {
    	std::fill_n(this->begin(), n, val);
        for (int i = n; i < this->size(); ++i)
	        this->get_allocator().destroy(this->_array + i);
        this->_size = n;
    }
    else
    {   
        std::fill_n(this->begin(), this->size(), val);
        std::uninitialized_fill_n(this->begin() + this->size() + 1, n - this->size(), val);
        this->_size = n;
    }
}

// insert
template < class T, class A >
typename ft::vector<T,A>::iterator	ft::vector<T,A>::insert(iterator position, const value_type &val)
{
    unsigned int    index;

    index = position - this->begin();
    this->_array = this->_realloc(this->size() + 1);
    position = this->begin() + index;
    if (position != this->end())
        std::copy_backward(position, this->end(), this->end() + 1);
    *position = val;
    this->_size += 1;
    return (position);
}

template < class T, class A >
void	ft::vector<T,A>::insert(iterator position, size_type n, const value_type &val)
{
    unsigned int    index;

    index = position - this->begin();
    this->_array = this->_realloc(this->size() + n);
    position = this->begin() + index;
    if (position != this->end())
        std::copy_backward(position, this->end(), this->end() + n);
    std::fill_n(position, n, val);
    this->_size += n;
}

template < class T, class A >
template< class InputIterator >
void	ft::vector<T,A>::insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
{
    unsigned int    index;
    unsigned int    size;
    
    size = last - first;
    index = position - this->begin();
    this->_array = this->_realloc(this->size() + size);
    position = this->begin() + index;
    if (position != this->end())
        std::copy_backward(position, this->end(), this->end() + size);
    std::copy(first, last, position);
    this->_size += size;
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
void    ft::vector<T,A>::swap(ft::vector<T,A> &x)
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
