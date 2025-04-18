/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:01:47 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/16 17:08:29 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		static const int LEVELS = 4;
		
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void debug();
		void info();
		void warning();
		void error();

		typedef void (Harl::*Log)();
		const Harl::Log _funcs[LEVELS] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
		const std::string _levels[LEVELS] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};
};

#endif
