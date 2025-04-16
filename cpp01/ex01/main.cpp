/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:22:50 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/11 17:49:42 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(5, "Jacksons");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
