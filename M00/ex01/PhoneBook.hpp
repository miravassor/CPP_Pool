/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:42:54 by avassor           #+#    #+#             */
/*   Updated: 2023/09/19 14:42:41 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

class PhoneBook
{
	private:
		int		_readIn(void) const;
		Contact	_contacts[8];
		int		_i;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	printContact(void) const;
		void	findContact(void);
};

#endif
