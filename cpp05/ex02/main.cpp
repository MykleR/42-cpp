/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 15:22:32 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <unistd.h>

// Colors for prettier output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void testBureaucrats() {
    std::cout << BOLD << BLUE << "========== BUREAUCRAT TESTS ==========" << RESET << std::endl;
    
    try {
        std::cout << CYAN << "\n[Creating bureaucrats with valid grades]" << RESET << std::endl;
        Bureaucrat president("President", 1);
        Bureaucrat minister("Minister", 25);
        Bureaucrat manager("Manager", 75);
        Bureaucrat intern("Intern", 150);
        
        std::cout << GREEN << president << RESET << std::endl;
        std::cout << GREEN << minister << RESET << std::endl;
        std::cout << GREEN << manager << RESET << std::endl;
        std::cout << GREEN << intern << RESET << std::endl;
        
        std::cout << CYAN << "\n[Testing grade incrementation/decrementation]" << RESET << std::endl;
        std::cout << "Incrementing " << manager.getName() << "'s grade from " << manager.getGrade() << std::endl;
        manager.incrementGrade();
        std::cout << GREEN << manager << RESET << std::endl;
        
        std::cout << "Decrementing " << manager.getName() << "'s grade from " << manager.getGrade() << std::endl;
        manager.decrementGrade();
        std::cout << GREEN << manager << RESET << std::endl;
        
        std::cout << CYAN << "\n[Testing grade boundaries]" << RESET << std::endl;
        std::cout << YELLOW << "Attempting to increment grade 1 (should fail)..." << RESET << std::endl;
        try {
            president.incrementGrade();
        } catch (std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        
        std::cout << YELLOW << "Attempting to decrement grade 150 (should fail)..." << RESET << std::endl;
        try {
            intern.decrementGrade();
        } catch (std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        
        std::cout << CYAN << "\n[Testing invalid bureaucrat creation]" << RESET << std::endl;
        
        std::cout << YELLOW << "Creating bureaucrat with grade 0 (should fail)..." << RESET << std::endl;
        try {
            Bureaucrat tooHigh("TooHigh", 0);
        } catch (std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        
        std::cout << YELLOW << "Creating bureaucrat with grade 151 (should fail)..." << RESET << std::endl;
        try {
            Bureaucrat tooLow("TooLow", 151);
        } catch (std::exception &e) {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
}

void testShrubberyCreationForm() {
    std::cout << BOLD << BLUE << "\n========== SHRUBBERY CREATION FORM TESTS ==========" << RESET << std::endl;
    std::cout << MAGENTA << "Required grades - Sign: 145, Execute: 137" << RESET << std::endl;
    
    try {
        Bureaucrat executive("Executive", 10);
        Bureaucrat assistant("Assistant", 140);
        Bureaucrat intern("Intern", 150);
        
        ShrubberyCreationForm form("garden");
        std::cout << GREEN << form << RESET << std::endl;
        
        std::cout << CYAN << "\n[Testing signing with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Intern (grade 150) attempts to sign (should fail):" << RESET << std::endl;
        intern.signForm(form);
        
        std::cout << CYAN << "\n[Testing signing with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Assistant (grade 140) attempts to sign (should succeed):" << RESET << std::endl;
        assistant.signForm(form);
        
        std::cout << CYAN << "\n[Testing execution with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Intern (grade 150) attempts to execute (should fail):" << RESET << std::endl;
        intern.executeForm(form);
        
        std::cout << CYAN << "\n[Testing execution with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Executive (grade 10) attempts to execute (should succeed):" << RESET << std::endl;
        executive.executeForm(form);
        
        std::cout << GREEN << "Check for the creation of garden_shrubbery file!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
}

void testRobotomyRequestForm() {
    std::cout << BOLD << BLUE << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << RESET << std::endl;
    std::cout << MAGENTA << "Required grades - Sign: 72, Execute: 45" << RESET << std::endl;
    
    try {
        Bureaucrat executive("Executive", 10);
        Bureaucrat manager("Manager", 50);
        Bureaucrat clerk("Clerk", 100);
        
        RobotomyRequestForm form("Bender");
        std::cout << GREEN << form << RESET << std::endl;
        
        std::cout << CYAN << "\n[Testing signing with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Clerk (grade 100) attempts to sign (should fail):" << RESET << std::endl;
        clerk.signForm(form);
        
        std::cout << CYAN << "\n[Testing signing with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Manager (grade 50) attempts to sign (should succeed):" << RESET << std::endl;
        manager.signForm(form);
        
        std::cout << CYAN << "\n[Testing execution with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Clerk (grade 100) attempts to execute (should fail):" << RESET << std::endl;
        clerk.executeForm(form);
        
        std::cout << CYAN << "\n[Testing execution with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Executive (grade 10) attempts to execute (should succeed):" << RESET << std::endl;
        executive.executeForm(form);
        
        std::cout << CYAN << "\n[Testing multiple robotomies to show randomness]" << RESET << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << YELLOW << "Robotomy attempt " << (i + 1) << ":" << RESET << std::endl;
            executive.executeForm(form);
            sleep(1); // Wait to change random seed
        }
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
}

void testPresidentialPardonForm() {
    std::cout << BOLD << BLUE << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << RESET << std::endl;
    std::cout << MAGENTA << "Required grades - Sign: 25, Execute: 5" << RESET << std::endl;
    
    try {
        Bureaucrat president("President", 1);
        Bureaucrat vicePresident("Vice President", 15);
        Bureaucrat minister("Minister", 30);
        
        PresidentialPardonForm form("Arthur Dent");
        std::cout << GREEN << form << RESET << std::endl;
        
		std::cout << CYAN << "\n[Testing execution without signing]" << RESET << std::endl;
        std::cout << YELLOW << "President (grade 1) attempts to execute (should fail):" << RESET << std::endl;
        president.executeForm(form);

        std::cout << CYAN << "\n[Testing signing with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Minister (grade 30) attempts to sign (should fail):" << RESET << std::endl;
        minister.signForm(form);
        
        std::cout << CYAN << "\n[Testing signing with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Vice President (grade 15) attempts to sign (should succeed):" << RESET << std::endl;
        vicePresident.signForm(form);
        
        std::cout << CYAN << "\n[Testing execution with insufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "Vice President (grade 15) attempts to execute (should fail):" << RESET << std::endl;
        vicePresident.executeForm(form);
        
        std::cout << CYAN << "\n[Testing execution with sufficient grade]" << RESET << std::endl;
        std::cout << YELLOW << "President (grade 1) attempts to execute (should succeed):" << RESET << std::endl;
        president.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
}

int main(void) {
    testBureaucrats();
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    
    return 0;
}

