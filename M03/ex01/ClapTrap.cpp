/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:09:50 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 13:05:40 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default") {
	_hitPoints = 10;
	_nrgPoints = 10;
	_attackDmg = 0;
	_hpMax = 10;
	std::cout << _name << ": default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	_hitPoints = 10;
	_nrgPoints = 10;
	_attackDmg = 0;
	_hpMax = 10;
	if (!_name.length())
		_name = "Default";
	std::cout << _name << ": ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& copy) {
	_hitPoints = copy._hitPoints;
	_nrgPoints = copy._nrgPoints;
	_attackDmg = copy._attackDmg;
	_hpMax = copy._hpMax;
	_name = copy._name + "_copy";
	std::cout << _name << ": ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const& copy) {
	if (this != &copy) {
		*this = copy;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << _name << ": ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->vAction()) {
		std::cout << "Could not attack" << std::endl;
		return;
	}
	--_nrgPoints;
	std::cout << _name << " attacks " << target << " and does " << _attackDmg << " damages" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->vAction()) {
		std::cout << "Could not repair himself" << std::endl;
		return;
	}
	if (_hitPoints == _hpMax) {
		std::cout << _name << " could not repair himself, life already at maximum: " << _hpMax << std::endl;
		return;
	}
	else {
		_hitPoints += amount;
		if (_hitPoints > _hpMax)
			_hitPoints = _hpMax;
	}
	--_nrgPoints;
	std::cout << _name << " repaired himself, life is now at " << _hitPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_hitPoints) {
		std::cout << _name << " is already dead, no damages taken" << std::endl;
		return;
	}
	if (minCross(_hitPoints, amount))
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << _name << " has taken " << amount << " damages, life is now at " << _hitPoints << std::endl;
}

bool	ClapTrap::vAction(void) {
	if (!_hitPoints && !_nrgPoints) {
		std::cout << _name << " got no life and energy left. ";
		return (1);
	}
	else if (!_hitPoints) {
		std::cout << _name << " got no life left. ";
		return (1);
	}
	else if (!_nrgPoints) {
		std::cout << _name << " got no energy left. ";
		return (1);
	}
	return (0);
}

bool	ClapTrap::minCross(unsigned int hitPoints, unsigned int amount) {
	return ((hitPoints < amount) ? true : false);
}
