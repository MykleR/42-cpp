/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:43:00 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 12:28:28 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
	std::cout << RED
              << "WEEEEELLLCOMEEEEE TO THEEEE AREEEEENAAAA!!!"
              << RESET << std::endl;
    ClapTrap nb1("CHICKEN JOCKEY");
    ClapTrap nb2("STEVE");
    std::cout << std::endl;

    nb1.setAttackDamage(4);
    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());
	std::cout << std::endl;

    nb2.setAttackDamage(6);
    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());
	std::cout << std::endl;

	std::cout << RED
              << nb1.getName()
              << " INVOKES THE POWER OF THE WATER BUCKET !!! \n"
              << "HOW COULD " << nb2.getName() << " ATTACK ?\n" << RESET;
	nb1.beRepaired(4294967295);
	std::cout << std::endl;

    std::cout << RED
              << nb2.getName()
              << " INVOKES THE POWER OF THE LALALALAVAAA CHICHICHICKENNN!!! \n"
              << "HOW COULD " << nb1.getName() << " SURVIVE ?\n" << RESET;
    nb2.setAttackDamage(4294967294);
    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());
	std::cout << std::endl;

	nb1.setAttackDamage(10);
    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());
    nb2.attack(nb1.getName());
    std::cout << RED << "THAT'S A WIN FOR " << nb1.getName() << "!!!!!\n" << RESET
              << std::endl;

    return 0;
}
