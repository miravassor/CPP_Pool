/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:55:47 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 13:28:28 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Builders / Unbuilders

Intern::Intern(){
};

Intern::Intern(Intern const &copy) {
	*this = copy;
};

Intern::~Intern(){
};

// Overloaders

Intern&	Intern::operator=(Intern const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

// Functions

AForm*	Intern::makeForm(std::string name, std::string target) {
	int	i;
	const char *array_ptr[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3 && name.compare(array_ptr[i]) != 0 ; i++);
	switch (i)
	{
		case (0):
			return (new RobotomyRequestForm(name, target));
		case (1):
			return (new PresidentialPardonForm(name, target));
		case (2):
			return (new ShrubberyCreationForm(name, target));
		default:
			std::cout << "Unknown form, bad intern!" << std::endl;
			return (NULL);
	}
}
