/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:14 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 12:22:52 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat&			operator=(Bureaucrat const &rhs);
		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				upGrade(void);
		void				downGrade(void);
		void				signForm(const class AForm &form) const;
		void				executeForm(AForm const &form) const;

		class GradeTooHighException {
			public:
				virtual void what() const throw() {
					std::cout << "Grade too high" << std::endl;
				}
		};

		class GradeTooLowException {
			public:
				virtual void what() const throw() {
					std::cout << "Grade too low" << std::endl;
				}
		};

		class ExeErrorException {
			public:
				virtual void what() const throw() {
					std::cout << "can't execute ";
				}
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
