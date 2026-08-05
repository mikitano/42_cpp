/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 01:23:34 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/05 03:43:01 by mkitano          ###   ########.fr       */
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

		std::vector<size_t> JacobsthalOrderFull(std::size_t size);

		//acho que esses podem ser possiveis template
		std::vector<std::pair<int, int> >makePairs();
		std::vector<int> pairWinners(const std::vector<std::pair<int, int> >& pairs);
		std::vector<int> pairLosers(const std::vector<std::pair<int, int> >& pairs);
		void mergeSortPairs(std::vector<std::pair<int,int> >& pairs);
		void insertLoser(std::vector<int>& mainChain, int value);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void parseInput(int ac, char** av);

		void printBefore() const;
		void printAfter() const;
		
		//acho que esses podem ser possiveis template
		std::vector<int> sortVector();
		//void sortDeque();

		void exec();

};

#endif