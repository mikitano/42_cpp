/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 03:07:38 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/17 03:29:24 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int	main(void) {

	std::cout << "\n===== ARRAY INT =====" << std::endl;
	int numbers1[] = {10, 20, 30};
	iter(numbers1, 3, print<int>);

	std::cout << "\n===== CONST ARRAY INT =====" << std::endl;
	const int numbers2[] = {10, 20, 30};
	iter(numbers2, 3, print<int>);

	std::cout << "\n===== ARRAY FLOAT =====" << std::endl;
	float f1[] = {10.01, 20.22, 30.42};
	iter(f1, 3, print<float>);

	std::cout << "\n===== CONST ARRAY FLOAT =====" << std::endl;
	const float f2[] = {10.01, 20.22, 30.42};
	iter(f2, 3, print<float>);

	std::cout << "\n===== ARRAY DOUBLE =====" << std::endl;
	double d1[] = {101.01, 240.2, 42.42};
	iter(d1, 3, print<double>);

	std::cout << "\n===== CONST ARRAY DOUBLE =====" << std::endl;
	const double d2[] = {101.01, 240.2, 42.42};
	iter(d2, 3, print<double>);

	std::cout << "\n===== ARRAY STRING =====" << std::endl;
	std::string circus1[] = {"Pomni", "Jax", "Caine"};
	iter(circus1, 3, print<std::string>);

	std::cout << "\n===== CONST ARRAY STRING =====" << std::endl;
	const std::string circus2[] = {"Pomni", "Jax", "Caine"};
	iter(circus2, 3, print<std::string>);

	return 0;
}