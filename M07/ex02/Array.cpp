/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:44:06 by avassor           #+#    #+#             */
/*   Updated: 2023/11/24 11:59:00 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Builders / Unbuilder

template<typename T>
Array<T>::Array()
: _array(new T[0]), _size(0) {
}

template<typename T>
Array<T>::Array(unsigned int n)
: _array(new T[n]), _size(n) {
}

template<typename T>
Array<T>::Array(const Array<T> &tocopy) {
	_array = new T[tocopy._size];
	_size = tocopy._size;
	for (int i = 0; i < _size; i++)
		_array[i] = tocopy._array[i];
}

template<typename T>
Array<T>::~Array() {
	delete [] _array;
}

// Overloaders

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &rhs) {
	if (this != &rhs) {
	delete [] _array;
	_array = new T[rhs._size];
	_size = rhs._size;
	for (int i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](const int &index) {
	if (index < 0 || index >= _size || _size <= 0)
		throw (Array<T>::indexException());
	return (_array[index]);
}

// Functions

template<typename T>
int Array<T>::size() const {
	return (_size);
}

