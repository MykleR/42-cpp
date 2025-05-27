/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MykleR <MykleR@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:04:32 by MykleR            #+#    #+#             */
/*   Updated: 2025/05/27 13:11:03 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <exception>

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

void testBasic()
{
    std::cout << YELLOW << "\n=== Basic Test ===" << RESET << std::endl;

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << BLUE << "Numbers: 6, 3, 17, 9, 11" << RESET << std::endl;
	std::cout << GREEN << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
	std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
}

void testLarge()
{
	std::cout << YELLOW << "\n=== Large Collection Test ===" << RESET << std::endl;

	Span sp(10000);
	std::vector<int> numbers;

	for (int i = 0; i < 10000; i++)
		numbers.push_back(i);
	sp.addNumber(numbers.begin(), numbers.end());

	std::cout << BLUE << "Added 10,000 numbers (0 to 9999)" << RESET << std::endl;
	std::cout << GREEN << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
	std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;
}

void testExceptions()
{
	std::cout << YELLOW << "\n=== Exception Tests ===" << RESET << std::endl;

	try {
		Span empty(5);
		empty.shortestSpan();
	} catch (std::exception& e) {
		std::cout << GREEN << "Empty span exception: " << e.what() << RESET << std::endl;
	}
	try {
		Span full(2);
		full.addNumber(1);
		full.addNumber(2);
		full.addNumber(3);
	} catch (std::exception& e) {
		std::cout << GREEN << "Full span exception: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::cout << BLUE << "* Testing Span Class" << RESET << std::endl;

	try {
		testBasic();
		testLarge();
		testExceptions();
		std::cout << GREEN << "\n✓ All tests completed!" << RESET << std::endl;
	}
	catch (std::exception& e) {
		std::cout << RED << "\n❌ Test failed: " << e.what() << RESET << std::endl;
	}
}
