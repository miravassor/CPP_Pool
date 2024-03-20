/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:11:00 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 14:41:41 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string dnu);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal &operator=(Animal const &copy);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
};

