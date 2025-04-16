/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:44:13 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/10 11:02:00 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _fName(""), _lName(""), _nName(""), _phone(""), _secret("")
{}

Contact::Contact(string firstName, string lastName, string nick, string phone, string secret)
	: _fName(firstName), _lName(lastName), _nName(nick), _phone(phone), _secret(secret)
{}

Contact::~Contact() {}
string Contact::getFirstName() const {return this->_fName;}
string Contact::getLastName() const {return this->_lName;}
string Contact::getNickName() const {return this->_nName;}
string Contact::getPhone() const {return this->_phone;}

void Contact::display(void) const
{
	std::cout << "\nFirst name: " << this->_fName << std::endl;
	std::cout << "Last name: " << this->_lName << std::endl;
	std::cout << "Nickname: " << this->_nName << std::endl;
	std::cout << "Phone number: " << this->_phone << std::endl;
	std::cout << "Darkest secret: " << this->_secret << std::endl;
}
