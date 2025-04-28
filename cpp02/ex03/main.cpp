/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:10:33 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 18:12:03 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(1, 1);
	Point c(2, 0);
	Point point(2, 0.5f);
	Point point2(1, 0.5f);
	Point point3(1, 1);

	std::cout << "Point A: " << a << std::endl;
	std::cout << "Point B: " << b << std::endl;
	std::cout << "Point C: " << c << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point " << point << " is inside the triangle." << std::endl;
	else
		std::cout << "The point " << point << " is outside the triangle." << std::endl;
	if (bsp(a, b, c, point2))
		std::cout << "The point " << point2 << " is inside the triangle." << std::endl;
	else
		std::cout << "The point " << point2 << " is outside the triangle." << std::endl;
	if (bsp(a, b, c, point3))
		std::cout << "The point " << point3 << " is inside the triangle." << std::endl;
	else
		std::cout << "The point " << point3 << " is outside the triangle." << std::endl;

	return 0;
}
