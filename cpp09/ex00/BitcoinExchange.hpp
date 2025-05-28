/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:34:24 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 18:23:07 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;

	bool isValidDate(const std::string &date) const;

	bool stringToFloat(const std::string &str, float &result) const;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange(const std::string &filename, const std::string &separator);
	BitcoinExchange& operator=(const BitcoinExchange &other);
	
	bool parseLine(const std::string &line, const std::string &sep,
		std::string &date, float &price, bool verbose) const;

	// GETTERS
	bool getPrice(const std::string &date, float &price) const;
	float getNearestPrice(const std::string &date, std::string &found) const;
	const std::map<std::string, float>& getData() const;
};
