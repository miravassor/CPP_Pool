/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:06:42 by avassor           #+#    #+#             */
/*   Updated: 2023/11/27 14:21:42 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void	easyfind(T x, int y) {
	try {
		if (std::find(x.begin(), x.end(), y) != x.end())
			std::cout << "Occurence found for: " << y << std::endl;
		else
			throw(std::exception());
	}
	catch (const std::exception &e) {
		std::cout << "No occurence of " << y << " found." << std::endl;
	}
}
