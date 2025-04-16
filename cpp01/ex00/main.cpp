/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:22:50 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/11 17:31:41 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	randomChump("Alice");

	Zombie* zombie = newZombie("Bob");
	zombie->announce();
	delete zombie;
}
