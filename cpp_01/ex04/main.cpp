/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:39:22 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/24 22:39:22 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		//msg de erro;
		return 1;
	}

	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (fileName.empty() || s1.empty() || s3.empty)
	{
		//msg de erro;
		return 1;
	}
}