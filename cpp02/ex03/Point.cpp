/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:47:08 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 18:13:32 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


Point::Point(void) : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point &point) : _x(point._x), _y(point._y) {}
Point::~Point(void) {}
Point &Point::operator=(const Point &other) {
    if (this != &other) {
        const_cast<Fixed &>(_x) = other._x;
        const_cast<Fixed &>(_y) = other._y;
    }
    return *this;
}
float Point::getX(void) const {return (_x.toFloat());}
float Point::getY(void) const {return (_y.toFloat());}
std::ostream &operator<<(std::ostream &os, const Point &point) {
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
