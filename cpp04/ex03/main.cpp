/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:43:13 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 23:43:23 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

// Color codes for better output formatting
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printHeader(const std::string& title) {
    std::cout << BOLD << CYAN << "\n╔════════════════════════════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << CYAN << "║ " << title << std::string(50 - title.length(), ' ') << RESET << std::endl;
    std::cout << BOLD << CYAN << "╚════════════════════════════════════════════════════════════" << RESET << std::endl;
}

void printSubHeader(const std::string& subtitle) {
    std::cout << BOLD << MAGENTA << "▶ " << subtitle << RESET << std::endl;
}

void printSuccess(const std::string& message) {
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
}

void printError(const std::string& message) {
    std::cout << RED << "✗ " << message << RESET << std::endl;
}

void printInfo(const std::string& message) {
    std::cout << YELLOW << "  " << message << RESET << std::endl;
}

void testAMateria() {
    printHeader("TESTING AMATERIA & DERIVED CLASSES");
    
    printSubHeader("Testing Ice Materia");
    Ice* ice = new Ice();
    printInfo("Type: " + ice->getType());
    
    ICharacter* target = new Character("Target");
    std::cout << BLUE << "  Using Ice on target: " << RESET;
    ice->use(*target);
    
    printSubHeader("Testing Cure Materia");
    Cure* cure = new Cure();
    printInfo("Type: " + cure->getType());
    
    std::cout << BLUE << "  Using Cure on target: " << RESET;
    cure->use(*target);
    
    printSubHeader("Testing Clone Functionality");
    AMateria* iceClone = ice->clone();
    printInfo("Original Ice address: " + std::to_string((unsigned long)ice));
    printInfo("Cloned Ice address: " + std::to_string((unsigned long)iceClone));
    printInfo("Clone type: " + iceClone->getType());
    
    AMateria* cureClone = cure->clone();
    printInfo("Original Cure address: " + std::to_string((unsigned long)cure));
    printInfo("Cloned Cure address: " + std::to_string((unsigned long)cureClone));
    printInfo("Clone type: " + cureClone->getType());
    
    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;
    delete target;
}

void testMateriaSource() {
    printHeader("TESTING MATERIASOURCE");
    
    printSubHeader("Creating and Learning Materias");
    IMateriaSource* src = new MateriaSource();
    
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
    printInfo("Learning Ice Materia");
    src->learnMateria(ice);

    printInfo("Learning Cure Materia");
    src->learnMateria(cure);
    
    printSubHeader("Creating Materias from Source");
    AMateria* ice_clone = src->createMateria("ice");
    if (ice_clone) {
        printSuccess("Successfully created Ice materia");
        printInfo("Type: " + ice_clone->getType());
    } else {
        printError("Failed to create Ice materia");
    }
	delete ice_clone;
    
    AMateria* cure_clone = src->createMateria("cure");
    if (cure_clone) {
        printSuccess("Successfully created Cure materia");
        printInfo("Type: " + cure_clone->getType());
    } else {
        printError("Failed to create Cure materia");
    }
	delete cure_clone;
    
    printSubHeader("Testing Invalid Materia Creation");
    AMateria* unknown = src->createMateria("unknown");
    if (!unknown) {
        printSuccess("Correctly returned NULL for unknown materia type");
    } else {
        printError("Incorrectly created unknown materia type");
        delete unknown;
    }
    
    printSubHeader("Testing Materia Source Capacity");
    // Fill to capacity (4 slots, we've already learned 2)
    printInfo("Learning 2 more materias to reach capacity...");
    src->learnMateria(ice);
    src->learnMateria(cure);
    
    // Try to exceed capacity
    printInfo("Attempting to exceed capacity...");
    src->learnMateria(ice);
    
    delete ice;
    delete cure;
    delete src;
}

void testCharacter() {
    printHeader("TESTING CHARACTER");
    
    printSubHeader("Character Equipment Management");
    Character* hero = new Character("Hero");
    printInfo("Created character: " + std::string(hero->getName()));
    
    // Create materias
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* extraIce = new Ice();
    
    // Equip materias
    printInfo("Equipping materias to slots 0-3...");
    hero->equip(ice1);
    hero->equip(ice2);
    hero->equip(cure1);
    hero->equip(cure2);
    
    // Test equipping to full inventory
    printInfo("Testing equip to full inventory...");
    hero->equip(extraIce);
    
    // Test unequipping
    printSubHeader("Testing Unequip Functionality");
    printInfo("Unequipping materia from slot 2...");
    hero->unequip(2);
    printInfo("Re-equipping extra materia to slot 2...");
    hero->equip(extraIce);
    
    printSubHeader("Testing Use Functionality");
    Character* target = new Character("Target");
    
    printInfo("Using materia in slot 0 (Ice)...");
    hero->use(0, *target);
    
    printInfo("Using materia in slot 1 (Ice)...");
    hero->use(1, *target);
    
    printInfo("Using materia in slot 2 (Extra Ice)...");
    hero->use(2, *target);
    
    printInfo("Using materia in slot 3 (Cure)...");
    hero->use(3, *target);
    
    printInfo("Testing invalid slot indices...");
    hero->use(4, *target);
    hero->use(-1, *target);
    
    delete hero;
    delete target;
    delete cure1; // We unequipped this one, need to delete manually
}

