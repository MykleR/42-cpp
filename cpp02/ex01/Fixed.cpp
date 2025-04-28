/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:09:09 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 17:28:47 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _fixedNum(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = new_value;
}

Fixed::Fixed(const float new_value) : _fixedNum((int)roundf((new_value * (1 << _fractionalPart))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int new_value) : _fixedNum(new_value << _fractionalPart)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (float)_fixedNum / (1 << _fractionalPart);
}

int Fixed::toInt(void) const
{
	return (_fixedNum >> _fractionalPart);
}

int Fixed::getRawBits(void) const
{
    return (_fixedNum);
}

void Fixed::setRawBits(int const raw)
{
	_fixedNum = raw;
}

Fixed &Fixed::operator=(const Fixed &value)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
        _fixedNum = value.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
