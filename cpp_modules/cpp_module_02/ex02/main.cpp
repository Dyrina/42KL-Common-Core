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

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	std::cout << "Default Test" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	{
		std::cout << "\nConstructors & Conversion\n";
		Fixed alpha;
		Fixed beta(10);
		Fixed omega(42.42f);
		Fixed delta(omega);
		
		std::cout << "alpha (default) : " << alpha << " | toInt: " << alpha.toInt() << " | toFloat: " << alpha.toFloat() << "\n";
		std::cout << "beta (int 10)  : " << beta << " | toInt: " << beta.toInt() << " | toFloat: " << beta.toFloat() << "\n";
		std::cout << "omega (float)   : " << omega << " | toInt: " << omega.toInt() << " | toFloat: " << omega.toFloat() << "\n";
		std::cout << "delta (copy omega)  : " << delta << " | toInt: " << delta.toInt() << " | toFloat: " << delta.toFloat() << "\n";
	}
	{
		std::cout << "\nArithmetic Operaters (+, -, *, /)\n";
		Fixed x(10.5f);
		Fixed y(2.0f);
			
		std::cout << "x (" << x << ") + y (" << y << ") = " << (x + y) << "\n";
		std::cout << "x (" << x << ") - y (" << y << ") = " << (x - y) << "\n";
		std::cout << "x (" << x << ") * y (" << y << ") = " << (x * y) << "\n";
		std::cout << "x (" << x << ") / y (" << y << ") = " << (x / y) << "\n";
	}
	{
		std::cout << "\nComparison Operators\n";
		Fixed p(5.05f);
		Fixed q(5.05f);
		Fixed r(10.0f);
		
		std::cout << std::boolalpha;
		std::cout << "p == q : " << (p == q) << "\n";
		std::cout << "p != r : " << (p != r) << "\n";
		std::cout << "p < r  : " << (p < r)  << "\n";
		std::cout << "r > p  : " << (r > p)  << "\n";
		std::cout << "p <= q : " << (p <= q) << "\n";
		std::cout << "r >= p : " << (r >= p) << "\n";
	}	
	{
		std::cout << "\nDecrement & Increment Operators (--)\n";
		Fixed dec(6.0f);
		Fixed inc(7.0f);

		std::cout << "dec initial : " << dec << "\n";
		std::cout << "--dec       : " << --dec << "\n";
		std::cout << "dec after   : " << dec << "\n";
		std::cout << "dec--       : " << dec-- << "\n";
		std::cout << "dec final   : " << dec << "\n";

		std::cout << "inc initial : " << inc << "\n";
		std::cout << "++inc       : " << ++inc << "\n";
		std::cout << "inc after   : " << inc << "\n";
		std::cout << "inc++       : " << inc++ << "\n";
		std::cout << "inc final   : " << inc << "\n";
	}
	{
		std::cout << "\nMin & Max Overloads\n";
		Fixed m1(3.14f);
		Fixed m2(6.28f);
		const Fixed c1(100.5f);
		const Fixed c2(200.5f);
		
		std::cout << "min(m1, m2)     : " << Fixed::min(m1, m2) << "\n";
		std::cout << "max(m1, m2)     : " << Fixed::max(m1, m2) << "\n";
		std::cout << "min(const c1, c2): " << Fixed::min(c1, c2) << "\n";
		std::cout << "max(const c1, c2): " << Fixed::max(c1, c2) << "\n";
	}
	{
		std::cout << "\nRaw Bits Getter / Setter\n";
		Fixed rawTest;
		rawTest.setRawBits(256); // 256 in fixed-point (8 fractional bits) equals 1.0f
		std::cout << "rawBits 256 as float: " << rawTest.toFloat() << "\n";
		std::cout << "getRawBits(): " << rawTest.getRawBits() << "\n";
	}
	return 0;
}
