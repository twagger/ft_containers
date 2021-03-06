/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:31:34 by twagner           #+#    #+#             */
/*   Updated: 2022/06/17 09:27:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
# include <iostream>

namespace   ft
{
    template <class T1, class T2>
    struct pair
    {
        // Member types
        typedef T1 first_type;
        typedef T2 second_type;

        // Member variables
        T1  first;
        T2  second;
    
        // Constructors
        pair(void) : first(T1()), second(T2()) {}
        template<class U, class V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}
        pair(const first_type &a, const second_type &b) : first(a), second(b) {}
        ~pair(void) {}
    
        // Operator overload
        pair    &operator=(const pair &pr)
        {
            if (this != &pr)
            {
                // As we use a const for first in map we cannot update it
                // This operator is not used in the rest of the code for this.
                //this->first = pr.first; 
                this->second = pr.second;
            }
            return (*this);
        }
    };

    // Non member relational operators
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return lhs.first == rhs.first; } // no need to compare second in the code

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1,T2> &rhs)
    { return !(lhs == rhs); }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return lhs.first < rhs.first 
    || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(rhs < lhs); }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return rhs < lhs; }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(lhs < rhs); }

    // Make pair
    template <class T1, class T2>
    pair<T1, T2>    make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }

    // << Overload
    template <class T1, class T2>
    std::ostream	&operator<<(std::ostream &o, pair<T1, T2> const &pr)
    {
        o << pr.first;
        return (o);
    }
}

#endif
