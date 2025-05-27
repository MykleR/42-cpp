/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:25:37 by mykle             #+#    #+#             */
/*   Updated: 2025/05/27 10:54:25 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <limits>

Span::~Span() {}

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize),
	_array(other._array) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_array = other._array;
		_maxSize = other._maxSize;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_array.size() >= _maxSize)
		throw std::length_error("Span is full");
	_array.push_back(number);
}

void Span::addNumber(std::vector<int>::const_iterator start,
		std::vector<int>::const_iterator end)
{
    if (std::distance(start, end) + _array.size() > _maxSize)
        throw std::runtime_error("no slot left");
    _array.insert(_array.end(), start, end);
}

unsigned int Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<int> sorted = _array;
	std::sort(sorted.begin(), sorted.end());
	unsigned value = std::numeric_limits<unsigned>::max();

	for (unsigned i = 1; i < _array.size(); ++i)
		value = std::min(value, static_cast<unsigned>(sorted[i] - sorted[i - 1]));
	return value;
}

unsigned int Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::logic_error("Not enough elements to find a span");
	return (*std::max_element(_array.begin(), _array.end()) -
            *std::min_element(_array.begin(), _array.end()));
}
