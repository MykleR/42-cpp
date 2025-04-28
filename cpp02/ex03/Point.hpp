/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:45:36 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 18:13:27 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);

		Point &operator=(const Point &point);

		float getX(void) const;
		float getY(void) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream &operator<<(std::ostream &os, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
