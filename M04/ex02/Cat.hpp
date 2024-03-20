/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:26 by avassor           #+#    #+#             */
/*   Updated: 2023/09/28 11:01:57 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(std::string dnu);
		Cat(Cat const &copy);
		~Cat(void);
		Cat &operator=(Cat const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
		void	getIdeas(int i) const;
		void	setIdeas(std::string str, int i);
};
