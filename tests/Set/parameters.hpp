/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:00:17 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 10:16:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

// Macros
# define SET typename TestFixture::Types
# define ITERATOR typename TestFixture::Types::iterator

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::set<int>,
    ft::set<int>,
    std::set<int, std::greater<int>>,
    ft::set<int, std::greater<int>>
>;

// Compare functions
static const std::type_info  &t_less = typeid(std::less<int>);
static const std::type_info  &t_more = typeid(std::greater<int>);

// Test suites
template<typename T>
struct Set_iterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_iterators, GenericTypes);

template<typename T>
struct Set_constructors : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_constructors, GenericTypes);

template<typename T>
struct Set_operators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_operators, GenericTypes);

template<typename T>
struct Set_modifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_modifiers, GenericTypes);

template<typename T>
struct Set_observers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_observers, GenericTypes);

template<typename T>
struct Set_operations : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Set_operations, GenericTypes);

#endif
