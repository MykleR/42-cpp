/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 19:20:29 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

// Colors for prettier output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void testIntern() {
    std::cout << BOLD << BLUE << "\n========== INTERN TESTS ==========" << RESET << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        
        std::cout << CYAN << "\n[Testing form creation with valid names]" << RESET << std::endl;
        
        AForm* scForm = someRandomIntern.makeForm("shrubbery creation", "garden");
        std::cout << YELLOW << "Testing shrubbery creation form:" << RESET << std::endl;
        if (scForm) {
            std::cout << GREEN << *scForm << RESET << std::endl;
            boss.signForm(*scForm);
            boss.executeForm(*scForm);
            delete scForm;
        }
        
        AForm* rrForm = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << YELLOW << "\nTesting robotomy request form:" << RESET << std::endl;
        if (rrForm) {
            std::cout << GREEN << *rrForm << RESET << std::endl;
            boss.signForm(*rrForm);
            boss.executeForm(*rrForm);
            delete rrForm;
        }
        
        AForm* ppForm = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << YELLOW << "\nTesting presidential pardon form:" << RESET << std::endl;
        if (ppForm) {
            std::cout << GREEN << *ppForm << RESET << std::endl;
            boss.signForm(*ppForm);
            boss.executeForm(*ppForm);
            delete ppForm;
        }
        
        std::cout << CYAN << "\n[Testing form creation with invalid name]" << RESET << std::endl;
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
        if (!invalidForm) {
            std::cout << GREEN << "Correctly returned nullptr for invalid form name" << RESET << std::endl;
        } else {
            std::cout << RED << "Error: Should have returned nullptr" << RESET << std::endl;
            delete invalidForm;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
}


int main(void) {
   testIntern();

    return 0;
}

