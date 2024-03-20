/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:38:01 by avassor           #+#    #+#             */
/*   Updated: 2023/12/05 17:53:31 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Build / Unbuild

BitcoinExchange::BitcoinExchange(BitcoinExchange& tocopy) {
	*this = tocopy;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_database = rhs._database;
		_user = rhs._user;
	}
	return (*this);
}

// Methods

void	BitcoinExchange::loadData(std::ifstream &file) {
	std::string line;
	std::getline(file, line);
	for (std::string line; std::getline(file, line);)
		_database.insert(extractDb(line));
}

std::pair<Date, float> BitcoinExchange::extractDb(std::string line) {
	std::string	year = line.substr(0, 4);
	std::string	month = line.substr(5, 2);
	std::string	day = line.substr(8, 2);
	std::string	value = line.substr(11);

	std::pair<Date, float>	res;
	res.first.day = atoi(day.c_str());
	res.first.month = atoi(month.c_str());
	res.first.year = atoi(year.c_str());
	res.second = atof(value.c_str());
	return res;
}

void	BitcoinExchange::extractUser(int year, int month, int day, float value) {
	std::pair<Date, float>	res;
	res.first.day = day;
	res.first.month = month;
	res.first.year = year;
	res.second = value;
	_user.insert(res);
}


void	BitcoinExchange::parsePrint(std::ifstream &arg) {
	int	i = 0;
	for (std::string line; std::getline(arg, line);) {
		lineCheck	id = idLine(line);
		if (!i && id != OK)
			;
		else
			printLine(id);
		++i;
	}
}

lineCheck	BitcoinExchange::idLine(std::string line) {
	double	dtemp = 0;
	float	ftemp = 0;
	int		month = 0;
	int		year = 0;
	int		day = 0;

	if (!line.size())
		return EMPTY;
	std::string	stemp = line.substr(0, 4);
	if (!strIsDigit(stemp))
		return NON_DIGIT;
	year = atoi(stemp.c_str());
	if (!(year >= 2009 && year <= 2022))
		return OUT_OF_RANGE;
	stemp = line.substr(4, 1);
	if (stemp.compare("-") != 0)
		return FORMAT;
	stemp = line.substr(5, 2);
	if (!strIsDigit(stemp))
		return NON_DIGIT;
	month = atoi(stemp.c_str());
	if (!(month >= 1 && month <= 12))
		return MONTH;
	stemp = line.substr(7, 1);
	if (stemp.compare("-") != 0)
		return FORMAT;
	stemp = line.substr(8, 2);
	if (!strIsDigit(stemp))
		return NON_DIGIT;
	day = atoi(stemp.c_str());
	if (!(day >= 1 && day <= 31))
		return FORMAT;
	if (daysInMonth(month, year) <= day)
		return WRONG_DATE;
	stemp = line.substr(10, 3);
	if (!stemp.size())
		return NO_VALUE;
	if (stemp.compare(" | ") != 0)
		return FORMAT;
	stemp = line.substr(13);
	if (!stemp.size())
		return NO_VALUE;
	if (!strIsFloat(stemp))
		return FORMAT;
	dtemp = atof(stemp.c_str());
	if (dtemp < INT_MIN || dtemp > INT_MAX)
		return OVERFLOW;
	ftemp = atof(stemp.c_str());
	extractUser(year, month, day, ftemp);
	return OK;
}

// void	BitcoinExchange::printDb() {
// 	std::cout << "Database:" << std::endl;
// 	for (mapPair::const_iterator it = _database.begin(); it != _database.end(); ++it)
// 		std::cout << "First: " << it->first.year << "-" << it->first.month << "-" << it->first.day << ", Second: " << it->second << std::endl;
// 	std::cout << "User input:" << std::endl;
// 	for (mapPair::const_iterator it = _user.begin(); it != _user.end(); ++it)
// 		std::cout << "First: " << it->first.year << "-" << it->first.month << "-" << it->first.day << ", Second: " << it->second << std::endl;
// }
