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

static Fixed	crossProduct( const Point& a, const Point& b, const Point& p )
{
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - 
           (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool	bsp( const Point& a, const Point& b, const Point& c, const Point& point )
{
    Fixed zero(0);

    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);
    bool allPositive = (d1 > zero) && (d2 > zero) && (d3 > zero);
    bool allNegative = (d1 < zero) && (d2 < zero) && (d3 < zero);
    return (allPositive || allNegative);
}