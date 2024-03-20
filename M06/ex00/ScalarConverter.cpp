/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:13 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 16:26:11 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string str) {
	Identifier	id;

	id = getType(str);
	switch (id) {
		case CHAR:
			isChar(str);
			break;
		case INT:
			isInt(str);
			break;
		case DOUBLE:
			isDouble(str);
			break;
		case FLOAT:
			isFloat(str);
			break;
		case NANF:
			isNan();
			break;
		case INF:
			isInf(str);
			break;
		case ERROR:
			std::cout << "Illegal formatting or character, try again." << std::endl;
			break;
	}
}

Identifier	getType(const std::string str) {
	if (str.empty())
		return (ERROR);
	else if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("-inf") || !str.compare("+inf"))
		return (INF);
	else if (!str.compare("nan") || !str.compare("nanf"))
		return (NANF);
	else if (str.length() == 1 && !isdigit(*str.begin()) && !iscntrl(*str.begin()))
		return (CHAR);
	else if (!isdigit(*str.begin()) && !isSign(*str.begin()))
		return (ERROR);
	else if (isTarget(str, '.') && (*str.begin() != '.') && (str[str.length() - 1] != '.') && (str[str.length() - 1] == 'f') && checkNum(str))
		return (FLOAT);
	else if (isTarget(str, '.') && (*str.begin() != '.') && (str[str.length() - 1] != '.') && checkNum(str))
		return (DOUBLE);
	else if (checkNum(str) && atof(str.c_str()) > INT_MIN && atof(str.c_str()) < INT_MAX)
		return (INT);
	return (ERROR);
}

bool	isSign(const char ch) {
	if (ch != '+' && ch != '-')
		return (0);
	return (1);
}

bool	isTarget(const std::string str, char target) {
	size_t	first = str.find(target);
	size_t	last = str.rfind(target);

	return ((first == last) && (first != std::string::npos));
}

bool	checkNum(const std::string str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '-' && str[i] != '+')
			return (0);
	}
	return (1);
}
