/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:01 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 13:43:21 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat r("Richard", 1);

	std::cout << r << std::endl;
	r.downGrade();
	r.upGrade();
	r.upGrade();
	r.upGrade();
	r.upGrade();
	r.upGrade();
	std::cout << r << std::endl;

	Bureaucrat m = r;
	std::cout << m << std::endl;
	m.downGrade();
	m.downGrade();
	m.downGrade();
	std::cout << m << std::endl;
	std::cout << r << std::endl;

	Bureaucrat b("Bill", 100000);
	std::cout << b << std::endl;

	Bureaucrat v("Valerie", 0);
	std::cout << v << std::endl;
	return (0);
}
