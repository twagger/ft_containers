/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:17:50 by twagner           #+#    #+#             */
/*   Updated: 2022/05/06 18:08:14 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return (RUN_ALL_TESTS());
}
