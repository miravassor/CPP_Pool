/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:37:39 by avassor           #+#    #+#             */
/*   Updated: 2023/12/05 17:52:51 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: program needs one argument: filename.txt" << std::endl;
		return (1);
	}
	BitcoinExchange	data;
	std::ifstream	dbase("data.csv");
	std::ifstream	arg(argv[1]);
	if (dbase.is_open() && arg.is_open()) {
		data.loadData(dbase);
		dbase.close();
		data.parsePrint(arg);
		arg.close();
	}
	else {
		std::cerr << "Error: opening file(s)" << std::endl;
		return (1);
	}
	return (0);
}
