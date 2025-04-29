/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:33:18 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 13:34:13 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap " << _name << " constructor by copy called" << std::endl;;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assignment operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack, no hit points or energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " now has " << _hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired, no hit points or energy points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
	if ((unsigned long)_hitPoints + amount > 4294967295)
		_hitPoints = 4294967295;
	else
		_hitPoints += amount;
	_energyPoints--;
}

std::string ClapTrap::getName() const{return _name;}
unsigned int ClapTrap::getHitPoints() const{return _hitPoints;}
unsigned int ClapTrap::getEnergyPoints() const{return _energyPoints;}
unsigned int ClapTrap::getAttackDamage() const{return _attackDamage;}
void ClapTrap::setHitPoints(const unsigned int &value){_hitPoints = value;}
void ClapTrap::setEnergyPoint(const unsigned int &value){_energyPoints = value;}
void ClapTrap::setAttackDamage(const unsigned int &value){_attackDamage = value;}
