/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 22:26:44 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/25 00:56:42 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "\n============== PDF TEST ==============\n";
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << "\nAfter add new data: "<< std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\n============== COMPARISON TEST: std::list ==============\n";
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();
	
	std::cout << "Size: " << lst.size() << std::endl;

	std::cout << "\nAfter add new data: "<< std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator l_it = lst.begin();
	std::list<int>::iterator l_ite = lst.end();

	while (l_it != l_ite) {
		std::cout << *l_it << std::endl;
		++l_it;
	}

	std::cout << "\n============== CONST TEST ==============" << std::endl;

	const MutantStack<int> cmstack(mstack);

	for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}
