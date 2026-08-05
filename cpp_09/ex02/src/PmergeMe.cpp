/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:01:45 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/05 03:53:47 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cerrno>

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

std::vector<int> PmergeMe::sortVector() {
	std::vector<std::pair<int, int> > pairs = makePairs();

	mergeSortPairs(pairs);
	std::vector<int> mainChain = pairWinners(pairs);	
	std::vector<int> losers = pairLosers(pairs);

	std::vector<size_t> jacOrder = JacobsthalOrderFull(losers.size());
	for (size_t i = 0; i < jacOrder.size(); i++)
		insertLoser(mainChain, losers[jacOrder[i] - 1]);

	if (_vec.size() % 2 != 0){
		int leftover = _vec.back();
		insertLoser(mainChain, leftover);
	}
	return mainChain;
}

std::vector<std::pair<int, int> > PmergeMe::makePairs() {
	std::vector<std::pair<int, int> > pairs;

	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it+= 2 ) {
		if (it + 1 == _vec.end())
			break;
		int a = *it, b = *(it + 1);
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return pairs;
}

std::vector<int> PmergeMe::pairWinners(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<int> winners;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		winners.push_back(it->second);
	return winners;
} 

std::vector<int> PmergeMe::pairLosers(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<int> losers;
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		losers.push_back(it->first);
	return losers;
}

void PmergeMe::mergeSortPairs(std::vector<std::pair<int,int> >& pairs) {
	std::vector<std::pair<int,int> > result;
	std::vector<std::pair<int,int> > left;
	std::vector<std::pair<int,int> > right;

	if (pairs.size() <= 1)
		return;

	size_t mid = pairs.size() / 2;
	for (size_t i = 0; i < pairs.size(); i++){
		if (i < mid)
			left.push_back(pairs[i]);
		else
			right.push_back(pairs[i]);
	}
	
	mergeSortPairs(left);
	mergeSortPairs(right);

	std::vector<std::pair<int,int> >::iterator itLeft = left.begin();
	std::vector<std::pair<int,int> >::iterator itRight = right.begin();
	while (itLeft != left.end() && itRight != right.end()) {
		if (itLeft->second < itRight->second) {
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
	pairs = result;
}

void PmergeMe::insertLoser(std::vector<int>& mainChain, int value) {
	// binary search + insertion
	size_t left = 0;
	size_t right = mainChain.size();
	
	while (left < right) {
			size_t mid = (left + right) / 2;
		if (value > mainChain[mid])
			left = mid + 1;
		else
			right = mid;
	}
	mainChain.insert(mainChain.begin() + left, value);
}

//função normal sem template
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
	_vec = sortVector();
}