/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydylan-k <ydylan-k@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:36:17 by ydylan-k          #+#    #+#             */
/*   Updated: 2026/10/04 15:43:17 by ydylan-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point inside(2.0f, 2.0f);
    Point outside(12.0f, 12.0f);
    Point onEdge(5.0f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "Inside (expected 1): " << bsp(a, b, c, inside) << "\n";
    std::cout << "Outside (expected 0): " << bsp(a, b, c, outside) << "\n";
    std::cout << "On Edge (expected 0): " << bsp(a, b, c, onEdge) << "\n";
    std::cout << "On Vertex (expected 0): " << bsp(a, b, c, onVertex) << "\n";

    return 0;
}