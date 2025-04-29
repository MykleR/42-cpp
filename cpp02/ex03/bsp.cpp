/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:51:24 by mykle             #+#    #+#             */
/*   Updated: 2025/04/29 12:59:38 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f;
	return (area < 0 ? -area : area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float triangle_area = getArea(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	float subArea1 = getArea(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	float subArea2 = getArea(a.getX(), a.getY(), c.getX(), c.getY(), point.getX(), point.getY());
	float subArea3 = getArea(b.getX(), b.getY(), c.getX(), c.getY(), point.getX(), point.getY());

	return ((triangle_area == subArea1 + subArea2 +  subArea3)
			&& (subArea1 != 0 && subArea2 != 0 && subArea3 != 0));
}
