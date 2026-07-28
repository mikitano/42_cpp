/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:06:42 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/28 00:38:33 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cctype>
#include <fstream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _data(copy._data) {}

BitcoinExchange::BitcoinExchange& operator=(const BitcoinExchange& rhs) {
	if (this != &rhs)
		_data = rhs._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::validateValue(const std::string& value) const {
	if (value.empty())
		throw runtime_error("Error: Bad input => empty");
	
	bool hasDot = false;
	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] == '.') {
			if (hasDot)
				throw runtime_error("Error: Bad input =>" + value);
			hasDot = true;
		}
		else if (!std::isdigit(value[i]))
			throw runtime_error("Error: Bad input =>" + value);
	}
	return true;
}

void BitcoinExchange::loadDataBase(const std::string& filename) {
	std::ifstream file (filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty data base file");

	while (std::getline(file, line)) {
		try {
			size_t pos = line.find(',');
			if (pos == std::string::npos)
				throw runtime_error("Error: Bad input => " + line);
			
			std::string date = line.substr(0, pos);
			validateDate(date);
			
			std::string v_data = line.substr(pos + 1);
			validateValue(v_data)

			char* end;
			double value = std::strtod(v_data.c_str(), &end);
			_data[date] = value;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}