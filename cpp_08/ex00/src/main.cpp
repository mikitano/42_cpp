/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:08:35 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/22 01:09:27 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main(void) {
	std::cout << "\n============ TEST WITH std::vector ============" << std::endl;
	std::vector<int> ivec;
	ivec.push_back(0);
	ivec.push_back(10);
	ivec.push_back(20);
	ivec.push_back(30);
	ivec.push_back(40);

	std::cout << "Vector: ";
	for (std::vector<int>::iterator i_it = ivec.begin(); i_it != ivec.end(); ++i_it)
		std::cout << *i_it << " ";
	std::cout << std::endl;
	
	try {
		std::cout << "Searching for 20..." << std::endl;
		std::vector<int>::iterator it = easyfind(ivec, 20);
		std::cout << "Found number: " << *it << std::endl;

		std::cout << "Searching for 99..." << std::endl;
		easyfind(ivec, 99);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n============ TEST WITH const std::vector ============" << std::endl;
	const std::vector<int> c_vec(ivec);

	std::cout << "Const Vector: ";
	for (std::vector<int>::const_iterator ic_it = c_vec.begin(); ic_it != c_vec.end(); ++ic_it)
		std::cout << *ic_it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Searching for 30..." << std::endl;
		std::vector<int>::const_iterator c_it = easyfind(c_vec, 30);
		std::cout << "Found number: " << *c_it << std::endl;

		std::cout << "Searching for 99..." << std::endl;
		easyfind(c_vec, 99);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n============ TEST WITH std::list ============" << std::endl;
	std::list<int> lst;
	lst.push_back(2);
	lst.push_back(12);
	lst.push_back(22);
	lst.push_back(32);
	lst.push_back(42);

	std::cout << "List: ";
	for (std::list<int>::iterator l_it = lst.begin(); l_it != lst.end(); ++l_it)
		std::cout << *l_it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Searching for 42..." << std::endl;
		std::list<int>::iterator il_it = easyfind(lst, 42);
		std::cout << "Found number: " << *il_it << std::endl;
		
		std::cout << "Searching for 0..." << std::endl;
		easyfind(lst, 0);
	}
	catch(const std::exception& e) {
		std::cout << "Error " << e.what() << std::endl;
	}

	std::cout << "\n============ TEST WITH const std::list ============" << std::endl;
	const std::list<int> c_lst(lst);
	
	std::cout << "Const List: ";
	for (std::list<int>::const_iterator cl_it = c_lst.begin(); cl_it != c_lst.end(); ++cl_it)
		std::cout << *cl_it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Searching for 42..." << std::endl;
		std::list<int>::const_iterator icl_it = easyfind(c_lst, 42);
		std::cout << "Found number: " << *icl_it << std::endl;
		
		std::cout << "Searching for 0..." << std::endl;
		easyfind(c_lst, 0);
	}
	catch(const std::exception& e) {
		std::cout << "Error " << e.what() << std::endl;
	}

	std::cout << "\n============ TEST WITH std::deque ============" << std::endl;
	std::deque<int> deq;
	deq.push_back(3);
	deq.push_back(13);
	deq.push_back(23);
	deq.push_back(33);
	deq.push_back(43);
	
	std::cout << "Deque: ";
	for (std::deque<int>::iterator dq_it = deq.begin(); dq_it != deq.end(); ++dq_it)
		std::cout << *dq_it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Searching for 33..." << std::endl;
		std::deque<int>::iterator d_it = easyfind(deq, 33);
		std::cout << "Found number: " << *d_it << std::endl;

		std::cout << "Searching for 100..." << std::endl;
		easyfind(deq, 100);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n============ TEST WITH const std::deque ============" << std::endl;
	const std::deque<int> c_deq(deq);

	std::cout << "Const Deque: ";
	for (std::deque<int>::const_iterator c_dq_it = c_deq.begin(); c_dq_it != c_deq.end(); ++c_dq_it)
		std::cout << *c_dq_it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Searching for 33..." << std::endl;
		std::deque<int>::const_iterator cd_it = easyfind(c_deq, 33);
		std::cout << "Found number: " << *cd_it << std::endl;

		std::cout << "Searching for 100..." << std::endl;
		easyfind(c_deq, 100);
	}
	catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}