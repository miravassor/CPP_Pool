/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:18:23 by avassor           #+#    #+#             */
/*   Updated: 2023/11/14 16:33:14 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Builders / Unbuilders

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Default", 72, 45), _target("undefined") {
};

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const std::string target)
: AForm(name, 72, 45), _target(target) {
};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
: _target(copy._target + "_copy") {
};

RobotomyRequestForm::~RobotomyRequestForm(){
};

// Overloaders

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

// Functions

void	RobotomyRequestForm::exe() const {
	std::srand(std::time(NULL));

	std::cout << "BrrRrRRRRrrrrr [...] VrrrrRRRRRRRRRRrrr [...] Bip." << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " could not be robotomized" << std::endl;
}
