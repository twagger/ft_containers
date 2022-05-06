/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:52:59 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 10:48:23 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
    // Equal
    template <class InputIterator1, class InputIterator2>
    bool    equal(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2);

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool    equal(InputIterator1 first1, InputIterator1 last1,
                  InputIterator2 first2, BinaryPredicate pred); 
    
    // Lexicographical compare
    template <class InputIterator1, class InputIterator2>
    bool    lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2);

    template <class InputIterator1, class InputIterator2, class Compare>
    bool    lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2,
                                    Compare comp);
}

# include "equal.tpp"
# include "lexicographical_compare.tpp"

#endif