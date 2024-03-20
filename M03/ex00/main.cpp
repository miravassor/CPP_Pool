/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:08:57 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 12:22:00 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("Leon");
	ClapTrap	b;
	ClapTrap	c = a;

	a.attack("Ella");
	b.attack("Marcus");
	c.attack("John");
	a.takeDamage(5);
	b.takeDamage(8);
	c.takeDamage(3);
	a.beRepaired(1);
	b.beRepaired(12);
	c.beRepaired(2);
	b.beRepaired(12);
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.attack("Ella");
	a.takeDamage(10);
	a.takeDamage(2);
	a.beRepaired(1);
}
