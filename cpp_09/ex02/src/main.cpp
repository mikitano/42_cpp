/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 22:44:12 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/02 01:57:39 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int	main(int ac, char** av) {
	PmergeMe test;

	try{
		test.parseInput(ac, av);
		test.printBefore();
		test.sortVector();
		test.printAfter();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}