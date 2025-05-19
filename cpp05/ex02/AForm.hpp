/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:58:06 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 14:06:17 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
public:
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &src);
	~AForm();

	AForm &operator=(const AForm &rhs);

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;

	void beSigned(int grade) ;
	void execute(Bureaucrat const &executor) const;
	
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		virtual const char* what() const throw();
	};

private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

	AForm();

protected:
	virtual void Action() const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
