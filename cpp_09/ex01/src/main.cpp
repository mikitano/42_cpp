/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:17:07 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/01 01:04:46 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int	main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << "Usage: ./RPN '<inverted Polish mathematical expression>'" << std::endl;
		return 1;
	}
	try {
		RPN rpn;
		rpn.calculate(av[1]);
		rpn.printResult();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}