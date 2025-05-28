/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 21:03:41 by mykle             #+#    #+#             */
/*   Updated: 2025/05/29 01:02:31 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

template<typename Container>
void printContainer(const Container& container, const std::string& label) {
    std::cout << label;
    for (const auto& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void testSort(Container& container, const std::string& containerType) {
    auto start = std::chrono::high_resolution_clock::now();
    Container sorted = PmergeMe<Container>::sort(container);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Convert to microseconds
    
    std::cout << "Time to process a range of " << container.size() 
              << " elements with " << containerType << ": " 
              << duration.count() / 1000.0 << " us" << std::endl;
    
    printContainer(sorted, "After:  ");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [positive integers...]" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Only positive integers allowed" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }
    
    printContainer(vec, "Before: ");
    
    testSort(vec, "std::vector<int>");
    testSort(deq, "std::deque<int>");
    
    return 0;
}
