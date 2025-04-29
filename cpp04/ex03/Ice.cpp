/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:29:39 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 23:19:31 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::~Ice() {}
Ice::Ice() : AMateria("ice") {}

Ice::Ice(AMateria const & src) : AMateria(src) {
	this->_type = "ice";
}

Ice & Ice::operator=(AMateria const & rhs){
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
