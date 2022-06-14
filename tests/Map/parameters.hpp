/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:00:17 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 13:32:28 by marvin           ###   ########.fr       */
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
using PerfTypes = testing::Types
<
    std::pair<std::map<int, char>, std::pair<int, char>>,
    std::pair<ft::map<int, char>, ft::pair<int, char>>,
    std::pair<std::map<int, char, std::greater<int>>, std::pair<int, char>>,
    std::pair<ft::map<int, char, std::greater<int>>, ft::pair<int, char>>
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

template<typename T>
struct Map_observers : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_observers, GenericTypes);

template<typename T>
struct Map_operations : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_operations, GenericTypes);

template<typename T>
struct Map_performance : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_performance, PerfTypes);

#endif
