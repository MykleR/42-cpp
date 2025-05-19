/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 13:33:44 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void testFormCreation() {
    std::cout << BOLD BLUE "\n=== Testing Form Creation ===" RESET << std::endl;
    
    // Valid form
    std::cout << CYAN "\n> Testing valid form:" RESET << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << GREEN "Created: " RESET << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Sign grade too high
    std::cout << CYAN "\n> Testing sign grade too high:" RESET << std::endl;
    try {
        Form f2("Invalid Form", 0, 25);
        std::cout << "Created: " << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Exec grade too low
    std::cout << CYAN "\n> Testing exec grade too low:" RESET << std::endl;
    try {
        Form f3("Invalid Form", 50, 151);
        std::cout << "Created: " << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Copy constructor
    std::cout << CYAN "\n> Testing copy constructor:" RESET << std::endl;
    try {
        Form f4("Patent Form", 10, 5);
        Form f5(f4);
        std::cout << GREEN "Original: " RESET << f4 << std::endl;
        std::cout << GREEN "Copy: " RESET << f5 << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
}

void testFormSigning() {
    std::cout << BOLD BLUE "\n=== Testing Form Signing ===" RESET << std::endl;
    
    // Successful signing
    std::cout << CYAN "\n> Testing successful signing:" RESET << std::endl;
    try {
        Bureaucrat highRank("Director", 5);
        Form importantForm("Classified Document", 10, 5);
        
        std::cout << YELLOW "Before signing: " RESET << importantForm << std::endl;
        highRank.signForm(importantForm);
        std::cout << GREEN "After signing: " RESET << importantForm << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Failed signing due to low grade
    std::cout << CYAN "\n> Testing failed signing due to low grade:" RESET << std::endl;
    try {
        Bureaucrat lowRank("Intern", 100);
        Form importantForm("Executive Order", 20, 10);
        
        std::cout << YELLOW "Before signing attempt: " RESET << importantForm << std::endl;
        lowRank.signForm(importantForm);
        std::cout << RED "After signing attempt: " RESET << importantForm << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Edge case - equal grade
    std::cout << CYAN "\n> Testing signing with equal grade:" RESET << std::endl;
    try {
        Bureaucrat b("Manager", 30);
        Form f("Department Request", 30, 30);
        
        std::cout << YELLOW "Before signing: " RESET << f << std::endl;
        b.signForm(f);
        std::cout << GREEN "After signing: " RESET << f << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Exception: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << BOLD MAGENTA "\n*** BUREAUCRAT AND FORM TESTING ***" RESET << std::endl;
    
    testFormCreation();
    testFormSigning();
    
    std::cout << BOLD MAGENTA "\n*** TESTING COMPLETE ***" RESET << std::endl;
    return 0;
}
