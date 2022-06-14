/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:23:19 by marvin            #+#    #+#             */
/*   Updated: 2022/06/14 07:51:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

// Macros
# define STACK typename TestFixture::Types

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::stack<int>,
    ft::stack<int>
>;

// Test suites
template<typename T>
struct Stack_modifiers : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Stack_modifiers, GenericTypes);

template<typename T>
struct Stack_constructors : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Stack_constructors, GenericTypes);

template<typename T>
struct Stack_capacity : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Stack_capacity, GenericTypes);

template<typename T>
struct Stack_relational_operators : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Stack_relational_operators, GenericTypes);

template<typename T>
struct Stack_access : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Stack_access, GenericTypes);

#endif
