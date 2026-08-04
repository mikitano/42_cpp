/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:01:45 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/04 01:43:15 by mkitano          ###   ########.fr       */
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
	std::vector<std::pair<int, int> > pairs = makePairs();
	std::vector<int> winners = pairWinners(pairs);
	std::vector<int> losers = pairLosers(pairs);

	if (_vec.size() % 2 != 0)
		int leftover = _vec.back();

	mergeSort(winners);
}

std::vector<std::pair<int, int> > PmergeMe::makePairs() {
	std::vector<std::pair<int, int> > pairs;

	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it+= 2 ) {
		if (it + 1 == _vec.end())
			return pairs;
		else {
			int a = *it, b = *(it + 1);
			if (a > b)
				std::swap(a, b);
			pairs.push_back(std::make_pair(a, b));
		}
	}
	return pairs;
}

std::vector<int> PmergeMe::pairWinners(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<int> winners;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		winners.push_back(it->second);
	return winners;
} 

std::vector<int> PmergeMe::pairLosers(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<int> losers;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		losers.push_back(ti->first);
	return losers;
}

void PmergeMe::mergeSort(std::vector<int>& winners) {
	std::vector<int> result;
	std::vector<int> left;
	std::vector<int> right;

	if (winners.size() <= 1)
		return;

	size_t mid = winners.size() / 2;
	for (size_t i = 0; i < winners.size(); i++){
		if (i < mid)
			left.push_back(winners[i]);
		else
			right.push_back(winners[i]);
	}
	
	mergeSort(left);
	mergeSort(right);

	std::vector<int>::iterator itLeft = left.begin();
	std::vector<int>::iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end()) {
		if (*itLeft < *itRight) {
			result.push_back(*itLeft);
			++itLeft;
		}
		else {
			result.push_back(*itRight);
			++itRight;
		}
	}
	while (itLeft != left.end()) {
		result.push_back(*itLeft);
		++itLeft;
	}
	while (itRight != right.end()) {
		result.push_back(*itRight);
		++itRight;
	}
	winners = result;
}

void PmergeMe::insertLoser() {
	
}