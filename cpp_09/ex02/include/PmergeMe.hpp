/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 01:23:34 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/05 23:53:48 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		void printBefore() const;
		void printAfter() const;
		std::vector<size_t> JacobsthalOrderFull(std::size_t size);
		
		template <typename Container>
		void sort(Container& arr);
		
		template <typename Container>
		std::vector<std::pair<int, int> >makePairs(const Container& arr);

		template <typename Container>
		Container pairWinners(std::vector<std::pair<int, int> >& pairs);

		template <typename Container>
		Container pairLosers(std::vector<std::pair<int, int> >& pairs);

		template <typename PairContainer>
		void mergeSortPairs(PairContainer& pairs);

		template <typename Container>
		void insertLoser(Container& mainChain, int value);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void parseInput(int ac, char** av);
		void exec();
};

#include "PmergeMe.tpp"

#endif