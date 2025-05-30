/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:31:08 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 13:34:04 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string	_name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &src);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &rhs);

	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	void setHitPoints(const unsigned int &value);
	void setEnergyPoint(const unsigned int &value);
	void setAttackDamage(const unsigned int &value);
};

#endif
