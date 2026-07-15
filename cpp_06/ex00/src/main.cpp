/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:49:41 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/14 23:54:04 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Correct usage: ./convert <scalar_literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}