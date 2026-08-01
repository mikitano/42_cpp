/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:00:54 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/01 02:50:41 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs)
		_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string& args) {
	std::istringstream inputStream(args);
	std::string token;
	
	while (inputStream >> token) {
		if (token.length() != 1)
			throw std::invalid_argument("Error");
		if (std::isdigit(token[0])) {
			int number = token[0] - '0';
			_stack.push(number);
		}
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
			execOperation(token[0]);
		else
			throw std::invalid_argument("Error");
	}
}

void RPN::execOperation(char op) {
	if (_stack.size() < 2)
		throw std::invalid_argument("Error");

	int right = _stack.top();
	_stack.pop();

	int left = _stack.top();
	_stack.pop();

	int result = 0;
	if (op == '+')
		result = left + right;
	else if (op == '-')
		result = left - right;
	else if (op == '*')
		result = left * right;
	else if (op == '/') {
		if (right == 0)
			throw std::runtime_error("Error: division by zero is invalid");
		result = left / right;
	}
	_stack.push(result);
}

void RPN::printResult() const {
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		throw std::invalid_argument("Error");
}