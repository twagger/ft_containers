/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:00:17 by marvin            #+#    #+#             */
/*   Updated: 2022/06/03 15:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETERS_HPP
# define PARAMETERS_HPP

// Macros
# define MAP typename TestFixture::Types::first_type
# define PAIR typename TestFixture::Types::second_type

// Types to test
using ContTypes = testing::Types
<
    std::pair<std::map<char, int>, std::pair<char, int>>,
    std::pair<ft::map<char, int>, ft::pair<char, int>>,
    std::pair<std::map<char, int, std::greater<char>>, std::pair<char, int>>,
    std::pair<ft::map<char, int, std::greater<char>>, ft::pair<char, int>>
>;

// Compare functions
static const std::type_info  &t_less = typeid(std::less<char>);
static const std::type_info  &t_more = typeid(std::greater<char>);

// Test suites
template<typename T>
struct Map_iterators : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_iterators, ContTypes);

template<typename T>
struct Map_constructor : public testing::Test { using Types = T; };
TYPED_TEST_CASE(Map_constructor, ContTypes);

#endif
