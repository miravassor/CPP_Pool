/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:31:43 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:14:13 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << _type << ": constructor called" << std::endl;
}

Cat::Cat(std::string dnu) : Animal(dnu) {
	(void)dnu;
	_type = "Cat";
	_brain = new Brain();
	std::cout << _type << ": overload constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	_type = copy._type;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(copy._brain->getIdeas(i), i);
	std::cout << _type << ": copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy) {
	_type = copy._type;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(copy._brain->getIdeas(i), i);
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << _type << ": destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << _type << ": Moew" << std::endl;
}

std::string	Cat::getType(void) const {
	return (_type);
}

void	Cat::getIdeas(int i) const {
	std::string	tmp = "";

	tmp = _brain->getIdeas(i);
	if (tmp != "")
		std::cout << tmp << std::endl;
}

void	Cat::setIdeas(std::string str, int i) {
		_brain->setIdeas(str, i);
}
