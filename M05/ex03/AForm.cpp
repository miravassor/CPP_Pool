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

#include "AForm.hpp"

// Builders / Unbuilders

AForm::AForm() : _name("Default"), _signed(false), _gradeReq(1), _execReq(1) {
}

AForm::AForm(const std::string name, const unsigned int gradeReq, const unsigned int execReq)
: _name(name), _signed(false), _gradeReq(gradeReq), _execReq(execReq) {
}

AForm::AForm(AForm const &copy)
 : _name(copy._name + "_copy"), _signed(copy._signed), _gradeReq(copy._gradeReq), _execReq(copy._execReq) {
}

AForm::~AForm() {
}

// Overloaders

AForm&	AForm::operator=(const AForm &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
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

const std::string	AForm::getName(void) const {
	return (this->_name);
}

bool	AForm::getSigned(void) const {
	return (this->_signed);
}

unsigned int	AForm::getGradeReq(void) const {
	return (this->_gradeReq);
}

unsigned int	AForm::getExecReq(void) const {
	return (this->_execReq);
}

void	AForm::beSigned(const class Bureaucrat &rhs) {
	try {
		if (rhs.getGrade() <= getGradeReq())
			this->_signed = true;
		else if (rhs.getGrade() > getGradeReq())
			throw AForm::GradeTooLowException();
		else
			throw AForm::GradeTooHighException();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << getName() << ": " << rhs.getName() << " ";
		e.what();
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << getName() << ": " << rhs.getName() << " ";
		e.what();
	}
}

void	AForm::execute(Bureaucrat const &executor) const {
	try {
		if (executor.getGrade() <= this->getExecReq() && this->getSigned() == true)
			exe();
		else
			throw AForm::ExeErrorException();
	}
	catch (AForm::ExeErrorException &e) {
		std::cout << _name << ": " << executor.getName() << " ";
		e.what();
		try {
			if (this->getSigned() == false)
				std::cout << "Form not signed" << std::endl;
			else if (getExecReq() < executor.getGrade())
				throw Bureaucrat::GradeTooLowException();
			else
				throw Bureaucrat::GradeTooHighException();
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			e.what();
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			e.what();
		}
	}
}
