/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:00:15 by avassor           #+#    #+#             */
/*   Updated: 2023/12/12 14:58:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.cpp"
#include "dequeMergeMe.hpp"
#include "dequeMergeMe.cpp"
#include "vectorMergeMe.hpp"
#include "vectorMergeMe.cpp"

int	main(int argc, char **argv) {
	if (argc < 3) {
		std::cout << "Error: program needs at least two values to sort them" << std::endl;
		return (1);
	}
	dequeMergeMe<std::deque<int> >		deq;
	deq.run(argc, argv);
	return 0;
}
