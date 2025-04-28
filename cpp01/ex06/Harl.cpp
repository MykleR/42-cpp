/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:06:17 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/28 13:32:29 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int Harl::_filterLevel = -1;

void Harl::setFilterLevel(std::string level) const
{
	for (int i = 0; i < LEVELS; i++)
		if (this->_levels[i] == level)
			this->_filterLevel = i;
	if (this->_filterLevel == -1)
		std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void Harl::complain(const std::string level) const
{
    int i = 0;
    for (; i < LEVELS; i++)
        if (this->_levels[i] == level)
            break; 
	if (this->_filterLevel > i || this->_filterLevel == -1)
		return ;
    switch (i)
	{
		case DEBUG:		debug(); break;
		case INFO:		info(); break;
		case WARNING:	warning(); break;
		case ERROR:		error(); break;
		default: break;
    }
}

void Harl::debug() const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << std::endl;
}

void Harl::warning() const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
