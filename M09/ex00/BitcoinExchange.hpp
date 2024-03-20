/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:37:48 by avassor           #+#    #+#             */
/*   Updated: 2023/12/05 17:53:03 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <cfloat>
#include <climits>


enum lineCheck {
	OK,
	MONTH,
	DAY,
	NO_VALUE,
	OUT_OF_RANGE,
	NON_DIGIT,
	FORMAT,
	WRONG_DATE,
	OVERFLOW,
	EMPTY
};

struct Date {
	int	year;
	int	month;
	int	day;

	bool operator<(const Date& other) const {
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		return day < other.day;
	}
};

typedef std::multimap<Date, float> mapPair;

class BitcoinExchange {
	private:
		std::multimap<Date, float>	_database;
		std::multimap<Date, float>	_user;

		std::pair<Date, float>	extractDb(std::string line);
		int			daysInMonth(int month, int year);
		bool		isLeapYear(int year);
		void		extractUser(int year, int month, int day, float value);
		bool		strIsDigit(std::string line);
		bool		strIsFloat(std::string line);
		bool		valiDate(mapPair::const_iterator dStartIt, mapPair::const_iterator uEndIt);
		void		search();
		void		printYear(Date date);
		lineCheck	idLine(std::string line);
	public:
		BitcoinExchange() {};
		~BitcoinExchange() {};
		BitcoinExchange(BitcoinExchange& tocopy);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);
		void	loadData(std::ifstream &file);
		void	parsePrint(std::ifstream &arg);
		void	printLine(lineCheck id);
};
