/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:03:41 by mykle             #+#    #+#             */
/*   Updated: 2025/05/29 14:14:31 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

#define MAX_OUTPUT_SIZE 20

template<typename Container>
void printContainer(const Container& container, const std::string& label)
{
	std::cout << label;
	size_t i = 0;
	for (; i < container.size() && i < MAX_OUTPUT_SIZE; ++i)
		std::cout << container[i] << " ";
	if (i >= MAX_OUTPUT_SIZE) std::cout << "... ";
	std::cout << std::endl;
}

template<typename Container>
double testSort(const Container& container, Container &sorted)
{
	auto start = std::chrono::high_resolution_clock::now();
	sorted = PmergeMe<Container>::sort(container);
	auto end = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() / 1000.0;
}

int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [integers > 0...]" << std::endl;
		return 1;
	}
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			std::cerr << "Error: Only integers > 0 allowed" << std::endl;
			return 1;
		}
		vec.push_back(num);
		deq.push_back(num);
	}
	printContainer(vec, "Before: ");
	double time1 = testSort(vec, vec);
	double time2 = testSort(deq, deq);
	printContainer(vec, "After:  ");

	std::cout << "Time to process a range of " << vec.size() 
				<< " elements with std::vector<int>:  " << time1 << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() 
				<< " elements with std::deque<int>: " << time2 << " us" << std::endl;
}
