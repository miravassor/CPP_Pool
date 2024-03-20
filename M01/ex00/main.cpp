/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:13:12 by avassor           #+#    #+#             */
/*   Updated: 2023/09/11 14:47:21 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*z_A;

	randomChump("Ella");
	z_A = newZombie("Marc");
	z_A->announce();
	delete z_A;
	return (0);
}
