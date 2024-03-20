/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:46 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 12:01:08 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ClapTrap {
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_nrgPoints;
		unsigned int	_attackDmg;
		unsigned int	_hpMax;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);
		ClapTrap &operator=(ClapTrap const &copy);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	vAction(void);
		bool	minCross(unsigned int hitPoints,unsigned int amount);
};
