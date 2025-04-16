/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:53:52 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/07 18:46:52 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printUpper(std::string str)
{
    for (std::size_t i=0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str;
}

int main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i=1; i < ac; i++)
		printUpper(av[i]);
	std::cout << std::endl;
	return 0;
}
