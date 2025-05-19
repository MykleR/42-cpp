/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:34:26 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 18:40:47 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){(void)other;}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formBuilders[i])(target);
		}
	}
	std::cout << "Intern can't create " << formName << std::endl;
	return nullptr;
}

AForm *Intern::createSCForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
AForm *Intern::createRRForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
AForm *Intern::createPPForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
