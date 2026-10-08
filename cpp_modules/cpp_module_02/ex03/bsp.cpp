/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:29:33 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/08 00:29:33 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(Point const a, Point const b, Point const p)
{
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - 
           (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed zero(0);

    // 1. Calculate orientation for each of the three directed edges
    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);

    // 2. Point is strictly inside counter-clockwise winding
    bool allPositive = (d1 > zero) && (d2 > zero) && (d3 > zero);

    // 3. Point is strictly inside clockwise winding
    bool allNegative = (d1 < zero) && (d2 < zero) && (d3 < zero);

    // If point is on an edge or vertex, at least one cross product will equal 0,
    // which makes both allPositive and allNegative evaluate to false.
    return (allPositive || allNegative);
}