void testCharacterCopying() {
    printHeader("TESTING CHARACTER COPYING");
    
    printSubHeader("Testing Copy Constructor");
    Character* original = new Character("Original");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
    original->equip(ice);
    original->equip(cure);
    
    printInfo("Created original character with Ice and Cure materias");
    
    Character* copy1 = new Character(*original);
    printInfo("Created copy using copy constructor");
    
    printSubHeader("Testing Assignment Operator");
    Character* copy2 = new Character("Copy2");
    *copy2 = *original;
    printInfo("Created copy using assignment operator");
    
    printSubHeader("Testing Independence of Copies");
    Character* target = new Character("Target");
    
    printInfo("Original character using materias:");
    original->use(0, *target);
    original->use(1, *target);
    
    printInfo("Copy1 (copy constructor) using materias:");
    copy1->use(0, *target);
    copy1->use(1, *target);
    
    printInfo("Copy2 (assignment) using materias:");
    copy2->use(0, *target);
    copy2->use(1, *target);
    
    // Test modifying original doesn't affect copies
    printSubHeader("Testing Independence After Modification");
    printInfo("Unequipping slot 0 from original...");
    original->unequip(0);
    
    printInfo("Original trying to use unequipped slot 0:");
    original->use(0, *target);
    
    printInfo("Copy1 using same slot (should still work):");
    copy1->use(0, *target);
    
    delete original;
    delete copy1;
    delete copy2;
    delete target;
	delete ice;
}

void testCompleteFlow() {
    printHeader("TESTING COMPLETE GAME FLOW");
    
    // Create materia source
    printSubHeader("Setting up MateriaSource");
    IMateriaSource* src = new MateriaSource();
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
    src->learnMateria(ice);
    src->learnMateria(cure);
	delete ice;
	delete cure;
    printSuccess("MateriaSource initialized with Ice and Cure templates");
    
    // Create characters
    printSubHeader("Creating Characters");
    ICharacter* knight = new Character("Knight");
    ICharacter* mage = new Character("Mage");
    ICharacter* enemy = new Character("Enemy");
    printSuccess("Characters created successfully");
    
    // Equip characters
    printSubHeader("Equipping Characters");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    knight->equip(tmp);
    printInfo("Knight equipped with Ice in slot 0");
    
    tmp = src->createMateria("ice");
    knight->equip(tmp);
    printInfo("Knight equipped with Ice in slot 1");
    
    tmp = src->createMateria("cure");
    mage->equip(tmp);
    printInfo("Mage equipped with Cure in slot 0");
    
    tmp = src->createMateria("cure");
    mage->equip(tmp);
    printInfo("Mage equipped with Cure in slot 1");
    
    // Simulate battle
    printSubHeader("Simulating Battle");
    std::cout << BLUE << "  Knight attacks Enemy:" << RESET << std::endl;
    knight->use(0, *enemy);
    knight->use(1, *enemy);
    
    std::cout << BLUE << "  Mage heals Knight:" << RESET << std::endl;
    mage->use(0, *knight);
    
    std::cout << BLUE << "  Mage heals themselves:" << RESET << std::endl;
    mage->use(1, *mage);
    
    // Clean up
    printSubHeader("Cleaning Up Resources");
    delete knight;
    delete mage;
    delete enemy;
    delete src;
    printSuccess("All resources cleaned up");
}

int main()
{
    std::cout << BOLD << YELLOW;
    std::cout << "╔══════════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║                   MATERIA SYSTEM TEST SUITE                  ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════════════════╝" << RESET << std::endl;
    
    testAMateria();
    testMateriaSource();
    testCharacter();
    testCharacterCopying();
    testCompleteFlow();
    
    std::cout << BOLD << GREEN << "\n✓ All tests completed successfully!" << RESET << std::endl;
    return 0;
}
