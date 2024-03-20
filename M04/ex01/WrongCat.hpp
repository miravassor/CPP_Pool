/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:21 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 15:05:55 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(std::string dnu);
		WrongCat(WrongCat const &copy);
		~WrongCat(void);
		WrongCat &operator=(WrongCat const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
};

