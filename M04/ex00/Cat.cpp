/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:31:43 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 14:51:36 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << _type << ": constructor called" << std::endl;
}

Cat::Cat(std::string dnu) : Animal(dnu) {
	(void)dnu;
	_type = "Cat";
	std::cout << _type << ": overload constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	if (this != &copy)
		*this = copy;
	std::cout << _type << ": copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

Cat::~Cat() {
	std::cout << _type << ": destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << _type << ": Moew" << std::endl;
}

std::string	Cat::getType(void) const {
	return (_type);
}
