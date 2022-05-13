/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:27:08 by twagner           #+#    #+#             */
/*   Updated: 2022/05/13 13:07:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include "../iterators/iterator.hpp"
# include "../utils/utils.hpp"

namespace	ft
{
    template < class Key, class T, class Compare = std::less<Key>, \
               class Allocator = std::allocator<std::pair<const Key, T>> >
    class map
	{
		public:

        protected:

        private:
    }
}

#endif
