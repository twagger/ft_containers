/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:52:59 by twagner           #+#    #+#             */
/*   Updated: 2022/05/27 10:39:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace   ft
{
    // Integral constant
    template <class T, T v>
    struct integral_constant {
        static const T                  value = v;
        typedef T                       value_type;
        typedef integral_constant<T,v>  type;
    };

    // True type and false type
    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    // Is_integral
    // First is the generic, others are full specializations for integral types
    template <class T>
    struct is_integral                                    : public false_type{};
    template <> struct is_integral<bool>                   : public true_type{};
    template <> struct is_integral<char>                   : public true_type{};
    template <> struct is_integral<char16_t>               : public true_type{};
    template <> struct is_integral<char32_t>               : public true_type{};
    template <> struct is_integral<wchar_t>                : public true_type{};
    template <> struct is_integral<signed char>            : public true_type{};
    template <> struct is_integral<short int>              : public true_type{};
    template <> struct is_integral<int>                    : public true_type{};
    template <> struct is_integral<long int>               : public true_type{};
    template <> struct is_integral<long long int>          : public true_type{};
    template <> struct is_integral<unsigned char>          : public true_type{};
    template <> struct is_integral<unsigned short int>     : public true_type{};
    template <> struct is_integral<unsigned int>           : public true_type{};
    template <> struct is_integral<unsigned long int>      : public true_type{};
    template <> struct is_integral<unsigned long long int> : public true_type{};
    template <> struct is_integral<const bool>             : public true_type{};
    template <> struct is_integral<const char>             : public true_type{};
    template <> struct is_integral<const char16_t>         : public true_type{};
    template <> struct is_integral<const char32_t>         : public true_type{};
    template <> struct is_integral<const wchar_t>          : public true_type{};
    template <> struct is_integral<const signed char>      : public true_type{};
    template <> struct is_integral<const short int>        : public true_type{};
    template <> struct is_integral<const int>              : public true_type{};
    template <> struct is_integral<const long int>         : public true_type{};
    template <> struct is_integral<const long long int>    : public true_type{};
    template <> struct is_integral<const unsigned char>    : public true_type{};
    template <> struct is_integral<const unsigned int>     : public true_type{};
    template <>
    struct is_integral<const unsigned short int>           : public true_type{};
    template <>
    struct is_integral<const unsigned long int>            : public true_type{};
    template <>
    struct is_integral<const unsigned long long int>       : public true_type{};
}

#endif
