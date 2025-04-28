/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:01:47 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/28 12:53:51 by mykle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		void complain(std::string level) const;
		static const int LEVELS = 4;

	private:
		void debug() const;
		void info() const;
		void warning() const;
		void error() const;

		typedef void (Harl::*Log)() const;
		const Harl::Log _funcs[LEVELS] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
		const std::string _levels[LEVELS] = {
			"DEBUG", "INFO", "WARNING", "ERROR"};
};

#endif
