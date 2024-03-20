/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:05:45 by avassor           #+#    #+#             */
/*   Updated: 2023/11/27 14:29:16 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(42);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longuest span: " << sp.longestSpan() << std::endl;

	std::cout << "Adding numbers with range of iterators from vector:" << std::endl;
	Span sp2 = Span(3);
	std::vector<int>	v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	sp2.addNumbers(v.begin(), v.end());
	sp2.printVec();

	std::cout << "Adding more numbers than capacity:" << std::endl;
	Span sp3 = Span(3);
	std::vector<int>	v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	try {
		sp3.addNumbers(v2.begin(), v2.end());
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	sp3.printVec();

	std::cout << "Trying shortestSpan() on an empty Class:" << std::endl;
	Span sp4 = Span(0);
	try {
		sp4.shortestSpan();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
