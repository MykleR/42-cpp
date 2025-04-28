/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:10:17 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/28 17:02:17 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	switch (argc)
	{
		case 2:
			harl.complain(argv[1]); break;
		default:
			std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
	}
}
