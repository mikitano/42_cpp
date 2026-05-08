/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:26:27 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/03 16:26:36 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoint(10), _enegyPoint(10), _attackDam(10) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoint(10), _enegyPoint(10), _attackDam(10) {
	std::cout << "Argument constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) : _name(rhs._name), _hitPoint(rhs._hitPoint), _enegyPoint(rhs._enegyPoint), _attackDam(rhs._attackDam) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_enegyPoint = rhs._enegyPoint;
		this->_attackDam = rhs._attackDam;
	}
	std::cout << "Operator assigned called" << std::endl;
	return *this;
}
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (target.empty())
	{
		std::cout << "Target does not exist" << std::endl;
		return;
	}
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name 
				  << " can't attack: " << this->_name
				  << " is dead" << std::endl;
		return;
	}
	if (this->_enegyPoint <= 0)
	{
		std::cout << this->_name << " can't attack: Insufficient energy points" << std::endl;
		return;
	}
	this->_enegyPoint -= 1;
	std::cout << "ClapTrap " << this->_name 
			  << " attacks " << target
			  << ", causing " << this->_attackDam 
			  << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return;
	}
	this->_hitPoint -= amount;
	std::cout << "ClapTrap " << this->_name
			  << " takes " << amount
			  << " point(s) of damage!" << std::endl;
	if (this->_hitPoint < 0)
	{
		this->_hitPoint = 0;
		std::cout << "ClapTrap " << this->_name << " died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name 
				  << " can't recover. " << this->_name
				  << " is already dead!" << std::endl;
		return;
	}
	if (this->_enegyPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " can't recover. Insufficient energy points" << std::endl;
		return;
	}
	this->_hitPoint += amount;
	std::cout << "ClapTrap " << this->_name
			<< " recovers " << amount
			<< " point(s) of life!" << std::endl;
	this->_enegyPoint -= 1;
}

const std::string &ClapTrap::getName() const {
	return this->_name;
}

int ClapTrap::getHitPoint() const {
	return this->_hitPoint;
}

int ClapTrap::getEnergyPoint() const {
	return this->_enegyPoint;
}

int ClapTrap::getAttackDam() const {
	return this->_attackDam;
}

void ClapTrap::setAttackDam(int dmg) {
	if (dmg < 0)
	{
		std::cout << "Attack damage can't be negative" << std::endl;
		return;
	}
	this->_attackDam = dmg;
}