/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:04:12 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/23 15:30:33 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {}
		MutantStack(const MutantStack& copy) : std::stack<T>(rhs) {}
		MutantStack& operator=(const MutantStack& rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}
		~MutantStack() {}

		


};

#endif