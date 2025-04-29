/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:14:02 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 21:39:14 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMAL_COUNT 6

int main()
{
	Animal *animals[ANIMAL_COUNT];
	for (int i = 0; i < ANIMAL_COUNT / 2; i++)
		animals[i] = new Dog();
	for (int i = ANIMAL_COUNT / 2; i < ANIMAL_COUNT; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < ANIMAL_COUNT; i++)
	{
		std::cout << "Animal " << i + 1 << ": ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < ANIMAL_COUNT; i++)
		delete animals[i];

	std::cout << std::endl << "=== Testing Brain classes ===" << std::endl;
	std::cout << "FOR THE DOG" << std::endl;
	Dog *dog = new Dog;

	std::cout << "addresse de dog::brain = " << " " << dog->getBrain() << std::endl;
	Dog	*tmp = new Dog(*dog);
	std::cout << "addresse de dog::brain = " << " " << tmp->getBrain() << std::endl;
	delete dog;
	delete tmp;

	std::cout << std::endl << "FOR THE CAT" << std::endl;
	Cat *cat = new Cat;

	std::cout << "addresse de dog::brain = " << " " << cat->getBrain() << std::endl;

	Cat	*tmp_cat = new Cat(*cat);
	
	std::cout << "addresse de dog::brain = " << " " << tmp_cat->getBrain() << std::endl;

	delete cat;
	delete tmp_cat;
}
