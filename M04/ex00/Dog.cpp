/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:32:08 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 14:53:11 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << _type << ": constructor called" << std::endl;
}

Dog::Dog(std::string dnu) : Animal(dnu) {
	(void)dnu;
	_type = "Dog";
	std::cout << _type << ": overload constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	if (this != &copy)
		*this = copy;
	std::cout << _type << ": copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

Dog::~Dog() {
	std::cout << _type << ": destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << _type << ": Woof" << std::endl;
}

std::string	Dog::getType(void) const {
	return (_type);
}
