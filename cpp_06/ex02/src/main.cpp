/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:23:37 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/16 02:01:56 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base*	generate(void) {
	int	n = std::rand() % 3;

	if (n == 0) {
		std::cout << "Generated: A" << std::endl;
		return (new A());
	}
	else if (n == 1) {
		std::cout << "Generated: B" << std::endl;
		return (new B());
	}
	else {
		std::cout << "Generated: C" << std::endl;
		return (new C());
	}
} 

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Identify (Pointer): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identify (Pointer): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identify (Pointer): C" << std::endl;
	else
		std::cout << "Identify (Pointer): Unknown" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Identify (Reference): A" << std::endl;
		return;
	}
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Identify (Reference): B" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Identify (Reference): C" << std::endl;
		return;
	}
	catch (std::exception& e) {}
}

int	main(void) {
	std::srand(std::time(NULL));

    std::cout << "========== TEST 1 ==========" << std::endl;
    Base* p1 = generate();
    identify(p1);
    identify(*p1);
    delete p1;

    std::cout << "\n========== TEST 2 ==========" << std::endl;
    Base* p2 = generate();
    identify(p2);
    identify(*p2);
    delete p2;

    std::cout << "\n========== TEST 3 ==========" << std::endl;
    Base* p3 = generate();
    identify(p3);
    identify(*p3);
    delete p3;

	return 0;
}