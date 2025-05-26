/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:13:16 by mykle             #+#    #+#             */
/*   Updated: 2025/05/26 11:18:03 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data = {"Example Data", 42};

	std::cout << "=== Original Data ===" << std::endl;
	std::cout <<  &data <<": Data(\"" << data.str << "\", " << data.value << ")" << std::endl;
	std::cout << "=== Serializing Data ===" << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "=== Deserializing Data ===" << std::endl;
	Data *dataPtr = Serializer::deserialize(ptr);
	std::cout <<  dataPtr << ": Data(\"" << dataPtr->str << "\", " << dataPtr->value << ")" << std::endl;
	return 0;
}
