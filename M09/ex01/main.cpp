/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:37:42 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 15:34:35 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Program needs one argument in RPN form" << std::endl;
		return (1);
	}
	RPN	rpn;
	rpn.run(argv[1]);
	return (0);
}
