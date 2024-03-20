/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:04 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 17:34:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base*	generate(void) {
	Base*	base;
	std::srand(time(NULL));
	int	key = rand() % 3;

	switch (key) {
		case 0:
			base = new A;
			std::cout << "Class A created." << std::endl;
			break;
		case 1:
			base = new B;
			std::cout << "Class B created." << std::endl;
			break;
		case 2:
			base = new C;
			std::cout << "Class C created." << std::endl;
			break;
	}
	return (base);
}

// cast p to different object, if non-null: p point to this object

void	identify(Base* p) {
	Base*	base;

	base = dynamic_cast<A*>(p);
	if (base) {
		std::cout << "A object" << std::endl;
		return ;
	}
	base = dynamic_cast<B*>(p);
	if (base) {
		std::cout << "B object" << std::endl;
		return ;
	}
	base = dynamic_cast<C*>(p);
	if (base)
		std::cout << "C object" << std::endl;
}

// dynamic_cast with references throws a std::bad_cast exception
// if it cannot successfully cast the reference
// (void)object -> suppress compiler warnings

void	identify(Base& p) {

	try {
		Base& Abase = dynamic_cast<A&>(p);
		(void)Abase;
		std::cout << "A object" << std::endl;
	}
	catch (const std::exception &e) {
		;
	}
	try {
		Base& Bbase = dynamic_cast<B&>(p);
		(void)Bbase;
		std::cout << "B object" << std::endl;
	}
	catch (const std::exception &e) {
		;
	}
	try {
		Base& Cbase = dynamic_cast<C&>(p);
		(void)Cbase;
		std::cout << "C object" << std::endl;
	}
	catch (const std::exception &e) {
		;
	}
}
