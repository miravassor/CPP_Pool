/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:49:12 by avassor           #+#    #+#             */
/*   Updated: 2023/09/18 16:15:13 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void	HumanA::attack(void) {
	if (this->_weapon.getType() != "")
		std::cout << _name << " attack with " << this->_weapon.getType() << std::endl;
	else
		std::cout << _name << "got no weapons" << std::endl;
}
