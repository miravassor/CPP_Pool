/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:31:20 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 17:59:52 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Builders / Unbuilders

Span::Span() : _N(1) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &tocopy)
: _N(tocopy._N), _v(tocopy._v) {}

Span::~Span() {}

// Overloaders

Span& Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->_v = rhs._v;
	}
	return *this;
}

// Functions

void	Span::addNumber(int nbr) {
	if (_v.size() < _N)
		_v.push_back(nbr);
	else
		throw Span::fullError();
}

int	Span::shortestSpan() const {
	if (_v.size() < 2 && _N < 2)
		throw Span::spanError();
	int	span = INT_MAX;
	for (std::vector<int>::const_iterator a = _v.begin(); a != _v.end(); ++a) {
		for (std::vector<int>::const_iterator b = a + 1; b != _v.end(); ++b) {
			int curr = abs(*a - *b);
			if (curr < span) {
				span = curr;
				if (!span)
					return span;
			}
		}
	}
	return span;
}

int	Span::longestSpan() const {
	if (_v.size() < 2 && _N < 2)
		throw Span::spanError();
	int	span = INT_MIN;
	for (std::vector<int>::const_iterator a = _v.begin(); a != _v.end(); ++a) {
		for (std::vector<int>::const_iterator b = a + 1; b != _v.end(); ++b) {
			int	curr = abs(*a - *b);
			if (curr > span) {
				span = curr;
				if (span == INT_MAX)
					return span;
			}
		}
	}
	return span;
}

void	Span::printVec() const {
	for (std::vector<int>::const_iterator it = _v.begin(); it < _v.end(); ++it)
		std::cout << *it << " | ";
	std::cout << std::endl;
}

