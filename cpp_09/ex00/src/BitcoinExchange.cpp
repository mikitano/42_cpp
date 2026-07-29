/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:06:42 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/29 00:29:56 by mkitano          ###   ########.fr       */
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

void BitcoinExchange::validateDate(const std::string& date) const {
	if (date.empty())
		throw runtime_error("Error: Bad input => empty");
	if (date.size() != 10)
		throw runtime_error("Error: Bad input => " + date);	
	if (date[4] != '-' || date[7] != '-')
		throw runtime_error("Error: Bad input => " + date);

	//separate year, month and day 
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	//check for only digits
	for (size_t i = 0, i < yearStr.size(), i++) {
		if (!std::isdigit(yearStr[i]))
			throw runtime_error ("Error: Bad input => " + yearStr);
	}
	for (size_t i = 0, i < monthStr.size(), i++) {
		if (!std::isdigit(monthStr[i]))
			throw runtime_error ("Error: Bad input => " + monthStr);
	}
	for (size_t i = 0, i < dayStr.size(), i++) {
		if (!std::isdigit(dayStr[i]))
			throw runtime_error ("Error: Bad input => " + dayStr);
	}

	//transform str -> int
	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	//basic limits check
	if (year < 2009)
		throw runtime_error("Error: Bad input => year bellow 2009");
	if (month < 1 || month > 12)
		throw runtime_error("Error: Bad input => invalid month");
	if (day < 1 || day > 31)
		throw runtime_error("Error: Bad input => invalid day");
	
	//array of max days in months
	int daysInMonth[12] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	}
	//check for FEB leap year
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			daysInMonth[1] = 29;
	}
	//check limits
	if (day > daysInMonth[month - 1])
		throw runtime_error("Error: Bad input => invalid day");
}

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
}

double BitcoinExchange::getExchange(const std::string& date) const {
	if (date.empty())
		throw runtime_error("Error: Bad input => empty");
	//TODO
}

void BitcoinExchange::loadDataBase(const std::string& filename) {
	std::ifstream file(filename.c_str());
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

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");

	//empty check and skip line 1
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty input file");
	
	while (std::getline(file , line)) {
		try {
			//find " | " position
			size_t pos = line.find(" | ");
			if (pos == std::string::npos)
				throw runtime_error("Error: Bad input => " + line);

			//separate date
			std::string date = line.substr(0, pos);
			validateDate(date);

			//separate multiply and validate
			std::string multiStr = line.substr(pos + 3);
			validateValue(multiStr);
			float multi = std::strtof(multiStr.c_str(), NULL);
			if (multi < 0)
				throw std::runtime_error("Error: not a positive number.");
			if (multi > 1000)
				throw std::runtime_error("Error: too large a number.");

			//find og value, print multiplying
			double value = getExchange(date);
			std::cout << date << " => " << multiStr << " = " << (multi * value) << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}