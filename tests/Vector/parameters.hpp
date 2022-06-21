/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 06:50:19 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 10:16:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

// Macros
# define VECTOR typename TestFixture::Types
# define ITERATOR typename TestFixture::Types::iterator

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::vector<int>,
    ft::vector<int>
>;

// Test test sets
using FtTypes = testing::Types
<
    ft::vector<int>
>;
using StdTypes = testing::Types
<
    std::vector<int>
>;

// Test suites
template<typename T>
struct Vector_iterators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_iterators, GenericTypes);

template<typename T>
struct Vector_capacity : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_capacity, GenericTypes);

template<typename T>
struct Vector_operators : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_operators, GenericTypes);

template<typename T>
struct Vector_modifiers : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_modifiers, GenericTypes);

template<typename T>
struct Vector_element_access : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_element_access, GenericTypes);

template<typename T>
struct Vector_constructors : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_constructors, GenericTypes);

template<typename T>
struct Vector_performance : public testing::Test { using Types = T; };
TYPED_TEST_SUITE(Vector_performance, GenericTypes);

#endif
