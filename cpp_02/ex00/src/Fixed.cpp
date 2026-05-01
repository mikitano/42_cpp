/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:02:42 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/30 23:03:52 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}
