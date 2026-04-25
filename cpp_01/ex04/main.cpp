/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:39:22 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/25 14:23:32 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

static void	replace_all(std::string& line, const std::string& s1, const std::string& s2)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
}

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Error: provide ./sed_is_for_losers <filename> <s1> <s2>\n";
		return 1;
	}

	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (fileName.empty() || s1.empty() || s2.empty())
	{
		std::cerr << "Error: invalid input\n";
		return 1;
	}

	std::ifstream inFile(fileName.c_str());
	if (!inFile)
	{
		std::cerr << "Error: Unable to open input file\n";
		return 1;
	}

	std::string outName = fileName + ".replace";
	std::ofstream outFile(outName.c_str());
	if (!outFile)
	{
		std::cerr << "Error: Unable to open output file\n";
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		replace_all(line, s1, s2);
		outFile << line;
		if (!inFile.eof())
			outFile << "\n";
	}
	return 0;
}
