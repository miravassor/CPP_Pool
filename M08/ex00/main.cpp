/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:05:45 by avassor           #+#    #+#             */
/*   Updated: 2023/11/23 12:26:34 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main() {
	std::vector<int>	v;
	int					key = 9;

	v.push_back(5);
	v.push_back(8);
	v.push_back(9);
	v.push_back(12);
	easyfind(v, key);
	return (0);
}
