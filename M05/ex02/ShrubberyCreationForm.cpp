/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:17:48 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 12:40:17 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Builders / Unbuilders

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Default", 145, 137), _target("undefined") {
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target)
: AForm(name, 145, 137), _target(target) {
};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
: _target(copy._target + "_copy") {
};

ShrubberyCreationForm::~ShrubberyCreationForm(){
};

// Overloaders

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

// Functions

void	ShrubberyCreationForm::exe() const {
	std::string		fname = _target + "_shrubbery";
	std::ofstream	out(fname.c_str());

	if (out.is_open()) {
		out << "           \\/ |    |/\n"
		<< "        \\/ / \\||/  /_/___/_\n"
		<< "         \\/   |/ \\/\n"
		<< "    _\\__\\_\\   |  /_____/_\n"
		<< "           \\  | /          /\n"
		<< "  __ _-----`  |{,-----------~\n"
		<< "            \\ }{\n"
		<< "             }{{\n"
		<< "             }}{\n"
		<< "             {{}\n"
		<< "       , -=-~{ .-^- _\n"
		<< "             `}\n"
		<< "              {\n";
		out.close();
	}
	else
		std::cerr << "Error: unable to open file" << std::endl;
}
