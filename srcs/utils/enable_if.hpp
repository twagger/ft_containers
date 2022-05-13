/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:47:43 by twagner           #+#    #+#             */
/*   Updated: 2022/05/13 14:48:34 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	// Enable_if with SFINAE principle
	template < bool, typename T = void > struct enable_if {};
    template < typename T >	struct enable_if< true, T >	{typedef T type;};
}

#endif
