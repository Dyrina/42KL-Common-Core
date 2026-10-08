/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:29:29 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/08 00:29:29 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) {}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {}

Point::Point(const Point& other) : m_x(other.m_x), m_y(other.m_y) {}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const
{
    return m_x;
}

Fixed Point::getY(void) const
{
    return m_y;
}