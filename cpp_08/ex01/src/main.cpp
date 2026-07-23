/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:38:05 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/23 01:05:17 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\n============== PDF TEST ==============\n";
		Span sp = Span(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n============== FULL SPAN TEST ==============\n";
		Span sp(2);

		try {
			sp.addNumber(10);
			sp.addNumber(20);
			sp.addNumber(30);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n============== NO SPAN TEST ==============\n";
		Span sp(5);

		try {
			sp.addNumber(10);
			sp.shortestSpan();
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n============== ADD RANGE TEST ==============\n";
		std::vector<int> numbers;

		numbers.push_back(1);
		numbers.push_back(5);
		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);

		Span sp(10);
		std::cout << "Using addRange function..." << std::endl;
		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "addRange success!" << std::endl;

		std::cout << "\nShortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n============== 10000 NUMBERS TEST ==============\n";
		std::vector<int> v_base;
		for (int i = 0; i < 10000; i++)
		v_base.push_back(i);
		
		Span big(10000);
		std::cout << "Using addRange function..." << std::endl;
		big.addRange(v_base.begin(), v_base.end());
		std::cout << "Inserted 10000 numbers!" << std::endl;

		std::cout << "\nShortest Span is: " << big.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << big.longestSpan() << std::endl;
	}
	return 0;
}