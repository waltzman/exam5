/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlobun <rlobun@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:58:06 by rlobun            #+#    #+#             */
/*   Updated: 2026/09/29 16:51:02 by rlobun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this main was made by flmarsou <flmarsou@student.42.fr>  
/**/

#include "bigint.hpp"

int	main()
{
	const bigint	a(42);
	bigint			b(21);
	bigint			c;
	bigint			d(1337);
	bigint			e(d);

	std::cout << "=== Ostream ====================" << std::endl;
	std::cout << "a = " << a << "\t\t| should be 42" << std::endl;
	std::cout << "b = " << b << "\t\t| should be 21" << std::endl;
	std::cout << "c = " << c << "\t\t| should be 0" << std::endl;
	std::cout << "d = " << d << "\t| should be 1337" << std::endl;
	std::cout << "e = " << e << "\t| should be 1337" << std::endl;

	std::cout << "\n=== Additions ===================" << std::endl;
	std::cout << "a + b = " << a + b << "\t| should be 63" << std::endl;
	std::cout << "(c += a) = " << (c += a) << "\t| should be 42" << std::endl;

	std::cout << "\n=== Increments ==================" << std::endl;
	std::cout << "b = " << b << "\t\t| should be 21" << std::endl;
	std::cout << "++b = " << ++b << "\t| should be 22" << std::endl;
	std::cout << "b++ = " << b++ << "\t| should be 22" << std::endl;

	std::cout << "\n=== Shifts ======================" << std::endl;
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << "\t| should be 230000000042" << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << "\t\t| should be 13370000" << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << "\t\t| should be 133700" << std::endl;

	std::cout << "\n=== Ostream =====================" << std::endl;
	std::cout << "a = " << a << "\t\t| should be 42" << std::endl;
	std::cout << "d = " << d << "\t| should be 133700" << std::endl;

	std::cout << "\n=== Comparisons =================" << std::endl;
	std::cout << "(d < a) = " << (d < a) << "\t| should be 0" << std::endl;
	std::cout << "(d <= a) = " << (d <= a) << "\t| should be 0" << std::endl;
	std::cout << "(d > a) = " << (d > a) << "\t| should be 1" << std::endl;
	std::cout << "(d >= a) = " << (d >= a) << "\t| should be 1" << std::endl;
	std::cout << "(d == a) = " << (d == a) << "\t| should be 0" << std::endl;
	std::cout << "(d != a) = " << (d != a) << "\t| should be 1" << std::endl;
}
