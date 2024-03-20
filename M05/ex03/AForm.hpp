/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:47:07 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 13:26:20 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeReq;
		const unsigned int	_execReq;
	public:
		AForm(void);
		AForm(const std::string name, const unsigned int gradeReq, const unsigned int execReq);
		AForm(AForm const &copy);
		virtual ~AForm(void);
		AForm						&operator=(AForm const &rhs);
		virtual const std::string	getName() const;
		virtual bool				getSigned() const;
		virtual unsigned int		getGradeReq() const;
		virtual unsigned int		getExecReq() const;
		virtual void				beSigned(const class Bureaucrat &rhs);
		virtual void				execute(Bureaucrat const &executor) const;
		virtual void				exe() const = 0;

		class	GradeTooHighException {
			public:
				virtual void what() const throw() {
					std::cout << "can't sign: grade to high" << std::endl;
				}
		};

		class GradeTooLowException {
			public:
				virtual void what() const throw() {
					std::cout << "can't sign: grade too low" << std::endl;
				}
		};

		class ExeErrorException {
			public:
				virtual void what() const throw() {
					std::cout << "can't execute: ";
				}
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);
