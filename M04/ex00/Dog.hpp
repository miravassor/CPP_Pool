/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:07 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 15:05:50 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog(void);
		Dog(std::string dnu);
		Dog(Dog const &copy);
		~Dog(void);
		Dog &operator=(Dog const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
};
