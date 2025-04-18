/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:01:47 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/16 17:35:45 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
public:
	Harl();
	~Harl();
	int getFilter() const;
	void setFilter(std::string level);
	void complain(std::string level);
	
	static const int LEVELS = 4;

private:
	void debug();
	void info();
	void warning();
	void error();

	int _filterLevel;
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
