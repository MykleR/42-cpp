/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 13:31:56 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void testBureaucratCreation() {
    std::cout << BOLD BLUE "\n=== Testing Bureaucrat Creation ===" RESET << std::endl;
    
    // Valid bureaucrat
    std::cout << CYAN "\n> Testing valid bureaucrat:" RESET << std::endl;
    try {
        Bureaucrat b1("John", 75);
        std::cout << GREEN "Created: " RESET << b1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Grade too high
    std::cout << CYAN "\n> Testing grade too high:" RESET << std::endl;
    try {
        Bureaucrat b2("Alice", 0);
        std::cout << "Created: " << b2 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Grade too low
    std::cout << CYAN "\n> Testing grade too low:" RESET << std::endl;
    try {
        Bureaucrat b3("Bob", 151);
        std::cout << "Created: " << b3 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Copy constructor
    std::cout << CYAN "\n> Testing copy constructor:" RESET << std::endl;
    try {
        Bureaucrat b4("Charlie", 100);
        Bureaucrat b5(b4);
        std::cout << GREEN "Original: " RESET << b4 << std::endl;
        std::cout << GREEN "Copy: " RESET << b5 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
}

void testGradeIncrementDecrement() {
    std::cout << BOLD BLUE "\n=== Testing Grade Increment/Decrement ===" RESET << std::endl;
    
    // Normal increment/decrement
    std::cout << CYAN "\n> Testing normal increment/decrement:" RESET << std::endl;
    try {
        Bureaucrat b("David", 75);
        std::cout << YELLOW "Initial: " RESET << b << std::endl;
        
        b.incrementGrade();
        std::cout << GREEN "After increment: " RESET << b << std::endl;
        
        b.decrementGrade();
        std::cout << YELLOW "After decrement: " RESET << b << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Exception on increment
    std::cout << CYAN "\n> Testing increment at maximum grade:" RESET << std::endl;
    try {
        Bureaucrat b("Eve", 1);
        std::cout << YELLOW "Initial: " RESET << b << std::endl;
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Exception on decrement
    std::cout << CYAN "\n> Testing decrement at minimum grade:" RESET << std::endl;
    try {
        Bureaucrat b("Frank", 150);
        std::cout << YELLOW "Initial: " RESET << b << std::endl;
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << BOLD MAGENTA "\n*** BUREAUCRAT AND FORM TESTING ***" RESET << std::endl;
    
    testBureaucratCreation();
    testGradeIncrementDecrement();
    
    std::cout << BOLD MAGENTA "\n*** TESTING COMPLETE ***" RESET << std::endl;
    return 0;
}
