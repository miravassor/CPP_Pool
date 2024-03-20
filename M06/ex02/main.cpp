/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:54 by avassor           #+#    #+#             */
/*   Updated: 2023/11/21 17:34:34 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int	main() {

	Base *pbase = generate();
	Base &rbase = *pbase;

	identify(pbase);
	identify(rbase);
	delete pbase;
	return (0);
}
