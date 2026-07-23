/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 01:12:26 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/22 21:37:00 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {
	_storage.reserve(n);
}

Span::Span(const Span& copy) : _maxSize(copy._maxSize), _storage(copy._storage) {}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		_maxSize = rhs._maxSize;
		_storage = rhs._storage;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
	if (_storage.size() >= _maxSize)
		throw SpanFullException();
	_storage.push_back(n);
}

int Span::longestSpan() const {
	if (_storage.size() < 2)
		throw NoSpanException();
	int minValue = *std::min_element(_storage.begin(), _storage.end());
	int maxValue = *std::max_element(_storage.begin(), _storage.end());
	return (maxValue - minValue);
}

int Span::shortestSpan() const {
	if (_storage.size() < 2)
		throw NoSpanException();
	std::vector<int> tmp(_storage);
	std::sort(tmp.begin(), tmp.end());

	int min_diff = -1;
	for (size_t i = 1; i < tmp.size(); i++) {
		int diff = tmp[i] - tmp[i - 1];
		if (min_diff == -1 || diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

const char* Span::SpanFullException::what() const throw() {
	return "Error: Span is already full";
}

const char* Span::NoSpanException::what() const throw() {
	return "Error: Not enough elements to find a Span";
}