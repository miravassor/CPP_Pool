/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:32:31 by avassor           #+#    #+#             */
/*   Updated: 2023/09/18 16:28:15 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	std::cout << "DEBUG :" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO :" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING :" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR :" << std::endl;
	harl.complain("ERROR");
	return (0);
}
