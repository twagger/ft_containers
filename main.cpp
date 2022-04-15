/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:17:50 by twagner           #+#    #+#             */
/*   Updated: 2022/04/15 16:21:22 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "containers/Vector.hpp"

#include <gtest/gtest.h>

/*
** ------------------------
** Commands to launch tests 
** ------------------------
**  cmake -S . -B build && cmake --build build && cd build && ctest ; cd ..
**  cmake -S . -B build && cmake --build build && cd build && ctest --verbose ; cd ..
*/

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

TEST_F(VectorTest, algorithmTest) {
	std::fill(MyVector.begin(), MyVector.end(), 43);
	std::fill(StdVector.begin(), StdVector.end(), 43);
	EXPECT_EQ(MyVector.size(), StdVector.size());
}
