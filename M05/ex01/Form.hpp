/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:47:07 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 12:54:20 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeReq;
		const unsigned int	_execReq;
	public:
		Form(void);
		Form(const std::string name, const unsigned int gradeReq, const unsigned int execReq);
		Form(Form const &copy);
		~Form(void);
		Form				&operator=(Form const &rhs);
		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int		getGradeReq() const;
		unsigned int		getExecReq() const;
		void				beSigned(const class Bureaucrat &rhs);

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
};

std::ostream&	operator<<(std::ostream& out, const Form& form);
