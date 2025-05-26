/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:56:03 by mrouves           #+#    #+#             */
/*   Updated: 2025/05/26 18:15:34 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <limits>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Span 
{
private:
	std::vector<T> _elements;
	unsigned int _maxSize;
public:
	Span();
	~Span();
	Span(unsigned int n);
	Span(const Span<T> &other);
	Span<T> &operator=(const Span<T> &other);

	void addNumber(T number);
	T shortestSpan() const;
	T longestSpan() const;
};

template <typename T> Span<T>::~Span() {}

template <typename T> Span<T>::Span() : _maxSize(0), _elements() {}

template <typename T> Span<T>::Span(unsigned int n) : _maxSize(n), _elements() {}

template <typename T>
Span<T>::Span(const Span<T> &other) : _maxSize(other._maxSize)
{
	if (this != &other)
	{
		_elements = other._elements;
		_maxSize = other._maxSize;
	}
	return *this;
}

template <typename T>
Span<T> &Span<T>::operator=(const Span<T> &other)
{
	if (this != &other)
	{
		_elements = other._elements;
		_maxSize = other._maxSize;
	}
	return *this;
}

template <typename T>
void Span<T>::addNumber(T number)
{
	if (_elements.size() >= _maxSize)
		throw std::length_error("Span is full");
	_elements.push_back(number);
}

template <typename T>
T Span<T>::shortestSpan() const
{
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<T> sortedElements = _elements;
	std::sort(sortedElements.begin(), sortedElements.end());

	T minSpan = std::numeric_limits<T>::max();
	for (size_t i = 1; i < sortedElements.size(); ++i)
	{
		T span = sortedElements[i] - sortedElements[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}
