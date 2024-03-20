/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:22:51 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 17:37:42 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	isChar(const std::string str) {
	char	ch = str[0];

	std::cout << "char:\t" << "'" << ch << "'" << std::endl;
	std::cout << "int:\t" << static_cast<int>(ch) << std::endl;
	std::cout << "float:\t" << static_cast<float>(ch) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(ch) << ".0" << std::endl;
}

void		isInt(const std::string str) {
	int	i = atoi(str.c_str());

	printChar(i);
	std::cout << "int:\t" << i << std::endl;
	std::cout << "float:\t" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(i) << ".0" << std::endl;
}


void		isDouble(const std::string str) {
	double d = atof(str.c_str());

	printChar(d);
	std::cout << "int:\t";
	if (static_cast<int>(d) < INT_MIN && static_cast<int>(d) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout <<  static_cast<int>(d) << std::endl;
	std::cout << "float:\t" << static_cast<float>(d);
	if (isWholeNbr(d))
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double:\t" << d;
	if (isWholeNbr(d))
		std::cout << ".0";
	std::cout << std::endl;
}


void		isFloat(const std::string str) {
	double d = atof(str.c_str());

	printChar(d);
	std::cout << "int:\t";
	if (static_cast<int>(d) < INT_MIN && static_cast<int>(d) > INT_MAX && d != 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float:\t" << static_cast<float>(d);
	if (isWholeNbr(d))
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double:\t" << d;
	if (isWholeNbr(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void	isNan() {
	std::cout << "char:\timpossible" << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	std::cout << "float:\tnanf" << std::endl;
	std::cout << "double\tnan" << std::endl;
}

void	isInf(const std::string str) {
	std::cout << "char:\timpossible " << std::endl;
	std::cout << "int:\timpossible" << std::endl;
	std::cout << "float:\t";
	if (str[str.length() - 1] == 'f' && (BeforeLast(str) == 'f'))
		std::cout << str << std::endl;
	else
		std::cout << str << 'f' << std::endl;
	std::cout << "double:\t";
	if (str[str.length() - 1] == 'f' && (BeforeLast(str) == 'f'))
		std::cout << str.substr(0, str.size() - 1) << std::endl;
	else
		std::cout << str << std::endl;
}

void	printChar(double c) {
	std::cout << "char:\t";
	if (c < 0 || c > 127)
		std::cout << "impossible" << std::endl;
	else if (iscntrl(c))
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
}

bool		isWholeNbr(double d) {
	return (std::fmod(d, 1.0) == 0.0);
}

char		BeforeLast(std::string str) {
	return (str.at(str.size() - 2));
}

