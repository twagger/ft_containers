/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:17:50 by twagner           #+#    #+#             */
/*   Updated: 2022/04/15 15:48:10 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "containers/Vector.hpp"

#include <gtest/gtest.h>

class VectorTest : public ::testing::Test {
	protected:
		ft::vector<int>	MyVector;
		std::vector<int> StdVector;
};

TEST_F(VectorTest, pushBackTest) {
	MyVector.push_back(42);
	StdVector.push_back(42);
	EXPECT_EQ(MyVector[0], StdVector[0]);
}
