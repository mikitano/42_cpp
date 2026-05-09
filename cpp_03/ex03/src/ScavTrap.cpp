/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:56:03 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/08 12:56:03 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap") {
	this->_hitPoint = 100;
	this->_enegyPoint = 50;
	this->_attackDam = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_enegyPoint = 50;
	this->_attackDam = 20;
	std::cout << "ScavTrap Argument constructor called: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called: " << this->_name << std::endl;
}
 
void ScavTrap::attack(const std::string& target) {
	if (target.empty())
	{
		std::cout << "ScavTrap Target does not exist" << std::endl;
		return;
	}
	if (this->_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name 
				  << " can't attack: " << this->_name
				  << " is dead" << std::endl;
		return;
	}
	if (this->_enegyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack: Insufficient energy points" << std::endl;
		return;
	}
	this->_enegyPoint--;
	std::cout << "ScavTrap " << this->_name 
			  << " attacks " << target
			  << ", causing " << this->_attackDam 
			  << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name
			  << " is in Gate keeper mode now!" << std::endl;
}