/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:54 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 17:35:09 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	Data	data;
	data.value = 42;

	// uintptr_t : store the value of a pointer in an integer variable
	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;

	Data		*dataPtr = Serializer::deserialize(raw);
	std::cout << dataPtr->value << std::endl;

	return (0);
}
