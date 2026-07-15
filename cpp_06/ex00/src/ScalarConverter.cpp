/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:11:50 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/15 03:02:21 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& str) {
	double	n;
	char*	end;

	if (str.empty()) {
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	if (str.length() == 1 && !std::isdigit(str[0])) {
		n = static_cast<double>(str[0]);
	}
	else {
		n = std::strtod(str.c_str(), &end);
		if ( ( *end != '\0' && *end != 'f' ) || ( *end == 'f' && *( end + 1 ) != '\0' ) ) {
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}
	printChar(n);
	printInt(n);
	printFloat(n);
	printDouble(n);
}

void ScalarConverter::printChar(const double n) {
	if (std::isnan(n) || std::isinf(n) || n < 0 || n >127)
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) <<std::endl;
}

void ScalarConverter::printInt(const double n) {
	if (std::isnan(n) || std::isinf(n) || n > std::numeric_limits<int>::max()|| n < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

void ScalarConverter::printFloat(const double n) {
	if (std::isnan(n) || std::isinf(n))
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	else
		std::cout << "float: " << std::fixed
				  << std::setprecision(1)
				  << static_cast<float>(n)
				  << "f" << std::endl;
}

void ScalarConverter::printDouble(const double n) {
	if (std::isnan(n) || std::isinf(n))
		std::cout << "double: " << n << std::endl;
	else
		std::cout << "double: " << std::fixed
				  << std::setprecision(1)
				  << n << std::endl;
}