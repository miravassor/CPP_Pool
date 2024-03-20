/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:47:12 by avassor           #+#    #+#             */
/*   Updated: 2023/11/06 13:33:41 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Builders / Unbuilders

Form::Form() : _name("Default"), _signed(false), _gradeReq(1), _execReq(1) {
}

Form::Form(const std::string name, const unsigned int gradeReq, const unsigned int execReq)
: _name(name), _signed(false), _gradeReq(gradeReq), _execReq(execReq) {
}

Form::Form(Form const &copy)
 : _name(copy._name + "_copy"), _signed(copy._signed), _gradeReq(copy._gradeReq), _execReq(copy._execReq) {
}

Form::~Form() {
}

// Overloaders

Form&	Form::operator=(const Form &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& form) {
	out << form.getName() << " form:" << std::endl;
	if (form.getSigned() == true)
		out << "\tSigned:\t\t\t   yes" << std::endl;
	else
		out << "\tSigned:\t\t\t   no" << std::endl;
	out << "\tGrade required to sign:\t   " << form.getGradeReq() << std::endl;
	out << "\tGrade required to execute: " << form.getExecReq() << std::endl;
	return (out);
}

// Functions

const std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getSigned(void) const {
	return (this->_signed);
}

unsigned int	Form::getGradeReq(void) const {
	return (this->_gradeReq);
}

unsigned int	Form::getExecReq(void) const {
	return (this->_execReq);
}

void	Form::beSigned(const class Bureaucrat &rhs) {
	try {
		if (rhs.getGrade() <= getGradeReq())
			this->_signed = true;
		else if (rhs.getGrade() > getGradeReq())
			throw Form::GradeTooLowException();
		else
			throw Form::GradeTooHighException();
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << getName() << ": " << rhs.getName() << " ";
		e.what();
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << getName() << ": " << rhs.getName() << " ";
		e.what();
	}
}
