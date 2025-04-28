/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:24 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 18:10:05 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) >> 1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A1 = getArea(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A2 = getArea(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A3 = getArea(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed A4 = getArea(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());

	return (A1 != A2 + A3 + A4);
}
