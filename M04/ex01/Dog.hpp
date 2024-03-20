/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:07 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 10:41:43 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(std::string dnu);
		Dog(Dog const &copy);
		~Dog(void);
		Dog &operator=(Dog const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
		void	getIdeas(int i) const;
		void	setIdeas(std::string str, int i);
};
