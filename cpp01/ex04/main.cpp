/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrouves <mrouves@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:12:50 by mrouves           #+#    #+#             */
/*   Updated: 2025/04/11 18:33:42 by mrouves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#define ERROR_OPEN 2
#define ERROR_CREATE 3
#define ERROR_ARG 1

int error(int error_code)
{
	switch (error_code)
	{
		case ERROR_OPEN:
			std::cerr << "Error: could not open file" << std::endl; break;
		case ERROR_ARG:
			std::cerr << "Error: invalid arguments" << std::endl; break;
		case ERROR_CREATE:
			std::cerr << "Error: could not create file" << std::endl; break;
	}
	return error_code;
}

void replace(std::string &line, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4 || !argv[2][0])
		return error(ERROR_ARG);
	std::ifstream ifs(argv[1]);
	if (!ifs.good())
		return error(ERROR_OPEN);
	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ofstream ofs(std::string(argv[1]) + ".replace");
	if (!ofs.good())
	{
		ifs.close();
		return error(ERROR_CREATE);
	}
	while (std::getline(ifs, line))
	{
		replace(line, s1, s2);
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
