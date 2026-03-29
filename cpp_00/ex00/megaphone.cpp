/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:01:27 by mkitano           #+#    #+#             */
/*   Updated: 2026/03/28 15:03:57 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < ac; i++)
	{
		std::string	str(av[i]);
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str[j]);
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}