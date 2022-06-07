/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:00:17 by marvin            #+#    #+#             */
/*   Updated: 2022/06/07 13:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

// Macros
# define MAP typename TestFixture::Types::first_type
# define PAIR typename TestFixture::Types::second_type
# define ITERATOR typename TestFixture::Types::first_type::iterator

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::pair<std::map<char, int>, std::pair<char, int>>,
    std::pair<ft::map<char, int>, ft::pair<char, int>>,
    std::pair<std::map<char, int, std::greater<char>>, std::pair<char, int>>,
    std::pair<ft::map<char, int, std::greater<char>>, ft::pair<char, int>>
>;
// Test test sets
using FtTypes = testing::Types
<
    std::pair<ft::map<char, int>, ft::pair<char, int>>,
    std::pair<ft::map<char, int, std::greater<char>>, ft::pair<char, int>>
>;
using StdTypes = testing::Types
<
    std::pair<std::map<char, int>, std::pair<char, int>>,
    std::pair<std::map<char, int, std::greater<char>>, std::pair<char, int>>
>;

// Compare functions
static const std::type_info  &t_less = typeid(std::less<char>);
static const std::type_info  &t_more = typeid(std::greater<char>);

// Test suites
template<typename T>
struct Map_iterators : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_iterators, GenericTypes);

template<typename T>
struct Map_constructors : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_constructors, GenericTypes);

template<typename T>
struct Map_operators : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_operators, GenericTypes);

template<typename T>
struct Map_modifiers : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_modifiers, GenericTypes);

#endif
