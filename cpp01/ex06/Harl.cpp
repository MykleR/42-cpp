/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:06:17 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/16 17:43:09 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getFilter() const
{
	return _filterLevel;
}

void Harl::setFilter(std::string level)
{
	for (int i = 0; i < Harl::LEVELS; i++)
	{
		if (level == _levels[i])
		{
			_filterLevel = i;
			return;
		}
	}
}

void Harl::complain(std::string level)
{
	int i = 0;
	while (i < Harl::LEVELS && level != _levels[i])
		i++;
	if (i >= Harl::LEVELS)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	switch(i)
	{
		case 0:
			(this->*_funcs[0])();
			break;
		case 1:
			(this->*_funcs[1])();
			break;
		case 2:
			(this->*_funcs[2])();
			break;
		case 3:
			(this->*_funcs[3])();
			break;
	}
}
