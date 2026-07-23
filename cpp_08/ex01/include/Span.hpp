/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 01:12:12 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/22 21:36:09 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span {
	private:
  		unsigned int _maxSize;
		std::vector<int> _storage;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int n);
		int longestSpan() const;
		int shortestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		template <typename Iter>
		void addRange(Iter begin, Iter end) {
			if (_storage.size() + std::distance(begin, end) > _maxSize)
				throw SpanFullException();
			_storage.insert(_storage.end(), begin, end);
		}
};

#endif