/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:14:02 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 21:47:28 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Testing Animal classes ===" << std::endl;
    //const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "dog type: " << dog->getType() << std::endl;
    std::cout << "cat type: " << cat->getType() << std::endl;
    //std::cout << "meta type: " << meta->getType() << std::endl;
    
    std::cout << "\n=== Testing Animal sounds ===" << std::endl;
    std::cout << "Cat sound: ";
    cat->makeSound();
    std::cout << "Dog sound: ";
    dog->makeSound();
    std::cout << "Generic animal sound: ";
    //meta->makeSound();
    
    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete dog;
    delete cat;

	std::cout << "\n===== DEEP COPY TEST: DOGS =====" << std::endl;
    {
        // Original dog
        Dog* dog1 = new Dog();
        dog1->getBrain()->setIdea(0, "I want to chase a ball");
        std::cout << "Original dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
        
        // Copy constructed dog
        Dog* dog2 = new Dog(*dog1);
        std::cout << "Copied dog idea: " << dog2->getBrain()->getIdea(0) << std::endl;
        
        // Change the original dog's idea
        dog1->getBrain()->setIdea(0, "I want to sleep");
        std::cout << "Modified original dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied dog idea (should be unchanged): " << dog2->getBrain()->getIdea(0) << std::endl;
        
        // Test the assignment operator
        Dog dog3;
        dog3 = *dog1;
        std::cout << "Assigned dog idea: " << dog3.getBrain()->getIdea(0) << std::endl;
        
        // Change the original dog's idea again
        dog1->getBrain()->setIdea(0, "I want to eat");
        std::cout << "Modified original dog idea: " << dog1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned dog idea (should be unchanged): " << dog3.getBrain()->getIdea(0) << std::endl;
        
        // Clean up
        delete dog1;
        delete dog2;
    }
    
    std::cout << "\n===== DEEP COPY TEST: CATS =====" << std::endl;
    {
        // Original cat
        Cat* cat1 = new Cat();
        cat1->getBrain()->setIdea(0, "I want to catch a mouse");
        std::cout << "Original cat idea: " << cat1->getBrain()->getIdea(0) << std::endl;
        
        // Copy constructed cat
        Cat* cat2 = new Cat(*cat1);
        std::cout << "Copied cat idea: " << cat2->getBrain()->getIdea(0) << std::endl;
		
		// Change the original cat's idea
        cat1->getBrain()->setIdea(0, "I want to nap");
        std::cout << "Modified original cat idea: " << cat1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Copied cat idea (should be unchanged): " << cat2->getBrain()->getIdea(0) << std::endl;
        
        // Test the assignment operator
        Cat cat3;
        cat3 = *cat1;
        std::cout << "Assigned cat idea: " << cat3.getBrain()->getIdea(0) << std::endl;
        
        // Change the original cat's idea again
        cat1->getBrain()->setIdea(0, "I want to play");
        std::cout << "Modified original cat idea: " << cat1->getBrain()->getIdea(0) << std::endl;
        std::cout << "Assigned cat idea (should be unchanged): " << cat3.getBrain()->getIdea(0) << std::endl;
        
        // Clean up
        delete cat1;
        delete cat2;
    }

}
