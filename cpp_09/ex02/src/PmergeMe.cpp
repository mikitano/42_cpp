/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:01:45 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/05 23:52:36 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <ctime>

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

std::vector<size_t> PmergeMe::JacobsthalOrderFull(std::size_t size) {
	if (size == 0)
   		return std::vector<size_t>();
	std::vector<size_t> jac;

	jac.push_back(1);
	jac.push_back(3);

	while (jac.back() < size)
		jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);

	std::vector<size_t> order;
	order.push_back(jac[0]);
	for (size_t i = 1; i < jac.size(); i++) {
		size_t curr = jac[i];
		size_t prev = jac[i - 1];

		if (curr > size)
			curr = size;
		for (size_t j = curr; j > prev; j--)
			order.push_back(j);
	}
	return order;
}

void PmergeMe::exec() {
	printBefore();
	
	std::clock_t startVec = std::clock();
	sort(_vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	sort(_deq);
	std::clock_t endDeq = std::clock();

	printAfter();
	std::cout << std::endl;

	double deqTime = static_cast<double>(endDeq - startDeq) * 1000000 / CLOCKS_PER_SEC;
	double vecTime = static_cast<double>(endVec - startVec) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
}