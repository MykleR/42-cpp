/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:54:36 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/29 21:55:38 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain &src);
	~Brain();
	Brain &operator=(const Brain &rhs);

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string &idea);
private:
	std::string _ideas[100];
};

#endif
