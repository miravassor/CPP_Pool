/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:52:18 by avassor           #+#    #+#             */
/*   Updated: 2023/09/27 13:10:15 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	_hitPoints = 100;
	_nrgPoints = 100;
	_attackDmg = 30;
	_hpMax = 100;
	std::cout << _name << ": Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_nrgPoints = 100;
	_attackDmg = 30;
	_hpMax = 100;
	std::cout << _name << ": FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	_name = copy._name + "_copy";
	std::cout << _name << ": FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const& copy) {
	if (this != &copy) {
		*this = copy;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << _name << ": " << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->vAction()) {
		std::cout << "Could not attack" << std::endl;
		return;
	}
	--_nrgPoints;
	std::cout << _name << " attacks with Fragging " << target << " and does " << _attackDmg << " damages" << std::endl;
}

void	FragTrap::printFive(void) {
	std::cout << _name << ": Hey guys, give me five!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	printFive();
}
