/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixtures.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:52:27 by twagner           #+#    #+#             */
/*   Updated: 2022/05/07 10:53:06 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXTURES_HPP
# define FIXTURES_HPP

class VectorTest : public ::testing::Test {
	protected:
		ft::vector<int>		MyVector;
		ft::vector<int>		MyTmpVector;
		std::vector<int>	StdVector;
		std::vector<int>	StdTmpVector;
};

#endif
