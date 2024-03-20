/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:10:53 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 10:56:30 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal: constructor called" << std::endl;
}

Animal::Animal(std::string dnu) : _type("Animal") {
	(void)dnu;
	std::cout << _type << ": constructor called" << std::endl;
}

Animal::Animal(Animal const &copy) {
	_type = copy._type;
	std::cout << _type << ": copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal: destructor called" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << _type << ": *random animal sound*" << std::endl;
}

std::string	Animal::getType(void) const {
	return (_type);
}
