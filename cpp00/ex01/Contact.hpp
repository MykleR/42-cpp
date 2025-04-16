/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:33:17 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/10 10:01:11 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
# include <iomanip>
# include <string>

typedef std::string string;

class Contact
{
	private:
		string _fName;
		string _lName;
		string _nName;
		string _phone;
		string _secret;

	public:
		Contact(void);
		~Contact(void);
		Contact(string firstName, string lastName, string nick, string phone, string secret);
		
		void display(void) const;
		string getFirstName() const;
		string getLastName() const;
		string getNickName() const;
		string getPhone() const;
};

#endif
