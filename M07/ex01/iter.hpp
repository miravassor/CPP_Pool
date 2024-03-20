/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:06:09 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 11:26:53 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename U, typename V>
void	iter(T *add, U size, V fp) {
	for (int i = 0; i < size; i++)
		fp(add[i]);
}
