/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:37:31 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:27:19 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <list>
#include <climits>

enum Id {
	ILLEGAL,
	OK
};

enum Tokens {
	NUMBER,
	OPERATOR,
	SPACE
};

enum Ope {
	PLUS,
	MINUS,
	MULT,
	DIV
};

struct Elem {
	Tokens	token;
	Ope		ope;
	char	c;
};

class RPN {
	private:
		std::list<Elem>		_list;
		Elem	parse(char c);
		Ope		findOp(char c);
		void	compute();
		void	rror(Id id);
		bool	isSign(char c);
		double	operate(int n1, int n2, Ope op);
	public:
		RPN() {};
		~RPN() {};
		RPN(RPN& tocopy);
		RPN& operator=(const RPN &rhs);
		void	run(std::string arg);
};
