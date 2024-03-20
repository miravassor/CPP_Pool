/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:44:14 by avassor           #+#    #+#             */
/*   Updated: 2023/11/22 17:22:48 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template<typename T>
class Array {
	private:
		T	*_array;
		int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &tocopy);
		~Array();

		Array<T>& operator=(const Array<T> &rhs);
		T& operator[](const int &index);

		int	size() const;

		class indexException : public std::exception {
			public:
			virtual const char * what() const throw() {
				return ("Out of range index.");
			}
		};
};


