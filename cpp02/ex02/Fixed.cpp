/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:09:09 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 12:41:46 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::~Fixed(void){}
Fixed::Fixed(void) : _fixedNum(0){}
Fixed::Fixed(const Fixed &new_value) {*this = new_value;}
Fixed::Fixed(const int new_value) : _fixedNum(new_value << _fractionalPart){}
Fixed::Fixed(const float new_value) : _fixedNum((int)roundf((new_value * (1 << _fractionalPart)))){}


int Fixed::getRawBits(void) const {return (_fixedNum);}
void Fixed::setRawBits(int const raw) {_fixedNum = raw;}
int Fixed::toInt(void) const {return (_fixedNum >> _fractionalPart);}
float Fixed::toFloat(void) const {return (float)_fixedNum / (1 << _fractionalPart);}

bool Fixed::operator>(const Fixed &value) const {return (_fixedNum > value.getRawBits());}
bool Fixed::operator<(const Fixed &value) const {return (_fixedNum < value.getRawBits());}
bool Fixed::operator>=(const Fixed &value) const {return (_fixedNum >= value.getRawBits());}
bool Fixed::operator<=(const Fixed &value) const {return (_fixedNum <= value.getRawBits());}
bool Fixed::operator==(const Fixed &value) const {return (_fixedNum == value.getRawBits());}
bool Fixed::operator!=(const Fixed &value) const {return (_fixedNum != value.getRawBits());}
Fixed Fixed::operator+(const Fixed &value) const {return (Fixed(this->toFloat() + value.toFloat()));}
Fixed Fixed::operator-(const Fixed &value) const {return (Fixed(this->toFloat() - value.toFloat()));}
Fixed Fixed::operator*(const Fixed &value) const {return (Fixed(this->toFloat() * value.toFloat()));}
Fixed Fixed::operator/(const Fixed &value) const
{
	if (value.toFloat() == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / value.toFloat()));
}

Fixed &Fixed::operator=(const Fixed &value)
{
    if (this != &value)
        _fixedNum = value.getRawBits();
    return (*this);
}
Fixed &Fixed::operator++(void)
{
	_fixedNum++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_fixedNum++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	_fixedNum--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixedNum--;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {return (a < b ? a : b);}
Fixed &Fixed::max(Fixed &a, Fixed &b) {return (a > b ? a : b);}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return (a < b ? a : b);}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return (a > b ? a : b);}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
