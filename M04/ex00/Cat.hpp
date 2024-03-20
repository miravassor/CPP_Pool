/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:27:26 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 15:04:06 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat(void);
		Cat(std::string dnu);
		Cat(Cat const &copy);
		~Cat(void);
		Cat &operator=(Cat const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
};
