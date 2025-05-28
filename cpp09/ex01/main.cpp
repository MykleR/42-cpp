/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:53:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 18:54:32 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>


int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <expression>" << std::endl;
		return 1;
	}
	try {
		rpn(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl; 
	}
}
