/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:41:04 by mykle             #+#    #+#             */
/*   Updated: 2025/05/19 22:51:44 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdint>
#include <limits>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	return *this;
}

int isNaN(const std::string &str) {
    return (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" ||
            str == "+inf" || str == "+inff" || str == "inf" || str == "inff");
}

template <typename T> void convertToChar(T value) {
	if (value < std::numeric_limits<char>::min() ||
		value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(value)) 
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

template <typename T> void convertToFloat(T value) {
	if (value < std::numeric_limits<float>::lowest() ||
		value > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << (
			ceil(value) == value ? ".0f" : "f") << std::endl;
}

template <typename T> void convertToDouble(T value) {
	if (value < std::numeric_limits<double>::lowest() ||
		value > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << (
			ceil(value) == value ? ".0" : "") << std::endl;
}

template <typename T> void convertToInt(T value) {
	if (static_cast<int_fast64_t>(value) > std::numeric_limits<int>::max() ||
		static_cast<int_fast64_t>(value) < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

template <typename T> T strToType(const std::string &str)
{
  std::stringstream ss(str);
  T result;
  ss >> result;
  return result;
}

template <> char strToType<char>(const std::string &str) { return (str[0]); }

ScalarType getStringType(const std::string &str) {

    char *error;

    if (isNaN(str))
        return (TYPE_NAN);

    if (str.length() == 1 && !isdigit(str[0]))
        return (TYPE_CHAR);

    (void)strtol(str.c_str(), &error, 10);
    if (*error == 0)
        return (error - str.c_str() <= 11 ? TYPE_INT : TYPE_UNKNOWN);

    double val = strtod(str.c_str(), &error);
    if (val == HUGE_VAL_F64 || val == -HUGE_VAL_F64)
        return (TYPE_UNKNOWN);
    if (*error == 0)
        return (TYPE_DOUBLE);

    if ((*error == 'f' && *(error + 1) == 0) &&
        std::fabs(val) <= std::numeric_limits<float>::max())
        return (TYPE_FLOAT);
    return (TYPE_UNKNOWN);
}

template <typename T> void __convert(const std::string &str) {
  T value = strToType<T>(str);
  convertToChar(value);
  convertToInt(value);
  convertToFloat(value);
  convertToDouble(value);
}

void __convert_unknow(const std::string &str) {
    std::cout << str << " does not convert to any type" << std::endl;
}

void __convert_nan(const std::string &str) {
    std::string input;

    if (str[0] == 'n')
        input = "nan";
    else if (str[0] == '-')
        input = "-inf";
    else
        input = "+inf";

    std::cout << "char: impossible!\n";
    std::cout << "int: impossible!\n";
    std::cout << "float: " << input << "f\n";
    std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convert(const std::string &str) {

    void (*convertFunc[])(const std::string &) = {
        &__convert<char>,   &__convert<int_fast64_t>, &__convert<float>,
        &__convert<double>, &__convert_nan,  &__convert_unknow};

    ScalarType type = getStringType(str);
    convertFunc[type](str);
}

