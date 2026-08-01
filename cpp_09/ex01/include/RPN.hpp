/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:50:35 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/31 21:36:01 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
	std::stack<int> _stack;
	void execOperation(char op);
	
public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& rhs);
	~RPN();

	void calculate(const std::string& args);
	void printResult() const;
};

#endif