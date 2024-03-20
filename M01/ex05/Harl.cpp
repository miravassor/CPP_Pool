/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:32:44 by avassor           #+#    #+#             */
/*   Updated: 2023/09/18 16:28:12 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void) {
	std::cout << "Debugging, be patient." << std::endl;
}

void	Harl::info(void) {
	std::cout << "RTFM." << std::endl;
}

void	Harl::warning(void) {
	std::cout << "You are being warned." << std::endl;
}

void	Harl::error(void) {
	std::cout << "Such human mistake." << std::endl;
}

void	Harl::complain(std::string level) {
	t_func	fptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
		(this->*fptr[i])();
}
