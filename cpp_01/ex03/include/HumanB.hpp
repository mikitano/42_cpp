/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:57:52 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/24 19:57:52 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
	
	public:
		HumanB(const std::string &name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif