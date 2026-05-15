/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:46:54 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 10:46:54 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs)
	{
		AAnimal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	std::cout << "Dog copy assingment operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << this->_type << ": au au" << std::endl;
}

Brain* Dog::getBrain() const {
	return this->_brain;
}

const std::string& Dog::getIdea(int i) const {
	if (i >= 100)
		std::cerr << "Caution: This idea doesn't exist" << std::endl;
	return _brain->getIdea(i);
}

void Dog::setIdea(int i, const std::string& idea) {
	if (i >= 100)
		std::cerr << "Caution: Not reachable, too much ideas!" << std::endl;
	_brain->setIdea(i, idea);
}
