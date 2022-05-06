/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:52:54 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 10:51:44 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class InputIterator1, class InputIterator2>
bool    ft::equal(InputIterator1 first1, InputIterator1 last1,
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

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool    ft::equal(InputIterator1 first1, InputIterator1 last1,
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
