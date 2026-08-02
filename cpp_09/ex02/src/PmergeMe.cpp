/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:01:45 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/02 01:59:38 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cerrno>

#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vec(copy._vec), _deq(copy._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		_vec = rhs._vec;
		_deq = rhs._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int ac, char** av) {
	if (ac < 2)
		throw std::invalid_argument("Usage: ./PmergeMe <two or more numbers>");

	for (int i = 1; i < ac; i++) {
		char* end;
		errno = 0;
		long number = std::strtol(av[i], &end, 10);

		if (errno == ERANGE)
			throw std::invalid_argument("Error: Invalid input");

		if (*end != '\0')
			throw std::invalid_argument("Error: Invalid input");
		
		if (number < 0 || number > INT_MAX)
			throw std::invalid_argument("Error: Invalid input");

		for (size_t j = 0; j < _vec.size(); j++) {
			if (_vec[j] == static_cast<int>(number))
				throw std::invalid_argument("Error: Duplicate number");
		}
		_vec.push_back(static_cast<int>(number));
		_deq.push_back(static_cast<int>(number));
	}
}

void PmergeMe::printBefore() const {
	std::cout << "Before:";
	for(std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::printAfter() const {
	std::cout << "After:";
	for(std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	std::sort(_vec.begin(), _vec.end());
}