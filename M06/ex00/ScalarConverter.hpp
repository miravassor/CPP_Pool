/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:07 by avassor           #+#    #+#             */
/*   Updated: 2023/11/20 18:09:56 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>

enum Identifier {
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	NANF,
	INF,
	ERROR
};

class ScalarConverter {
	public:
	static void	convert(const std::string str);
};

Identifier	getType(std::string str);
bool		isSign(const char ch);
bool		isTarget(const std::string str, char target);
bool		checkNum(const std::string str);
void		isChar(const std::string str);
void		isInt(const std::string str);
void		isFloat(const std::string str);
void		isDouble(const std::string str);
void		isNan();
void		isInf(const std::string str);
void		printChar(double c);
bool		isWholeNbr(double d);
char		BeforeLast(std::string str);
