/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:30:56 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 17:59:35 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_v;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &tocopy);
		~Span();

		Span& operator=(const Span &rhs);

		void	addNumber(int nbr);
		void	printVec() const;
		int		shortestSpan() const;
		int		longestSpan() const;

		template<typename Iterator>
		void	addNumbers(Iterator begin, Iterator end) {
			for (; begin != end; ++begin)
				addNumber(*begin);
		};

		class fullError : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Error: container is full";
				}
		};

		class spanError : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Error: not enough elements in the vector container";
				}
		};
};
