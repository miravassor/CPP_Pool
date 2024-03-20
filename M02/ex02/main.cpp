/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:16:26 by avassor           #+#    #+#             */
/*   Updated: 2023/09/26 09:08:08 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main(void) {
// 	Fixed	a(2.5f);
// 	Fixed	b(5.5f);

// 	std::cout << Fixed::max(a, b) << std::endl;
// 	std::cout << Fixed::min(a, b) << std::endl;
// 	std::cout << Fixed::max((Fixed const)a, (Fixed const)b) << std::endl;
// 	std::cout << Fixed::min((Fixed const)a, (Fixed const)b) << std::endl;
// 	std::cout << ((a > b) ? a : b) << std::endl;
// 	std::cout << ((a < b) ? a : b) << std::endl;
// 	std::cout << ((a >= b) ? a : b) << std::endl;
// 	std::cout << ((a <= b) ? a : b) << std::endl;
// 	std::cout << b - a << std::endl;
// 	std::cout << b + a << std::endl;
// 	std::cout << b / a << std::endl;
// 	std::cout << b / 0 << std::endl;
// 	std::cout << b * a << std::endl;
// 	std::cout << ++b << std::endl;
// 	std::cout << b++ << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << --b << std::endl;
// 	std::cout << b-- << std::endl;
// 	std::cout << b << std::endl;
// 	Fixed c = a;
// 	if (c == a)
// 		std::cout << "same old same" << std::endl;
// 	if (b != a)
// 		std::cout << "not same not" << std::endl;
// 	return (0);
// }

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}
