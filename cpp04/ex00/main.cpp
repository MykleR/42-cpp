/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:14:02 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 20:27:50 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Testing Animal classes ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    
    std::cout << "\n=== Testing Animal sounds ===" << std::endl;
    std::cout << "Cat sound: ";
    cat->makeSound();
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Generic animal sound: ";
    meta->makeSound();
    
    std::cout << "\n=== Testing WrongAnimal classes ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    std::cout << "wrong_cat type: " << wrong_cat->getType() << std::endl;
    std::cout << "wrong_meta type: " << wrong_meta->getType() << std::endl;
    
    std::cout << "\n=== Testing WrongAnimal sounds ===" << std::endl;
    std::cout << "WrongCat sound: ";
    wrong_cat->makeSound(); // This should call WrongAnimal::makeSound(), not WrongCat::makeSound()
    std::cout << "WrongAnimal sound: ";
    wrong_meta->makeSound();
    
    std::cout << "\n=== Demonstrating direct call to WrongCat ===" << std::endl;
    const WrongCat direct_wrong_cat;
    std::cout << "Direct WrongCat type: " << direct_wrong_cat.getType() << std::endl;
    std::cout << "Direct WrongCat sound: ";
    direct_wrong_cat.makeSound(); // This will call WrongCat::makeSound()
    
    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrong_meta;
    delete wrong_cat;
    
    return 0;
}
