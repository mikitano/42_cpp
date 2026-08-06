/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:19:35 by mkitano           #+#    #+#             */
/*   Updated: 2026/08/05 23:37:58 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <cstddef>

template <typename Container>
void PmergeMe::sort(Container& arr) {
	std::vector<std::pair<int, int> > pairs = makePairs(arr);

	mergeSortPairs(pairs);
	Container mainChain(pairWinners<Container>(pairs));	
	Container losers(pairLosers<Container>(pairs));

	std::vector<size_t> jacOrder = JacobsthalOrderFull(losers.size());
	for (size_t i = 0; i < jacOrder.size(); i++)
		insertLoser(mainChain, losers[jacOrder[i] - 1]);

	if (arr.size() % 2 != 0){
		int leftover = arr.back();
		insertLoser(mainChain, leftover);
	}
	arr = mainChain;
}

template <typename Container>
std::vector<std::pair<int, int> > PmergeMe::makePairs(const Container& arr) {
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < arr.size(); i += 2) {
		if (i + 1 == arr.size())
			break;
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return pairs;
}

template <typename Container>
Container PmergeMe::pairWinners(std::vector<std::pair<int, int> >& pairs) {
	Container winners;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		winners.push_back(it->second);
	return winners;
} 

template <typename Container>
Container PmergeMe::pairLosers(std::vector<std::pair<int, int> >& pairs) {
	Container losers;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		losers.push_back(it->first);
	return losers;
}

template <typename PairContainer>
void PmergeMe::mergeSortPairs(PairContainer& pairs) {
	PairContainer result;
	PairContainer left;
	PairContainer right;

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

	size_t i = 0;
	size_t j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].second < right[j].second) {
			result.push_back(left[i]);
			++i;
		}
		else {
			result.push_back(right[j]);
			++j;
		}
	}
	while (i < left.size()) {
		result.push_back(left[i]);
		++i;
	}
	while (j < right.size()) {
		result.push_back(right[j]);
		++j;
	}
	pairs = result;
}

template <typename Container>
void PmergeMe::insertLoser(Container& mainChain, int value) {
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