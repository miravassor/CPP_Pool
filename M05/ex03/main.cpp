/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:01 by avassor           #+#    #+#             */
/*   Updated: 2023/11/16 13:28:43 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	n("Noelle Grand Master", 1);
	Intern	npc;
	AForm*	a;

	a = npc.makeForm("shrubberry creation", "task1");
	a->beSigned(n);
	n.executeForm(*a);
	delete a;

	a = npc.makeForm("robotomy request", "task2");
	a->beSigned(n);
	n.executeForm(*a);
	delete a;

	a = npc.makeForm("presidential pardon", "task3");
	a->beSigned(n);
	n.executeForm(*a);
	delete a;

	a = npc.makeForm("excuse me sir i don't understand", "task4");
	return (0);
}
