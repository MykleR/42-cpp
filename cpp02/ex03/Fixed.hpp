/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:08:12 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 17:33:54 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

typedef unsigned char u8;

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &new_value);
		Fixed(const int new_value);
		Fixed(const float new_value);
		~Fixed(void);

		int  getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int   toInt(void) const;

		Fixed &operator=(const Fixed &);
		bool operator>(const Fixed &value) const;
		bool operator<(const Fixed &value) const;
		bool operator>=(const Fixed &value) const;
		bool operator<=(const Fixed &value) const;
		bool operator==(const Fixed &value) const;
		bool operator!=(const Fixed &value) const;

		Fixed operator+(const Fixed &value) const;
		Fixed operator-(const Fixed &value) const;
		Fixed operator*(const Fixed &value) const;
		Fixed operator/(const Fixed &value) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		static const u8 _fractionalPart = 8;
		int _fixedNum;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
