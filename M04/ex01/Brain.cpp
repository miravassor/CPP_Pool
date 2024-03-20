/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:17 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:05:50 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "";
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	*this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdeas(int i) const {
	if (i < 0 || i > 99) {
		std::cout << "Out of range request: [0-99]" << std::endl;
		return ("");
	}
	return (_ideas[i]);
}

void	Brain::setIdeas(std::string str, int i) {
	if (i < 0 || i > 99) {
		std::cout << "Out of range request: [0-99]" << std::endl;
		return;
	}
	_ideas[i] = str;
}
