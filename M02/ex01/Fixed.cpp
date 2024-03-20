/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:16:42 by avassor           #+#    #+#             */
/*   Updated: 2023/09/26 08:57:49 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixPointValue = 0;
}

Fixed::Fixed(const int i) : _fixPointValue(i << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixPointValue(fRound(f * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixPointValue = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	/*std::cout << "getRawBits member function called" << std::endl;*/
	return (this->_fixPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixPointValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixPointValue / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const {
	return ((this->_fixPointValue >> _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}

int	fRound(const float f) {
	return (std::floor(f + 0.5));
}

