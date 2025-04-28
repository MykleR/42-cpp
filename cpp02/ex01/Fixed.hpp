/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:08:12 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 17:21:11 by mykle            ###   ########.fr       */
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

	private:
		static const u8 _fractionalPart = 8;
		int _fixedNum;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
