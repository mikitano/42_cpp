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

Fixed::Fixed(): _rawBits(0) {}

Fixed::Fixed(const int value) {
	_rawBits = value << _fracBits;
}

Fixed::Fixed(const float value) {
	_rawBits = roundf(value * (1 << _fracBits));
}

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed &obj) {
	if (this != &obj)
		this->_rawBits = obj._rawBits;
	return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed& other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
	return (other > *this);
}

bool Fixed::operator>=(const Fixed& other) const {
	return !(*this < other);
}

bool Fixed::operator<=(const Fixed& other) const {
	return !(*this > other);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed& other) const {
	return !(*this == other);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	result (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	result (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawBits * other._rawBits) >> _fracBits);
	result (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawBits << _fracBits) / other._rawBits);
	result (result);
}

Fixed& Fixed::operator++(void) {
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_rawBits++;
	return temp;
}

Fixed& Fixed::operator--(void) {
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::mmax(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& obj) {
	stream << obj.toFloat();
	return stream;
}