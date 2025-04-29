/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:34:30 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 22:34:52 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::~Cure() {}
Cure::Cure() : AMateria("cure") {}

Cure::Cure(AMateria const & src) : AMateria(src) {
	this->_type = "cure";
}

Cure & Cure::operator=(AMateria const & rhs){
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
