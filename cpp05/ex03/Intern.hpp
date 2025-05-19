/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:28:18 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 19:16:11 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);

private:
	typedef AForm *(Intern::*FormBuilder)(const std::string &target);

	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	FormBuilder formBuilders[3] = {
		&Intern::createSCForm,
		&Intern::createRRForm,
		&Intern::createPPForm
	};
	AForm *createSCForm(const std::string &target);// ShrubberyCreationForm
	AForm *createRRForm(const std::string &target);// RobotomyRequestForm
	AForm *createPPForm(const std::string &target);// PresidentialPardonForm
};
