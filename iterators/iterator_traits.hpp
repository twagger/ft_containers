/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:11:29 by twagner           #+#    #+#             */
/*   Updated: 2022/04/12 17:09:57 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <cstddef>
# include <iterator>

namespace ft
{
	template < class Iter >
	struct iterator_traits
	{
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T								*pointer;
		typedef T								&reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T							*pointer;
		typedef const T							&reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

#endif
