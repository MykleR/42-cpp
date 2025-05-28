/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:34:47 by mykle             #+#    #+#             */
/*   Updated: 2025/05/28 18:36:02 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {*this = other;}

BitcoinExchange::BitcoinExchange(const std::string& filename, const std::string& separator)
{
	_data.clear();
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		float price;
		if (parseLine(line, separator, date, price, false))
			_data[date] = price;
	}
	file.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
	int day = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	return year > 0 && month > 0 && day > 0 && month <= 12 && day <= 31;
}

bool BitcoinExchange::stringToFloat(const std::string& str, float& result) const
{
	char *endptr;
	result = static_cast<float>(std::strtod(str.c_str(), &endptr));
	return *endptr == 0;
}

bool BitcoinExchange::parseLine(const std::string& line, const std::string &sep,
		std::string& date, float& price,  bool verbose) const
{
	size_t sepPos = line.find(sep);
	if (sep.empty() || line.empty() || sepPos == std::string::npos)
	{
		if (verbose) std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	date = line.substr(0, sepPos);
	if (!isValidDate(date))
	{
		if (verbose) std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	std::string price_str = line.substr(sepPos + sep.length());
	return stringToFloat(price_str, price);
}

const std::map<std::string, float>& BitcoinExchange::getData() const
{
	return _data;
}

bool BitcoinExchange::getPrice(const std::string& date, float& price) const
{
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	bool found = (it != _data.end());
	price = (found) ? it->second : 0.0f;
	return (found);
}

float BitcoinExchange::getNearestPrice(const std::string& date, std::string& found) const
{
	if (_data.empty())
		return 0.0f;
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it == _data.end())
		--it; // Get the last available date
	found = it->first;
	return it->second;
}
