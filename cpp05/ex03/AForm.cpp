/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:00:20 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 14:09:28 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {}
AForm::~AForm() {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name),
	_signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name),
	_signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	if (src._signGrade < 1 || src._execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (src._signGrade > 150 || src._execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

std::string AForm::getName() const {return this->_name;}
int AForm::getSignGrade() const {return this->_signGrade;}
int AForm::getExecGrade() const {return this->_execGrade;}
bool AForm::isSigned() const {return this->_isSigned;}

void AForm::beSigned(int grade)
{
	if (grade <= this->_signGrade)
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	this->Action();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "AForm: " << i.getName() << ", Sign Grade: " << i.getSignGrade()
		<< ", Exec Grade: " << i.getExecGrade() << ", Signed: " << (i.isSigned() ? "Yes" : "No");
	return o;
}
