/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 01:23:34 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/01 20:31:35 by mkitano          ###   ########.fr       */
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


	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		void parseInput(int ac, char** av);

		//acho que esses podem ser template
		void sortVector();
		void sortDeque();

		void printBefore() const;
		void printAfter() const;
};

#endif