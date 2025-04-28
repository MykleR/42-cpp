/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykle <mykle@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:08:12 by mykle             #+#    #+#             */
/*   Updated: 2025/04/28 17:20:31 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

typedef unsigned char u8;

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &new_value);
		~Fixed(void);

		int  getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed &operator=(const Fixed &);

	private:
		static const u8 _fractionalPart = 8;
		int _fixedNum;
};

#endif
