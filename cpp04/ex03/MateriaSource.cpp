/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:00:32 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 23:25:21 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_materia[i] = NULL;
		if (src._materia[i])
			this->_materia[i] = src._materia[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < 4; i++)
	{
		delete this->_materia[i];
		this->_materia[i] = NULL;
		if (rhs._materia[i])
			this->_materia[i] = rhs._materia[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m->clone();
			return;
		}
	}
	std::cout << "MateriaSource: Inventory is full, cannot learn new materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	std::cout << "MateriaSource: No materia of type " << type << " found." << std::endl;
	return NULL;
}

