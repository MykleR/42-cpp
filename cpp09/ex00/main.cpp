/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:50:25 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 18:35:19 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int error(const std::string &msg)
{
	std::cerr << "Error: " << msg << std::endl;
	return 1;
}

int calculatePrice(const BitcoinExchange &btc, const std::string &date, float coins)
{
	if (coins < 0)
		return error("Not a positive number.");
	if (coins > 1000)
		return error("Too large a number.");
	
	std::string found;
	float price = btc.getNearestPrice(date, found);
	std::cout << found << " => " << coins << " = " << coins * price << std::endl;
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return error("Usage: " + std::string(argv[0]) + " <filename>");
	
	BitcoinExchange btc("data.csv", ",");
	if (btc.getData().empty())
		return error("Empty database. Please check the data.csv file.");

	std::ifstream file(argv[1]);
	if (!file.is_open()) 
		return error("Cannot open file " + std::string(argv[1]));
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		float coins;
		if (btc.parseLine(line, " | ", date, coins, true))
			calculatePrice(btc, date, coins);
	}
	file.close();
	return 0;
}
