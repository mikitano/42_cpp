/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:48:47 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/01 17:34:04 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fracBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj) {
	if (this != &obj)
		this->_rawBits = obj._rawBits;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->getRawBits()) / (1 << _fracBits);
}

int Fixed::toInt(void) const {
	return (this->getRawBits() >> _fracBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& obj) {
	stream << obj.toFloat();
	return stream;
}