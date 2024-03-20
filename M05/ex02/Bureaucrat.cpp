/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:23 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 12:49:12 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Builders / Unbuilders

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1) {
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade)
: _name(name), _grade(grade) {
	try {
		if (getGrade() < 1)
			throw GradeTooHighException();
		else if (getGrade() > 150)
			throw GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		e.what();
		_grade = 150;
		std::cout << "Bureaucrat " << getName() << " set to default grade: 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		e.what();
		_grade = 150;
		std::cout << "Bureaucrat " << getName() << " set to default grade: 150" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
: _name(copy._name + "_copy"), _grade(copy._grade) {
}

Bureaucrat::~Bureaucrat(void) {
}

// Overloaders

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << "'s grade: " << bureaucrat.getGrade() << std::endl;
	return (out);
}

// Functions

const std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::upGrade(void) {
	try {
		if (getGrade() <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		e.what();
	}
}

void	Bureaucrat::downGrade(void) {
	try {
		if (getGrade() >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		e.what();
	}
}

void	Bureaucrat::signForm(const class AForm &form) const {
	try {
		if (form.getSigned() == true && this->getGrade() <= form.getGradeReq())
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else if (form.getSigned() == false)
			std::cout << this->getName() << ": " << form.getName() << " has not been signed" << std::endl;
		else if (this->getGrade() < 1)
			throw AForm::GradeTooHighException();
		else
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << form.getName() << ": " << this->getName() << " ";
		e.what();
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << form.getName() << ": " << this->getName() << " ";
		e.what();
	}
}

void	Bureaucrat::executeForm(AForm const &form) const {
	std::cout << _name << ": ";
	try {
		if (this->getGrade() <= form.getExecReq() && form.getSigned() == true) {
			std::cout << "executed " << form.getName() << std::endl;
			form.execute(*this);
		}
		else
			throw ExeErrorException();
	}
	catch (ExeErrorException &e) {
		e.what();
		std::cout << form.getName() << " because: ";
		try {
			if (form.getSigned() == false)
				std::cout << "not signed" << std::endl;
			else if (this->getGrade() > form.getExecReq())
				throw GradeTooLowException();
			else
				throw GradeTooHighException();
		}
		catch (GradeTooLowException &e) {
			e.what();
		}
		catch (GradeTooHighException &e) {
			e.what();
		}
	}
}
