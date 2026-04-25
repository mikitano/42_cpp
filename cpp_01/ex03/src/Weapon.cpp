/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 01:17:09 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/24 01:17:09 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type){
	_type = type;
}
Weapon::~Weapon() {}

const std::string &Weapon::getType() const{
	return _type;
}

void Weapon::setType(const std::string &type){
	if (type.empty())
		return;
	_type = type;
}
