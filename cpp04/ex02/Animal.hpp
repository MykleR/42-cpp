/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:07:30 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 21:40:56 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal(const Animal &src);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);

		virtual void makeSound() const = 0;
		std::string getType() const;

	protected:
		Animal();
		std::string type;
};

#endif
