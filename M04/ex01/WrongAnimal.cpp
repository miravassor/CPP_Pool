/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:09:42 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 14:57:11 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << _type << ": constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string dnu) : _type("WrongAnimal") {
	(void)dnu;
	std::cout << _type << ": constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	_type = copy._type;
	std::cout << _type << ": copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << _type << ": destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << _type << ": *random WrongAnimal sound*" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}
