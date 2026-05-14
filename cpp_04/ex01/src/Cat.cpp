/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 12:43:31 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 12:43:31 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << "Cat copy assingment operator called" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << this->_type << ": miaaaau" << std::endl;
}

const std::string& Cat::getIdea(int i) const {
	if (i >= 100)
		std::cerr << "This idea doesn't exist" << std::endl;
	return this->_ideas[i];
}

void Cat::setIdea(int i, const std::string& idea) {
	if (i >= 100)
		std::cerr << "Caution: Too much ideas!" << std::endl;
	this->_ideas[i] = idea;
}