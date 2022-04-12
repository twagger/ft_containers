/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/04/12 11:13:21 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <algorithm>
#include "containers/Vector.hpp"

int main(void)
{
	int i;

	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 1 : Create a FT Vector ]--- \033[0m" << std::endl;
	ft::vector<int>	myVector;
	myVector.push_back(35);
	myVector.push_back(42);
	std::cout << "vector[0] : " << myVector[0] << std::endl;
	std::cout << "vector[1] : " << myVector[1] << std::endl;
	
	// TEST 2
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 2 : Create a FT Vector by copy ]--- \033[0m" << std::endl;
	ft::vector<int>	myCopiedVector(myVector);
	myCopiedVector.push_back(38);
	myCopiedVector.push_back(49);
	i = 0;
	for (ft::vector<int>::iterator it = myCopiedVector.begin(); it < myCopiedVector.end(); ++it)
	{
		std::cout << "vector[" << i++ << "] : " << *it << std::endl;
	}
	
	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 3 : Use iterators on FT Vector ]--- \033[0m" << std::endl;
	i = 0;
	for (ft::vector<int>::iterator it = myVector.begin(); it < myVector.end(); ++it)
	{
		std::cout << "vector[" << i++ << "] : " << *it << std::endl;
	}

	// END OF PROGRAM
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
