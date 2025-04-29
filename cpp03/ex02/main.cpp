/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:43:00 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 13:41:26 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(void) {
    std::cout << RED << "=== TESTING CONSTRUCTION/DESTRUCTION SEQUENCE ===" << RESET << std::endl;
    {
        std::cout << YELLOW << "\nCreating a FragTrap (shows parent constructor called first):" << RESET << std::endl;
        FragTrap scav("Guardian");
        
        std::cout << YELLOW << "\nDestroying FragTrap (shows child destructor then parent):" << RESET << std::endl;
    }
    
    std::cout << RED << "\n=== COMPARING CLAPTRAP VS FRAGTRAP STATS ===" << RESET << std::endl;
    ClapTrap clap("Regular");
    FragTrap scav("Enhanced");
    
    std::cout << BLUE << "\nClapTrap stats:" << RESET << std::endl;
    std::cout << "Name: " << clap.getName() << std::endl;
    std::cout << "Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << clap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << clap.getAttackDamage() << std::endl;
    
    std::cout << BLUE << "\nFRAGTRAP stats:" << RESET << std::endl;
    std::cout << "Name: " << scav.getName() << std::endl;
    std::cout << "Hit Points: " << scav.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << scav.getAttackDamage() << std::endl;
    
    std::cout << RED << "\n=== TESTING FRAGTRAP FUNCTIONALITY ===" << RESET << std::endl;
    clap.attack("Target");
    scav.attack("Target");
    
    std::cout << GREEN << "\nTesting highFivesGuys function:" << RESET << std::endl;
    scav.highFivesGuys();
    
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
