/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:52:59 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 17:24:41 by twagner          ###   ########.fr       */
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

	// Enable_if with SFINAE principle
	template < bool, typename T = void > struct enable_if {};
	template < typename T >	struct enable_if< true, T >	{typedef T type;};

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
    template <class T>  struct is_integral                          : public false_type{};
    template <>         struct is_integral<bool>                    : public true_type{};
    template <>         struct is_integral<char>                    : public true_type{};
    template <>         struct is_integral<char16_t>                : public true_type{};
    template <>         struct is_integral<char32_t>                : public true_type{};
    template <>         struct is_integral<wchar_t>                 : public true_type{};
    template <>         struct is_integral<signed char>             : public true_type{};
    template <>         struct is_integral<short int>               : public true_type{};
    template <>         struct is_integral<int>                     : public true_type{};
    template <>         struct is_integral<long int>                : public true_type{};
    template <>         struct is_integral<long long int>           : public true_type{};
    template <>         struct is_integral<unsigned char>           : public true_type{};
    template <>         struct is_integral<unsigned short int>      : public true_type{};
    template <>         struct is_integral<unsigned int>            : public true_type{};
    template <>         struct is_integral<unsigned long int>       : public true_type{};
    template <>         struct is_integral<unsigned long long int>  : public true_type{};

    template <>         struct is_integral<const bool>                    : public true_type{};
    template <>         struct is_integral<const char>                    : public true_type{};
    template <>         struct is_integral<const char16_t>                : public true_type{};
    template <>         struct is_integral<const char32_t>                : public true_type{};
    template <>         struct is_integral<const wchar_t>                 : public true_type{};
    template <>         struct is_integral<const signed char>             : public true_type{};
    template <>         struct is_integral<const short int>               : public true_type{};
    template <>         struct is_integral<const int>                     : public true_type{};
    template <>         struct is_integral<const long int>                : public true_type{};
    template <>         struct is_integral<const long long int>           : public true_type{};
    template <>         struct is_integral<const unsigned char>           : public true_type{};
    template <>         struct is_integral<const unsigned short int>      : public true_type{};
    template <>         struct is_integral<const unsigned int>            : public true_type{};
    template <>         struct is_integral<const unsigned long int>       : public true_type{};
    template <>         struct is_integral<const unsigned long long int>  : public true_type{};
}

# include "equal.tpp"
# include "lexicographical_compare.tpp"
# include "is_integral.tpp"

#endif
