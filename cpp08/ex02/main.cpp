/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MykleR <MykleR@42angouleme.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:14:26 by MykleR            #+#    #+#             */
/*   Updated: 2025/05/27 13:18:28 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

void testMutantStack()
{
	std::cout << BOLD << BLUE << "=== MutantStack Test ===" << RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << YELLOW << "Top: " << RESET << mstack.top() << std::endl;

	mstack.pop();
	std::cout << YELLOW << "Size: " << RESET << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << YELLOW << "Stack contents: " << RESET;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void testWithList()
{
	std::cout << BOLD << BLUE << "=== std::list Comparison ===" << RESET << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << YELLOW << "Back: " << RESET << list.back() << std::endl;

	list.pop_back();
	std::cout << YELLOW << "Size: " << RESET << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << YELLOW << "List contents: " << RESET;
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << BOLD << GREEN << "*** MUTANT STACK TESTING ***" << RESET << std::endl;

	testMutantStack();
	std::cout << std::endl;
	testWithList();

	std::cout << std::endl << BOLD << GREEN << "*** Tests completed ***" << RESET << std::endl;
}
