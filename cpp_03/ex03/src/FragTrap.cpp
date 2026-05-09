/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:11:48 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/09 00:31:04 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap") {
	this->_hitPoint = 100;
	this->_enegyPoint = 100;
	this->_attackDam = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_enegyPoint = 100;
	this->_attackDam = 30;
	std::cout << "FragTrap Argument constructor called: " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called: " << this->_name << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name
			  << ": High five guys! ✋" << std::endl;
}
