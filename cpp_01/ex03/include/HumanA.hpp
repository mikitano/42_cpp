/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:43:28 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/24 19:43:28 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif