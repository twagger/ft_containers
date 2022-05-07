/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:52:47 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 10:49:40 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class InputIterator1, class InputIterator2>
bool ft::lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first2 < *first1)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool ft::lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2,
                                 Compare comp)
{
    while (first1 != last1)
    {
        if (first2 == last2 || comp(*first2, *first1))
            return false;
        else if (comp(*first1, *first2))
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}
