/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:01 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 13:41:24 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	r("Richard Moneybags", 1);
	Bureaucrat	d("Denis Nomoney", 150);

	ShrubberyCreationForm task("Task", "target1");

	task.beSigned(d);

	task.beSigned(r);
	r.executeForm(task);

	RobotomyRequestForm task2("Task2", "target2");
	task2.beSigned(r);
	r.executeForm(task2);

	PresidentialPardonForm task3("Task3", "target3");
	task3.beSigned(r);
	r.executeForm(task3);
	return (0);
}
