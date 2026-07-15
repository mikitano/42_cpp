/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:11:22 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/15 02:58:39 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();

		static void printChar(const double n);
		static void printInt(const double n);
		static void printFloat(const double n);
		static void printDouble(const double n);

	public:
		static void convert(const std::string& str);
};