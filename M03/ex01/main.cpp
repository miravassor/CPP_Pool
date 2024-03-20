/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:08:57 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 13:06:49 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	a("Leon");
	ScavTrap	b("Rosa");
	ScavTrap	c = b;
	b.attack("Mireille");
	b.guardGate();
	c.takeDamage(2);
	c.beRepaired(1);
	c.beRepaired(1);
	c.beRepaired(1);
}
