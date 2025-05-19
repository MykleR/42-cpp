/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:58:06 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 13:00:11 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
public:
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &src);
	~Form();

	Form &operator=(const Form &rhs);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(int grade);

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

	Form();
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
