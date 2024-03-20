/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_utils.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:50 by avassor           #+#    #+#             */
/*   Updated: 2023/12/05 17:52:44 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::strIsDigit(std::string line) {
	for (size_t i = 0; i < line.size(); ++i) {
		if (!isdigit(line[i]))
			return false;
	}
	return true;
}

bool	BitcoinExchange::strIsFloat(std::string line) {
	for (size_t i = 0; i < line.size(); ++i) {
		if (!isdigit(line[i]) && line[i] != '.')
			return false;
		if ((line[i] == '.' && i == 0) || i == line.size())
			return false;
	}
	return true;
}

bool	BitcoinExchange::isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int	BitcoinExchange::daysInMonth(int month, int year) {
	switch (month) {
		case 2:
			return BitcoinExchange::isLeapYear(year) ? 29 : 28;
		case 4: case 6: case 9: case 11:
			return 30;
		default:
			return 31;
	}
}

void	BitcoinExchange::printLine(lineCheck id) {
	switch (id) {
		case NON_DIGIT:
			std::cout << "Error: non-digit characters" << std::endl;
			break;
		case OUT_OF_RANGE:
			std::cout << "Error: out of range year" << std::endl;
			break;
		case FORMAT:
			std::cout << "Error: format is not in the form YEAR-MO-DY" << std::endl;
			break;
		case MONTH:
			std::cout << "Error: month is not in the form [(0)1-12]" << std::endl;
			break;
		case DAY:
			std::cout << "Error: day is not in the form [(0)1-31]" << std::endl;
			break;
		case WRONG_DATE:
			std::cout << "Error: day is upper than max day of specified month of specified year" << std::endl;
			break;
		case OVERFLOW:
			std::cout << "Error: value overflow" << std::endl;
			break;
		case NO_VALUE:
			std::cout << "Error: no value in line" << std::endl;
			break;
		case EMPTY:
			std::cout << "Error: empty line" << std::endl;
			break;
		case OK:
			search();
			break;
	}
}

bool	BitcoinExchange::valiDate(mapPair::const_iterator dStartIt, mapPair::const_iterator uEndIt) {
	if ((dStartIt->first.year != uEndIt->first.year) || (dStartIt->first.month != uEndIt->first.month))
		return (false);
	if (dStartIt->first.day == uEndIt->first.day)
		return (true);
	mapPair::const_iterator	nextdStartIt = dStartIt;
	++nextdStartIt;
	if (dStartIt->first.day < uEndIt->first.day && nextdStartIt->first.day > uEndIt->first.day)
		return (true);
	return (false);
}

void	BitcoinExchange::search() {
	mapPair::const_iterator	uEndIt = --_user.end();
	mapPair::const_iterator	dStartIt = _database.begin();
	mapPair::const_iterator	dEndIt = _database.end();

	for (; dStartIt != dEndIt; ++dStartIt) {
		if (valiDate(dStartIt, uEndIt))
			break;
	}
	printYear(uEndIt->first);
	std::cout << " => " << uEndIt->second << " = " << dStartIt->second * uEndIt->second << std::endl;
}

void	BitcoinExchange::printYear(Date date) {
	std::cout << date.year<< "-";
	if (date.month < 10)
		std::cout << "0" << date.month << "-";
	else
		std::cout << date.month << "-";
	if (date.day < 10)
		std::cout << "0" << date.day;
	else
		std::cout << date.day;
}
