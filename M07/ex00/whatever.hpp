/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:04:53 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 12:08:48 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
	if (a == b)
		return (a);
	return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b) {
	if (a == b)
		return (a);
	return (a > b ? a : b);
}
