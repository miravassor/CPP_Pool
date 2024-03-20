/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:58:59 by avassor           #+#    #+#             */
/*   Updated: 2023/09/19 14:58:34 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

std::string	Contact::_getData(std::string str) const {
	std::string	in = "";
	while (1)
	{
		std::cout << str;
		std::getline(std::cin, in);
		if (std::cin.eof() || std::cin.fail())
			return "";
		else if (invalid_input(in)) {
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
		else if (std::cin.good() && !in.empty())
			break;
		else {
			std::cin.clear();
			std::cout << "Invalid input" << std::endl;
		}
	}
	return (in);
}

void	Contact::init(void) {
	this->_firstName = this->_getData("First name: ");
	if (this->_firstName == "")
		return;
	this->_lastName = this->_getData("Last name: ");
	if (this->_lastName == "")
		return;
	this->_nickname = this->_getData("Nickname: ");
	if (this->_nickname == "")
		return;
	this->_phNumber = this->_getData("Phone number: ");
	if (this->_phNumber == "")
		return;
	this->_secret = this->_getData("Darkest secret: ");
	if (this->_secret == "")
		return;
	std::cout << std::endl;
}

std::string Contact:: _printLen(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void   	Contact::setIndex(int i) {
	this->_i = i;
}


void	Contact::printTable(int i) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return;
	std::cout << "|" << std::setw(10) << i + 1;
	std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName);
	std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname);
	std::cout << "|" << std::endl;
}

void	Contact::printContact(void) const {
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
		return;
	std::cout << "First name\t| " << this->_firstName << std::endl;
	std::cout << "Last name\t| " << this->_lastName << std::endl;
	std::cout << "Nickname\t| " << this->_nickname << std::endl;
	std::cout << "Phone number\t| " << this->_phNumber << std::endl;
	std::cout << "Darkest secret\t| " << this->_secret << std::endl;
	std::cin.ignore();
}

bool	invalid_input(std::string str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == '\t' || str[i] == '\b' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r')
			return (1);
	}
	size_t	j = 0;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == ' ')
			j++;
	}
	if (str.size() == j)
		return (1);
	return (0);
}
