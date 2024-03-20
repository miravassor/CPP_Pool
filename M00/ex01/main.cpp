/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:45:11 by avassor           #+#    #+#             */
/*   Updated: 2023/09/19 15:01:21 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	in = "";
	std::cout << "PhoneBook | Commands: ADD, SEARCH, EXIT" << std::endl;
	while (in.compare("EXIT")) {
		if (!in.compare("ADD"))
			book.addContact();
		else if (!in.compare("SEARCH")) {
			book.printContact();
			book.findContact();
		}
		if (std::cin.eof())
			break;
		std::cout.flush();
		std::cout << "> ";
		std::getline(std::cin, in);
		if (std::cin.eof() || std::cin.fail())
			break ;
	}
	return (0);
}
