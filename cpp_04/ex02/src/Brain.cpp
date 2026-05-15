/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 22:20:38 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/12 22:20:38 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int i) const {
	if (i >= 100)
		std::cerr << "This idea doesn't exist" << std::endl;
	return this->_ideas[i];
}

void Brain::setIdea(int i, const std::string& idea) {
	if (i >= 100)
		std::cerr << "Caution: Too much ideas!" << std::endl;
	this->_ideas[i] = idea;
}
