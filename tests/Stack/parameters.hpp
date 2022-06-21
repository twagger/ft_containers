/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:23:19 by marvin            #+#    #+#             */
/*   Updated: 2022/06/21 09:51:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP
# include <vector>
# include <deque>
# include <list>

// Macros
# define STACK typename TestFixture::Types

// Types to test
// Generic test set
using GenericTypes = testing::Types
<
    std::stack<int>,
    ft::stack<int>,
    std::stack<int, std::vector<int>>,
    ft::stack<int, std::vector<int>>,
    std::stack<int, std::deque<int>>,
    ft::stack<int, std::deque<int>>,
    std::stack<int, std::list<int>>,
    ft::stack<int, std::list<int>>
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
