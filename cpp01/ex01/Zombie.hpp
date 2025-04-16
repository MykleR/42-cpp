/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:19:35 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/11 17:46:06 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
		void announce(void) const;
};

Zombie* zombieHorde( int N, std::string name );

#endif
