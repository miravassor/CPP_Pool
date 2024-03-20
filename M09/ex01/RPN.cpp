/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:37:57 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:35:17 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Build

RPN::RPN(RPN& tocopy) {
	*this = tocopy;
}

RPN&	RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		_list = rhs._list;
	}
	return (*this);
}

// Main methods

void	RPN::run(std::string arg) {

	for (long unsigned int i = 0; i < arg.size(); ++i) {
		Id		id = OK;
		if (!isdigit(arg[i]) && !isSign(arg[i]) && arg[i] != ' ')
			id = ILLEGAL;
		if (i == 0 && isSign(arg[i]))
			id = ILLEGAL;
		if (id != OK)
			return rror(id);
		Elem	elem = parse(arg[i]);
		if (elem.token != SPACE)
			_list.push_back(elem);
	}
	compute();
}


// back ->  access the last element
// pop_back removes the last element
void	RPN::compute() {
	std::list<Elem>::iterator	currIt = _list.begin();
	std::list<int>	numbers;
	double	res = 0;

	for (; currIt != _list.end(); ++currIt) {
		if (currIt->token == NUMBER)
			numbers.push_back(currIt->c - '0');
		else {
			Ope		op = findOp(currIt->c);
			if (numbers.empty()) {
				std::cout << "Error: operation on empty stack" << std::endl;
				return;
			}
			int		n2 = numbers.back(); numbers.pop_back();
			if (numbers.empty()) {
				std::cout << "Error: operation on empty stack" << std::endl;
				return;
			}
			int		n1 = numbers.back(); numbers.pop_back();
			res = operate(n1, n2, op);
			if (res < INT_MIN || res > INT_MAX) {
				std::cout << "Error: overflow" << std::endl;
				return;
			}
			numbers.push_back(static_cast<int>(res));
		}
	}
	std::cout << numbers.back() << std::endl;
}

double	RPN::operate(int n1, int n2, Ope op) {
	double	res = 0;

	switch (op) {
		case PLUS:
			res = n1 + n2;
			break;
		case MINUS:
			res = n1 - n2;
			break;
		case DIV:
			if (n2 == 0)
				res = 0;
			else
				res = n1 / n2;
			break;
		case MULT:
			res = n1 * n2;
			break;
	}
	return res;
}

// Parsing

Elem	RPN::parse(char c) {
	Elem	elem;
	if (isdigit(c))
		elem.token = NUMBER;
	else if (isSign(c))
		elem.token = OPERATOR;
	else
		elem.token = SPACE;
	elem.c = c;
	return elem;
}

// Utilities

void	RPN::rror(Id id) {
	switch (id) {
		case ILLEGAL:
			std::cout << "Error: illegal character in argument" << std::endl;
			break;
		default:
			break;
	}
}

bool	RPN::isSign(char c) {
	return c == '*' || c == '/' || c == '-' || c == '+' ? true : false;
}

Ope	RPN::findOp(char c) {
	if (c == '+')
		return PLUS;
	if (c == '-')
		return MINUS;
	if (c == '/')
		return DIV;
	else
		return MULT;
}
