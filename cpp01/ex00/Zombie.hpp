/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:19:35 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/11 17:27:14 by mrouves          ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
