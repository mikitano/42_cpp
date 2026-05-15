/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 23:55:33 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/13 23:55:33 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Default AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type) {
	std::cout << "AAnimal argument constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

const std::string& AAnimal::getType() const {
	return this->_type;
}
