/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:11:11 by mykle             #+#    #+#             */
/*   Updated: 2025/05/20 19:41:14 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::Action() const
{
	std::srand(time(NULL));
	std::cout << "Brrrrrrrzzzzt... *drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << "The robotomy of " << this->_target << " has been successful." << std::endl;
	else
		std::cout << "The robotomy of " << this->_target << " has failed." << std::endl;
}
