/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:11:36 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 13:05:14 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	_name = "Default";
	_hitPoints = 100;
	_nrgPoints = 50;
	_attackDmg = 20;
	_hpMax = 100;
	std::cout << _name << ": default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_nrgPoints = 50;
	_attackDmg = 20;
	_hpMax = 100;
	if (!_name.length())
		_name = "Default";
	std::cout << _name << ": ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	_name = copy._name + "_copy";
	std::cout << _name << ": ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const& copy) {
	if (this != &copy) {
		*this = copy;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << _name << ": ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (this->vAction()) {
		std::cout << "Could not attack" << std::endl;
		return;
	}
	--_nrgPoints;
	std::cout << _name << " attacks " << target << " with Trapping" << " and does " << _attackDmg << " damages" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::printGate(void) {
	guardGate();
}
