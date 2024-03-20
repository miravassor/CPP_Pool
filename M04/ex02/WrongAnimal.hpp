/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:10:29 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 15:00:48 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string dnu);
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(WrongAnimal const &copy);
		std::string	getType(void) const;
		void	makeSound(void) const;
};
