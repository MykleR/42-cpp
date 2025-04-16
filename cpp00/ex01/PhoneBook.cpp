/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:19:11 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/10 11:30:07 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(Contact contact)
{
	this->_contacts[this->_count++ % 8] = contact;
}

bool PhoneBook::isEmpty(void) const
{
	return (!this->_count);
}

bool PhoneBook::search(int index, Contact &contact) const
{
	if (index < 0 || index >= this->MAX || index >= this->_count)
		return (1);
	contact = this->_contacts[index];
	return (0);
}

static string format(string field)
{
	if (field.length() <= 10)
		return (field);
	field.resize(9);
	field.append(".");
	return (field);
}

void PhoneBook::display(void) const
{
	std::cout << "     index|first name| last name|  nickname\n";
	for (int i = 0; i < this->MAX && i < this->_count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << format(this->_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << format(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << format(this->_contacts[i].getNickName()) << std::endl;
	}
}
