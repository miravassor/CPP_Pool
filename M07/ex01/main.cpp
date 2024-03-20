/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:59:37 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 12:09:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	add1(double &i) {
	i = i += 1;
}

// equivalent to multiplying 1 by 2 to the power of i
void	pow2(int &i) {
	i = 1 << i;
}

int	main() {

	double	array1[] = {1.5, 2.3, 3.8, 4.45, 5.12};
	int		array2[] = {2, 3, 4, 5, 6, 7, 8};

	::iter(array1, 5, add1);
	::iter(array2, 7, pow2);

	for (int i = 0; i < 5; i++) {
		std::cout << array1[i] << " | ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 7; i++) {
		std::cout << array2[i] << " | ";
	}
	std::cout << std::endl;
	return (0);
}
