/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:32:08 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:14:24 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << _type << ": constructor called" << std::endl;
}

Dog::Dog(std::string dnu) : Animal(dnu) {
	(void)dnu;
	_type = "Dog";
	_brain = new Brain();
	std::cout << _type << ": overload constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	_type = copy._type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(copy._brain->getIdeas(i), i);
	std::cout << _type << ": copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy) {
	_type = copy._type;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(copy._brain->getIdeas(i), i);
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << _type << ": destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << _type << ": Woof" << std::endl;
}

std::string	Dog::getType(void) const {
	return (_type);
}

void	Dog::getIdeas(int i) const {
	std::string	tmp = "";

	tmp = _brain->getIdeas(i);
	if (tmp != "")
		std::cout << tmp << std::endl;
}

void	Dog::setIdeas(std::string str, int i) {
	_brain->setIdeas(str, i);
}
