/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:28:40 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 22:48:48 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(AMateria const & src);
		~Cure();

		Cure & operator=(AMateria const & rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
