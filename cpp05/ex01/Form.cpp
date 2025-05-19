/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:00:20 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 13:12:44 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {}
Form::~Form() {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name),
	_signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name),
	_signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	if (src._signGrade < 1 || src._execGrade < 1)
		throw Form::GradeTooHighException();
	else if (src._signGrade > 150 || src._execGrade > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

std::string Form::getName() const {return this->_name;}
int Form::getSignGrade() const {return this->_signGrade;}
int Form::getExecGrade() const {return this->_execGrade;}
bool Form::isSigned() const {return this->_isSigned;}

void Form::beSigned(int grade)
{
	if (grade <= this->_signGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form: " << i.getName() << ", Sign Grade: " << i.getSignGrade()
		<< ", Exec Grade: " << i.getExecGrade() << ", Signed: " << (i.isSigned() ? "Yes" : "No");
	return o;
}
