/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:53:26 by twagner           #+#    #+#             */
/*   Updated: 2022/04/12 17:35:27 by twagner          ###   ########.fr       */
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
	std::cout << "creation : OK" << std::endl;

	// TEST 3
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 3 : Use iterators on FT Vector ]--- \033[0m" << std::endl;
	i = 0;
	for (ft::vector<int>::iterator it = myCopiedVector.begin(); it < myCopiedVector.end(); ++it)
	{
		std::cout << "vector[" << i++ << "] : " << *it << std::endl;
	}
	
	// TEST 4
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ TEST 4 : Use reverse iterators on FT Vector ]--- \033[0m" << std::endl;
	ft::vector<int>::iterator it(myCopiedVector.begin());
	ft::vector<int>::iterator ite(myCopiedVector.end());
	ft::vector<int>::reverse_iterator rev_it(ite);
	ft::vector<int>::reverse_iterator rev_ite(it);

  	std::cout << "MyCopiedVector reversed content :";
  	while (rev_it != rev_ite)
    	std::cout << ' ' << *rev_it++;
 	std::cout << '\n';
	
	// END OF PROGRAM
	std::cout << std::endl;
	std::cout << "\033[1;35m ---[ End of program ]--- \033[0m" << std::endl;
	return (0);
}
