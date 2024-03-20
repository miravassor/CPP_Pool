/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:02 by avassor           #+#    #+#             */
/*   Updated: 2023/11/14 16:33:57 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Builders / Unbuilders

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Default", 25, 5), _target("undefined") {
};

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const std::string target)
: AForm(name, 25, 5), _target(target) {
};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
: _target(copy._target + "_copy") {
};

PresidentialPardonForm::~PresidentialPardonForm(){
};

// Overloaders

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

// Functions

void	PresidentialPardonForm::exe() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

