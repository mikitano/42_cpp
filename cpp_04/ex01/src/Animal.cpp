/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:21:33 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 01:21:33 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Default Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
	std::cout << "Animal argument constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal:: makeSound() const {
	std::cout << "Animal: *static noises*" << std::endl;
}

const std::string& Animal::getType() const {
	return this->_type;
}