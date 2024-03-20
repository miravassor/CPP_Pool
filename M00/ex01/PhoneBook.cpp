/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:39:23 by avassor           #+#    #+#             */
/*   Updated: 2023/09/19 14:59:16 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_i = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::addContact(void) {
	this->_contacts[this->_i % 8].init();
	this->_contacts[this->_i % 8].setIndex(this->_i % 8);
	if (this->_i < 8)
		this->_i++;
}

void	PhoneBook::printContact(void) const {
	if (!this->_i) {
		std::cout << "No contact in database" << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].printTable(i);
	std::cout << std::endl;
}

int	PhoneBook::_readIn() const {
	int	in = -1;

	while (1)
	{
		std::cout << "Enter contact index: ";
		std::cin >> in;
		in -= 1;
		if (std::cin.eof() || std::cin.fail() || (std::cin.good() && (in >= 0 && in < this->_i)))
			break;
		else {
			std::cout << "Invalid index" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return (in);
}

void	PhoneBook::findContact(void) {
	if (!this->_i)
		return;
	int i = this->_readIn();
	if (i == -2)
		return;
	this->_contacts[i].printContact();
}
