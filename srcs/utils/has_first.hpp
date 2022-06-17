/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_first.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:27:11 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 14:13:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAS_FIRST_HPP
# define HAS_FIRST_HPP
# include "pair.hpp"

namespace   ft
{
    template <class T>
    struct hasFirst
    {
        // To check if the T type have a "first" subtype
        typedef char yes[1];
        typedef char no[2]; 

        template <typename C>
        static yes& test(typename C::first*);

        template <typename>
        static no& test(...);

        // If the "sizeof" of the result of calling test<T>(NULL) is equal to
        // sizeof(yes), the first overload worked and T has a nested type named
        // first.
        static const bool value = sizeof(test<T>(NULL)) == sizeof(yes);
    };
}

#endif
