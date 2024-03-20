/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:16:35 by avassor           #+#    #+#             */
/*   Updated: 2023/09/20 15:33:51 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	private:
		int					_fixPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed(void);

		Fixed& operator=(const Fixed &rhs);
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs)const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		Fixed operator+(Fixed const &rhs) const;
		Fixed operator-(Fixed const &rhs) const;
		Fixed operator*(Fixed const &rhs) const;
		Fixed operator/(Fixed const &rhs) const;
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static int	fRound(const float f);
		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static Fixed &max(Fixed &lhs, Fixed &rhs);
		static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
		static Fixed const &max(Fixed const &lhs, Fixed const &rhs);
};
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif

