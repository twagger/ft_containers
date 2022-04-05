/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/04/05 16:08:28 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./containers/Vector.hpp"
#include <memory>

int main(void)
{
	// TEST 1
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 1 : Create a FT Vector ]--- \033[0m" << std::endl;

	ft::vector<int>	myVector;
	myVector.push_back(35);
	myVector.push_back(42);
	std::cout << "vector[0] : " << myVector[0] << std::endl;
	std::cout << "vector[1] : " << myVector[1] << std::endl;

	// END OF PROGRAM
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
