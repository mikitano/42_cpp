/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 00:35:58 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/09 11:36:03 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap_clap_name"), ScavTrap(), FragTrap() {
	this->_name = "Default DiamondTrap";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_enegyPoint = ScavTrap::_enegyPoint;
	this->_attackDam = FragTrap::_attackDam;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	this->_hitPoint = FragTrap::_hitPoint;
	this->_enegyPoint = ScavTrap::_enegyPoint;
	this->_attackDam = FragTrap::_attackDam;
	std::cout << "DiamondTrap  Argument constructor called: " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	this->_name = rhs._name;
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called: " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My DiamondTrap name is " << this->_name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}