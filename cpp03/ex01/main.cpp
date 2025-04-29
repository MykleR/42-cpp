/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:43:00 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 13:24:50 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(void) {
    std::cout << RED << "=== TESTING CONSTRUCTION/DESTRUCTION SEQUENCE ===" << RESET << std::endl;
    {
        std::cout << YELLOW << "\nCreating a ScavTrap (shows parent constructor called first):" << RESET << std::endl;
        ScavTrap scav("Guardian");
        
        std::cout << YELLOW << "\nDestroying ScavTrap (shows child destructor then parent):" << RESET << std::endl;
    }
    
    std::cout << RED << "\n=== COMPARING CLAPTRAP VS SCAVTRAP STATS ===" << RESET << std::endl;
    ClapTrap clap("Regular");
    ScavTrap scav("Enhanced");
    
    std::cout << BLUE << "\nClapTrap stats:" << RESET << std::endl;
    std::cout << "Name: " << clap.getName() << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    std::cout << BLUE << "\nScavTrap stats:" << RESET << std::endl;
    std::cout << "Name: " << scav.getName() << std::endl;
    std::cout << "Hit Points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scav.getAttackDamage() << std::endl;
    
    std::cout << RED << "\n=== TESTING SCAVTRAP FUNCTIONALITY ===" << RESET << std::endl;
    std::cout << GREEN << "\nTesting different attack messages:" << RESET << std::endl;
    clap.attack("Target");
    scav.attack("Target");
    
    std::cout << GREEN << "\nTesting guardGate function:" << RESET << std::endl;
    scav.guardGate();
    
    std::cout << GREEN << "\nTesting energy points depletion:" << RESET << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Energy left: " << scav.getEnergyPoints() << " - ";
        scav.attack("Dummy");
    }
    
    std::cout << GREEN << "\nTesting damage and repair:" << RESET << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.takeDamage(200);  // Should kill the ScavTrap
    scav.attack("Target"); // Should fail due to no hit points
    
    return 0;
}
