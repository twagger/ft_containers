/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:15:43 by twagner           #+#    #+#             */
/*   Updated: 2022/05/13 17:41:01 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
    // Default
    template <class InputIterator1, class InputIterator2>
    bool    equal(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    // Predicate
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool    equal(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

}

#endif
