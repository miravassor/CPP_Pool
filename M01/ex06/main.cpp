/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:32:31 by avassor           #+#    #+#             */
/*   Updated: 2023/09/14 16:20:36 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2)
		std::cout << "Argument needed: DEBUG, INFO, WARNING or ERROR" << std::endl;
	else
		harl.complain(argv[1]);
	return (0);
}
