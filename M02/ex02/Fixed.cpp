/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:16:42 by avassor           #+#    #+#             */
/*   Updated: 2023/09/26 09:06:56 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CONSTRUCTORS*/

Fixed::Fixed(void) {
	// std::cout << "Default constructor called" << std::endl;
	this->_fixPointValue = 0;
}

Fixed::Fixed(const int i) : _fixPointValue(i << _fractionalBits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fixPointValue(Fixed::fRound(f * (1 << _fractionalBits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

/*DESTRUCTORS*/

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

/*COPY*/

Fixed& Fixed::operator=(const Fixed &copy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_fixPointValue = copy.getRawBits();
	return (*this);
}

/*OPERATORS*/

bool Fixed::operator>(const Fixed &rhs) const {
	return ((this->_fixPointValue > rhs.getRawBits()) ? true : false);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return ((this->_fixPointValue < rhs.getRawBits()) ? true : false);
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return ((this->_fixPointValue >= rhs.getRawBits()) ? true : false);
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return ((this->_fixPointValue <= rhs.getRawBits()) ? true : false);
}

bool Fixed::operator==(const Fixed &rhs) const {
	return ((this->_fixPointValue == rhs.getRawBits()) ? true : false);
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return ((this->_fixPointValue != rhs.getRawBits()) ? true : false);
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	if (!rhs._fixPointValue) {
		std::cout << "Error: division by 0" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void) {
	++_fixPointValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);
	++_fixPointValue;
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	--_fixPointValue;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	--_fixPointValue;
	return (tmp);
}

/*FUNCTIONS*/

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
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

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	return ((lhs <= rhs) ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	return ((lhs >= rhs) ? lhs : rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	return ((lhs <= rhs) ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	return ((lhs >= rhs) ? lhs : rhs);
}

int Fixed::fRound(const float f) {
	if (f >= 0.0f)
		return ((int)std::floor(f + 0.5f));
	return ((int)std::ceil(f - 0.5f));
}
