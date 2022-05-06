/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:53:18 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 12:18:50 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "../utils/utils.hpp"

/* ************************************************************************** */
/* 	OPERATOR OVERLOADS                                                        */
/* ************************************************************************** */
template < class T, class Container > 
ft::stack<T,Container>	&ft::stack<T,Container>::operator=(const ft::stack<T,Container> &other)
{
    this->c = other.c;
    return (*this);
}
