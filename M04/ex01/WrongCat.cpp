/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:11 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 15:03:27 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	_type = "WrongCat";
	std::cout << _type << ": constructor called" << std::endl;
}

WrongCat::WrongCat(std::string dnu) : WrongAnimal(dnu) {
	(void)dnu;
	_type = "WrongCat";
	std::cout << _type << ": overload constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy) {
	if (this != &copy)
		*this = copy;
	std::cout << _type << ": copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << _type << ": destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << _type << ": WrongMoew" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return (_type);
}

