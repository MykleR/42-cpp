/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:40:16 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/10 12:18:54 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define CLEAR "\033[2J\033[H"
#define TITLE "\033[1;32m ------- \033[0m"

void title(string title)
{
	std::cout << CLEAR << TITLE << title << TITLE << "\n\n";
}

int	pause(string message)
{
	if (std::cin.eof()) return 0;
	std::cout << message << "\nPress ENTER to continue.\n";
	std::cin.ignore();
	return 0;
}

void prompt(string message, string &input)
{
	if (std::cin.eof()) return;
	std::cout << message;
	std::getline(std::cin, input);
}

bool	addContact(PhoneBook &book)
{
	string	fName, lName, nName, phone, secret;

	title("ADD CONTACT");
	prompt("Enter first name: ", fName);
	prompt("Enter last name: ", lName);
	prompt("Enter nickname: ", nName);
	prompt("Enter phone number: ", phone);
	prompt("Enter darkest secret: ", secret);
	if (fName.empty() || lName.empty() || nName.empty()
		|| phone.empty() || secret.empty())
		return pause("\nContact not added. Empty fields.");
	book.add(Contact(fName, lName, nName, phone, secret));
	return pause("\nContact added successfully");
}

bool	searchContact(PhoneBook &book)
{
	string input;
	Contact contact;

	title("SEARCH CONTACT");
	if (book.isEmpty())
		return pause("Book is empty.");
	book.display();
	prompt("\nEnter an index: ", input);
	if (input.length() != 1 || book.search(input[0] - '0', contact))
		return pause("\nContact not found.");
	contact.display();
	return pause("");
}

int main(void)
{
	string entry;
	PhoneBook book = PhoneBook();

	for(;;)
	{
		title("PHONEBOOK");
		std::cout << "Available commands: \n- ADD\n- SEARCH\n- EXIT\n\n";
		prompt(">> ", entry);
		if (entry == "ADD") addContact(book);
		if (entry == "SEARCH") searchContact(book);
		if (std::cin.eof() || entry == "EXIT") break;
	}
	std::cout << "\nExiting program.\n";
}
