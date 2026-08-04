/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 01:23:34 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/04 01:20:48 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		//acho que esses podem ser possiveis template
		std::vector<std::pair<int, int> >makePairs();
		std::vector<int> pairWinners(const std::vector<std::pair<int, int> >& pairs);
		std::vector<int> pairLosers(const std::vector<std::pair<int, int> >& pairs);
		void mergeSort(std::vector<int>& winners);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void parseInput(int ac, char** av);

		void printBefore() const;
		void printAfter() const;
		
		//acho que esses podem ser possiveis template
		void sortVector();
		void sortDeque();

};

#endif