/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:17:16 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/10 11:17:31 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
	private:
		static const int MAX = 8;
		Contact	_contacts[MAX];
		int		_count;

	public:
		PhoneBook();
		~PhoneBook();

		bool isEmpty(void) const;
		void display(void) const;
		void add(Contact contact);
		bool search(int index, Contact &contact) const;
};

#endif
