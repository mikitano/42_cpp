/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:59:28 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/24 21:59:28 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << _name << " died" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon)
	{
		std::cout << _name << " attacks wiht their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " has no weapon to attack with!" << std::endl;
	}
}