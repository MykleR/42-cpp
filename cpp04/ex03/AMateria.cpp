/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:24:51 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 22:28:30 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}
AMateria::AMateria(std::string const & type) : _type(type) {}
AMateria::AMateria(AMateria const & src) : _type(src._type) {}
AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
