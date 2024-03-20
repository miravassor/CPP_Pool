/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:59:58 by avassor           #+#    #+#             */
/*   Updated: 2023/09/19 13:03:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phNumber;
		std::string	_secret;
		int			_i;
		std::string	_printLen(std::string str) const;
		std::string	_getData(std::string str) const;
	public:
		Contact(void);
		~Contact(void);
		void	init(void);
		void	setIndex(int i);
		void	printTable(int i) const;
		void	printContact(void) const;
};

bool	invalid_input(std::string str);

#endif
