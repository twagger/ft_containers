/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:11:29 by twagner           #+#    #+#             */
/*   Updated: 2022/05/27 13:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <cstddef>
# include <iterator>

namespace   ft
{
    // Iterator traits is a definition of member types for any iterator that
    // allow to get iterator types from a simple pointer to a certain type (T)
    // so it can be used properly with algorythms.
    
    // Master template
    /**
     * @brief Gets the types from the iterator type itself
     * 
     * @tparam Iter Iterator type
     */
    template < class Iter >
    struct iterator_traits // Master template with Iter
    {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };

    // Partial specilization for Pointers to T
    /**
     * @brief Gets the types from a pointer to T
     * 
     * @tparam T templated type handled by the iterator
     */
    template < class T >
    struct iterator_traits<T *>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T                               *pointer;
        typedef T                               &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    // Partial specialization for const Pointers to T
    /**
     * @brief Gets the types from a const pointer to T
     * 
     * @tparam T const templated type handled by the iterator
     */
    template < class T >
    struct iterator_traits<const T *>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef const T                         *pointer;
        typedef const T                         &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template < class Iter >
    typename iterator_traits<Iter>::iterator_category 
    _iterator_category(const Iter &)
    { 
        return typename iterator_traits<_Iter>::iterator_category(); 
    }
}

#endif
