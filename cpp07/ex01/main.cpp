/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:54:44 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 12:01:42 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>
#include <iostream>
#include <string.h>

void toupper_yes(char &c) { c = toupper(c); }
void mult2(int &i) { i *= 2; }
void printInt(const int &i) { std::cout << i << " "; }

int main(void)
{
	char str[] = "hello world";
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "Before iterating over string: " << std::endl << str << std::endl;
	iter(str, strlen(str), toupper_yes);
	std::cout << "After iterating over string: " << std::endl << str << std::endl;

	std::cout << "Before iterating and multiplying by 2: " << std::endl;
	iter(arr, sizeof(arr) / sizeof(arr[0]), printInt);
	std::cout << std::endl;
	iter(arr, sizeof(arr) / sizeof(arr[0]), mult2);
	std::cout << "After iterating and multiplying by 2: " << std::endl;
	iter(arr, sizeof(arr) / sizeof(arr[0]), printInt);
	std::cout << std::endl;
	return 0;
}
