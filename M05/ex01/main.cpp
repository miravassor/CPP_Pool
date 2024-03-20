/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:31:01 by avassor           #+#    #+#             */
/*   Updated: 2023/11/07 15:02:49 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat r("Richard", 26);

	Form task("Task", 25, 25);
	std::cout << task << std::endl;
	task.beSigned(r);

	Bureaucrat d("Denise", 25);
	task.beSigned(d);
	std::cout << task << std::endl;

	Form task2("Task2", 10, 10);
	std::cout << task2 << std::endl;
	d.signForm(task2);
	Bureaucrat c("Celine", 1);
	task2.beSigned(c);
	c.signForm(task2);
	std::cout << task2 << std::endl;
	return (0);
}
