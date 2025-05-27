/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:56:03 by mrouves           #+#    #+#             */
/*   Updated: 2025/05/27 10:54:34 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span 
{
private:
	std::vector<int> _array;
	unsigned int _maxSize;

public:
	Span();
	~Span();
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);

	void addNumber(int number);
	void addNumber(std::vector<int>::const_iterator begin,
			std::vector<int>::const_iterator end);

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

